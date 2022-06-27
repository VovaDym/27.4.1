#include <iostream>
#include <ctime>
#include "branch.h"



int main()
{
    std::srand(std::time(nullptr));

    createVillage();

    system("cls");

    std::cout << "Enter elven name to find: ";
    std::string name;
    std::cin >> name;
    findElf(name);
}