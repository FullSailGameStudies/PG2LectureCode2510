// Day10.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include "Console.h"
#include "Input.h"



/*
    ╔══════════╗
    ║ File I/O ║
    ╚══════════╝

    3 things are required for File I/O:
    1) Open the file
    2) read/write to the file
    3) close the file



*/
int main()
{
    std::cout << "Hello PG2!\n";

    /*

        ╔════════════════╗
        ║ write csv data ║
        ╚════════════════╝

        [  Open the file  ]
        [  Write to the file  ]
        [  Close the file  ]

        you need the path to the file
            use full path ( drive + directories + filename )
            or use relative path ( directories + filename )
            or current directory ( filename )

        Make sure to separate the data in the file with a delimiter.
        The delimiter is important because it is used
            to separate the data when reading the file back in.


        Lecture code: set a filePath variable, open an output file, write some csv data to it
    */

    std::string fileName = "2510.csv";
    std::string path = "C:/temp/2510/";
    std::string fullPath = path + fileName;

    //ofstream: output (write to the file)
    //ifstream: input  (read from the file)
    //fstream: input + output

    //1) OPEN the file
    //   will create the file IF the path exists
    //   it will NOT create the path
    //   check if the file is open before using it
    std::ofstream outFile(fullPath);
    char delimiter = '*';
    if (outFile.is_open())
    {
        //2) Write to the file
        //   << insertion operator
        outFile << "Batman rules!" << delimiter << "Steev4";
        outFile << delimiter << 13.2;
        outFile << delimiter << true << delimiter << "Aquaman smells.";
    }
    else
        std::cout << fullPath << " could not be opened.\n";

    //3) CLOSE the file
    //   close the file AS SOON AS POSSIBLE
    outFile.close();


    //1) OPEN the file
    std::ifstream inFile(fullPath);
    if (inFile.is_open())
    {
        //2) READ the file
        std::string line;
        //read the file until it reaches a newline OR the end of the file
        std::getline(inFile, line);

        //parse the string to get the data
        std::string data;
        std::stringstream lineStream(line);
        //read the stream until it reaches a delimiter OR the end of the stream
        std::getline(lineStream, data, delimiter);
        std::cout << data << "\n";

        //try-catch block
        //1) put the code that MIGHT throw an exception inside a try block
        //2) add 1 or more catch blocks to handle exceptions

        try
        {
            std::getline(lineStream, data, delimiter);
            int iData = std::stoi(data);
            std::cout << iData << "\n";

            std::getline(lineStream, data, delimiter);
            double dData = std::stod(data);
            std::cout << dData << "\n";

            std::getline(lineStream, data, delimiter);
            bool bData = std::stoi(data);
            std::cout << bData << "\n";

        }
        //1 or more catch blocks to handle different exceptions
        catch (const std::exception& ex)
        {
            std::cout << "Error parsing the file:\n";
            std::cout << ex.what() << "\n";
        }
        std::getline(lineStream, data, delimiter);
        std::cout << data << "\n";
    }
    else
        std::cout << fullPath << " could not be opened.\n";

    //3) CLOSE the file
    inFile.close();

    /*

        ╔═══════════════╗
        ║ read csv data ║
        ╚═══════════════╝

        [  Open the file  ]
        [  read the file  ]
        [  Close the file  ]

        Lecture code: using the filePath variable, open an input file, use getline to read a line, print the line
    */


    /*

        ╔═════════════════════╗
        ║ parsing csv strings ║
        ╚═════════════════════╝
        
        use getline on a string stream instead of a file stream

        Lecture code: 
            using the line read in above, use a stringstream to split the line using getline.
            store the separate items in a vector
            parse each item in the vector to an appropriate variable.
        

    */





    /*

        CHALLENGE:

        Parse the multi csv string (below) to get the data.
        NOTE: the data is a collection of object data.
        There are multiple delimiters.
        Separate on the first delimiter (collectionSeparator) to get the csv data for each object.
        Then, separate the object csv data on objectSeparator to get the details of the object.

        EX: hero#hero#hero   each hero is separated by a #
            name^secret^age  the details of each hero is separated by a ^

    */
    std::string multi = "Batman^Bruce Wayne^35#Superman^Clark Kent^25#Wonder Woman^Diana Prince^25#Aquaman^Arthur Curry^12";
    char collectionSeparator = '#';
    char objectSeparator = '^';
}