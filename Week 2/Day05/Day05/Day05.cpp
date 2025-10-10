// Day05.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include "Console.h"
#include "Input.h"

enum class Weapon
{
    Sword, Axe, Spear, Mace
};

//avoid magic numbers
const int NOT_FOUND = -1;

int LinearSearch(const std::vector<int>& numbers, int searchNumber)
{
    for (int i = 0; i < numbers.size(); i++)
    {
        if (searchNumber == numbers[i])
        {
            return i;
        }
    }
    return NOT_FOUND;
}


int main()
{
    /*
        ╔═════════╗
        ║Searching║
        ╚═════════╝

        There are 2 ways to search a vector: linear search or binary search

        CHALLENGE:

            write a method to linear search the numbers list.
                The method should take 2 parameters: vector of ints to search, int to search for.
                The method should return -1 if NOT found or the index if found.

            The algorithm:
                1) start at the beginning of the vector
                2) compare each item in the vector to the search item
                3) if found, return the index
                4) if reach the end of the vector, return -1 which means not found

    */
    std::vector<int> numbers = { 0,1,2,3,4,5,6 };
    int searchNumber = 6;
    int foundIndex = LinearSearch(numbers, searchNumber);
    if (foundIndex == NOT_FOUND)
        std::cout << searchNumber << " is not found.\n";
    else
        std::cout << searchNumber << " was found at index " << foundIndex << "\n";



    /*
        ╔═══════════════════╗
        ║ map<TKey, TValue> ║
        ╚═══════════════════╝

        [  Creating a map  ]

        map<TKey, TValue>  - an associative collection.
            TKey is a placeholder for the type of the keys.
            TValue is a placeholder for the type of the values.

        When you want to create a map variable,
            1) replace TKey with whatever type of data you want to use for the keys
            2) replace TValue with the type you want to use for the values


        [  Adding items to a map  ]

        There are 2 ways to add items to a map:
        1) using the insert method.
        2) using [key] = value
    */
    std::map<Weapon, int> dorasBackpack;//will store the counts of each kind of weapon

    //returns an iterator and a bool. 
    //if the key is already in the map, it will NOT insert it -- the bool will be false.
    auto inserted = dorasBackpack.insert(std::make_pair(Weapon::Sword, 5));
    if (inserted.second == false) //meaning not inserted
        std::cout << "The key was already in the map. It was not inserted.\n";
    else
        std::cout << "The key was inserted in the map.\n";

    dorasBackpack[Weapon::Axe] = 3;
    dorasBackpack[Weapon::Axe] = 7;//simply overwrites the value if the key is already in the map

    //keys MUST be unique
    //std::map<keyType,valueType> 
    std::map<std::string, float> menu;
    //2 ways to add data to a map...
    //1) (easy way) map[key] = value;
    menu["omelette"] = 4.99f;
    menu["texas toast"] = 2.99f;
    menu["orange juice"] = 3.99f;
    menu["orange juice"] = 4.99f;//overwrites

    //2) (harder way) map.insert(key-value pair);
    std::pair<std::string, float> menuPair =
        std::make_pair("bacon", 1.99f);
    menu.insert(menuPair);
    menuPair.second = 2.99f;
    //first: iterator to the key-value pair object in the map
    //second: bool saying whether it was inserted or not
    std::pair<std::map<std::string,float>::iterator,bool> menuInserted = menu.insert(menuPair);//does NOT overwrite
    if (menuInserted.second)
    {
        std::cout << menuPair.first << " is already on the menu.\n";
    }

    std::cout << "\n\nPG2 Cafe\n";
    //looping
    for (auto iter = menu.begin(); iter != menu.end(); iter++)
    {
        std::cout << iter->first;
        Console::SetCursorLeft(15);
        std::cout << iter->second << "\n";
    }
    std::cout << "\n\n";

    std::cout << "\n\nPG2 Cafe\n";
    for (auto& menuItem : menu)
    {
        std::cout << menuItem.first;
        Console::SetCursorLeft(15);
        std::cout << menuItem.second << "\n";
    }
    std::cout << "\n\n";

    std::cout << "\n\nPG2 Cafe\n";
    for (auto& [itemName,itemPrice] : menu)
    {
        std::cout << itemName;
        Console::SetCursorLeft(15);
        std::cout << itemPrice << "\n";
    }
    std::cout << "\n\n";
    /*
        CHALLENGE:

            Create a map that stores names (string) and grades. 
            Call the variable grades.
            Add students and grades to your map.


            Loop over your grades map and print each student name and grade.

    */






    /*
        ╔═══════════════════╗
        ║ map<TKey, TValue> ║
        ╚═══════════════════╝

        [  Looping over a map  ]

        You should use a ranged-based for loop when needing to loop over the entire map.

    */
    for (auto const& [key, val] : dorasBackpack) //requires C++ 20
    {
        switch (key)
        {
        case Weapon::Sword:
            std::cout << "Sword: ";
            break;
        case Weapon::Axe:
            std::cout << "Axe: ";
            break;
        case Weapon::Spear:
            std::cout << "Spear: ";
            break;
        case Weapon::Mace:
            std::cout << "Mace: ";
            break;
        default:
            break;
        }
        std::cout << val << "\n";
    }





    /*
        ╔═══════════════════╗
        ║ map<TKey, TValue> ║
        ╚═══════════════════╝

        [  Checking for a key in a map  ]

        use the find method to check if the key is in the map

        will return map.end() if NOT found.

    */
    std::map<Weapon, int>::iterator foundIter = dorasBackpack.find(Weapon::Mace);
    if (foundIter == dorasBackpack.end()) //meaning it was NOT found
    {
        std::cout << "Dora did not find any maces.\n";
    }
    else
    {
        //can safely grab the value for the key
        std::cout << "Dora found " << foundIter->second << " Maces\n";
    }



    /*
        CHALLENGE:

            look for a specific student in the map.
            If the student is found, print out the student's grade
            else print out a message that the student was not found

    */




    /*
        ╔═══════════════════╗
        ║ map<TKey, TValue> ║
        ╚═══════════════════╝

        [  Updating a value for a key in a map  ]

        To update an exisiting value in the map, use the [ ]


    */
    dorasBackpack[Weapon::Axe] = 1;//updates the count for the axe



    /*
        CHALLENGE:

            Pick any student and curve the grade (add 5) that is stored in the grades map

    */
}