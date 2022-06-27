#pragma once

#include <iostream>
#include <string>
#include <vector>





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