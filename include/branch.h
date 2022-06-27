#pragma once

#include <iostream>
#include <string>
#include <vector>

const int numberTree = 1;
class Branch** village = new Branch * [numberTree];


class Branch
{

public:

    void addChildren()
    {
        Branch* newChildren = new Branch;
        newChildren->parent = this;
        childrens.push_back(newChildren);
    }

    void settle()
    {
        int numberBigBranch = this->childrens.size();
        for (int i = 0; i < numberBigBranch; ++i)
        {
            std::cout << "The " << i + 1 << " of the " << numberBigBranch << " big branch " << std::endl;
            int numberMiddleBranch = this->childrens[i]->childrens.size();
            for (int j = 0; j < numberMiddleBranch; ++j)
            {
                std::cout << "The " << j + 1 << " of the " << numberMiddleBranch << " middle branch " << std::endl;
                Branch* child = this->childrens[i]->childrens[j];
                std::cout << "Enter the elf's name or enter <None> if the house remains empty: ";
                std::cin >> child->elfName;
            }
        }
    }

    Branch* getChildrenAt(const int index)
    {
        return (this->childrens[index]);
    }

    int getCountChildrens()
    {
        return (this->childrens.size());
    }

    std::string getElfName()
    {
        return elfName;
    }

protected:

    std::string elfName = "unknown";
    Branch* parent = nullptr;
    std::vector <Branch*> childrens;
};

void createVillage()
{
    for (int i = 0; i < numberTree; ++i)
    {
        system("cls");

        std::cout << "The " << i + 1 << " of the " << numberTree << " tree " << std::endl;
        village[i] = new Branch;
        int numberBigBranch = rand() % 3 + 3;
        for (int j = 0; j < numberBigBranch; ++j)
        {
            village[i]->addChildren();

            int numberMiddleBranch = rand() % 2 + 2;

            for (int k = 0; k < numberMiddleBranch; ++k)
            {
                village[i]->getChildrenAt(j)->addChildren();
            }
        }
        village[i]->settle();
    }
}

void findElf(const std::string& inName)
{
    for (int i = 0; i < numberTree; ++i)
    {
        Branch* tree = village[i];
        for (int j = 0; j < tree->getCountChildrens(); ++j)
        {
            int numberNeighbor = -1;
            Branch* child = tree->getChildrenAt(j);
            bool found = false;
            for (int k = 0; k < child->getCountChildrens(); ++k)
            {
                std::string name = child->getChildrenAt(k)->getElfName();
                if (!found && name == inName)
                {
                    found = true;
                    k = 0;
                }
                if (found && name != "None")
                {
                    ++numberNeighbor;
                }       
            }
            if (found)
            {
                std::cout << i + 1 << " tree " << j + 1 << " big branch " << numberNeighbor << " neighbors" << std::endl;
            }    
        }
    }
}