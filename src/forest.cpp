#include <iostream>
#include <ctime>
#include "branch.h"

int main()
{
    std::srand(std::time(nullptr));
    
    int numberTree = 5;
    Branch** village = new Branch * [numberTree];

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

    system("cls");

    std::cout << "Enter elven name to find: ";
    std::string searchName;
    std::cin >> searchName;
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
                if (!found && name == searchName)
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