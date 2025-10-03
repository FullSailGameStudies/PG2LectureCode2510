﻿#include <iostream>
#include <string>
#include <vector>
#include "FullSailCourse.h"
#include <Console.h>


bool postFix(std::string& hero)
{
    srand((unsigned int)time(NULL));
    int postFixNumber = rand() % 1000;
    hero = hero + "-" + std::to_string(postFixNumber);
    return postFixNumber % 2 == 0;
}

float average(const std::vector<int>& scores)
{
    //scores.push_back(5); //not allowed because it is marked as const
    float sum = 0;
    for (auto score : scores)
        sum += score;

    return sum / scores.size();
}

void print(const std::vector<int>& scores)
{
    std::cout << "----SCORES----\n";
    int index = 1;
    for (int score : scores)
        std::cout << index++ << ". " << score << "\n";
}

void printInfo(const std::vector<int>& scores)
{
    std::cout << "size: " << scores.size() << "\tcapacity: " << scores.capacity() << "\n";
}

//a REFERENCE is an ALIAS to another variable
//PROs to using references...
//1) allows access to a variable in a different scope
//2) PREVENTS a copy. improves the performance.
//
//WHEN to use pass by reference...
//1) when the parameter is a class
//2) when the method needs to modify a variable in a different scope
//3) when you want to improve performance
void Adder(int& number)//number is a REFERENCE variable
{
    //number now REFERS to a variable in a different scope
    number += rand();
}

//get the benefit of NOT making a copy
//prevents the method from changing the variable
void PrintTheBest(const std::string& heroName)
{
    //heroName = "Bruce";
    std::cout << heroName << "\n";
}
int main()
{
    std::string name = "Aquaman";
    PrintTheBest(name);
    name = "Batman";
    PrintTheBest(name);
    int n = 5;
    int& nRef = n;//nRef is the SAME variable as n
    Adder(n);
    std::cout << n << "\n";
    /*
        ╔══════════════════════════════╗
        ║Parameters: Pass by Reference.║
        ╚══════════════════════════════╝
        Sends the variable itself to the method. The method parameter gives the variable a NEW name (i.e. an alias)

        NOTE: if the method assigns a new value to the parameter, the variable used when calling the method will change too.
            This is because the parameter is actually just a new name for the other variable.
    */
    std::string spider = "Spiderman";
    bool isEven = postFix(spider);
    std::string evenResult = (isEven) ? "TRUE" : "FALSE";
    std::cout << spider << "\n" << "Is Even postfix? " << evenResult << "\n";


    /*
        CHALLENGE 1:

            Write a method to fill the vector of floats with grades.
            1) pass it in by reference
            2) add 10 grades to the vector

    */
    std::vector<float> grades;
    FullSailCourse pg2;
    pg2.GetGrades(grades);
    pg2.SetName("PG2 2510");
    pg2.PrintGrades(grades);
    //Console::WriteLine("\nPG2 2510", ConsoleColor::Magenta);
    //for (int index = 0; index < grades.size(); index++)
    //{
    //    std::cout << grades[index] << "\n";
    //}
    //range-based (foreach) loop
    //for (auto& grade : grades)
    //{
    //    std::cout << grade << "\n";
    //}

    //an iterator is an OBJECT that points to an item inside a collection
    //vector.begin() - gives an iterator to the first item in the vector
    //vector.end() - gives an iterator to the item AFTER the last item
    //for (auto iter = grades.begin(); iter != grades.end(); iter++)
    //{
    //    std::cout << *iter << "\n";
    //}

    /*
        ╔══════════════════╗
        ║ const parameters ║
        ╚══════════════════╝
        const is short for constant. It prevents the variable from being changed in the method.

        This is the way you pass by reference and prevent the method from changing the variable.
    */
    std::vector<int> highScores;
    for (int i = 0; i < 10; ++i)
    {
        highScores.push_back(rand() % 5000);
        printInfo(highScores);//size: ?  capacity: ?
    }
    float avg = average(highScores);



    /*
        CHALLENGE 2:

            Write a method to calculate the stats on a vector of grades
            1) create a method to calculate the min, max. 
                pass the grades vector as a const reference. Use ref parameters for min and max.
            2) call the method in main and print out the min, max.

    */





    /*
        ╔═══════════╗
        ║ vector<T> ║
        ╚═══════════╝

        [  Removing from a vector  ]

        clear() - removes all elements from the vector
        erase(position) - removes the element at the position
        erase(starting position, ending position) - removes a range of elements. the end position is not erased.

    */
    print(highScores);

    //erase all scores < 2500

    print(highScores);



    /*
        CHALLENGE 3:

            Using the vector of grades you created.
            Remove all the failing grades (grades < 59.5).
            Print the grades.
    */





    /*
        ╔═══════════╗
        ║ vector<T> ║
        ╚═══════════╝

        
        size(): # of items that have been ADDED
        capacity(): length of the internal array
        reserve(n): presizes the internal array
    */
    std::vector<int> scores;
    scores.reserve(10); //makes the internal array to hold 10 items.

    printInfo(scores);
}

