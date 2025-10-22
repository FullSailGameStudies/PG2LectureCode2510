// Day11.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Car.h"
#include <vector>
#include <fstream>
#include "Console.h"
#include "Input.h"

int main()
{
    std::cout << "Gone in 60 Seconds!\n";//https://carbuzz.com/features/beyond-eleanor-gone-in-60-seconds-car-names#:~:text=The%20Complete%20List%20Of%20Gone%20In%2060%20Seconds,8%201961%20Porsche%20Speedster%20-%20%22Natalie%22%20More%20items

    Car myRide(1967, "Ford", "Shelby Mustang GT500");
    //1) open the file
    std::string fileName = "garage2510.csv";
    char delimiter = '$';
    std::ofstream out(fileName);
    if (out.is_open())
    {
        //2) write to the file
        myRide.SerializeCSV(out, delimiter);
    }
    else
        std::cout << fileName << " could not be opened.\n";

    //3) close the file
    out.close();


    std::vector<Car> garage;
    garage.push_back(Car(1967, "Ford", "Shelby Mustang GT500"));
    garage.push_back(Car(1956, "Ford", "T Bird"));
    garage.push_back(Car(1961, "Porsche", "Speedster"));
    garage.push_back(Car(1965, "Pontiac", "GTO"));
    garage.push_back(Car(1969, "Plymouth", "Hemi Cuda"));

    //coding practice: serialize the garage to a file
    std::ofstream garageFile("jaysGarage.csv");
    if (garageFile.is_open())
    {
        bool notFirst = false;
        for (auto& car : garage)
        {
            if(notFirst) garageFile << "\n";
            notFirst = true;

            car.SerializeCSV(garageFile, delimiter);
        }
    }
    else
        std::cout << "Jay's Garage could not be opened.\n";
    garageFile.close();


    std::string myData = "1965,Pontiac,GTO";
    Car todaysRide(myData, ',');
    std::cout << todaysRide.vehicleInformation() << "\n";

    //coding practice:
    //  load jays garage from the file into a new vector of Car objects
    //  then, loop over the new vector and print the vehicle info
    std::ifstream jaysFile("jaysGarage.csv");
    std::vector<Car> loadedCars;
    if (jaysFile.is_open())
    {
        while (not jaysFile.eof())
        {
            //read a line from the file
            //create a Car using the line
            std::string line;
            std::getline(jaysFile, line);
            Car nextCar(line, delimiter);
            loadedCars.push_back(nextCar);
        }
    }
    else
        std::cout << "jaysGarage.csv could not be opened.\n";
    jaysFile.close();

    std::cout << "\n\nJay's Garage\n";
    for (auto& car : loadedCars)
    {
        car.SerializeCSV(std::cout, ' ');
        std::cout << "\n";
        //std::cout << car.vehicleInformation() << "\n";
    }

    /*
        ╔═════════════╗
        ║ Serializing ║
        ╚═════════════╝

        Saving the state (data) of objects

        Lecture Code: serialize the vector of Cars to a file.
            Data Format:
                separates cars. EX: car1|car2|car3
                separates data inside a car. EX: 1967;Ford;Shelby Mustang GT500

    */



    /*
        ╔═══════════════╗
        ║ Deserializing ║
        ╚═══════════════╝

        Recreating the objects from the saved state (data) of objects

        Lecture Code:
            Open the file
            Read in each line
            split each line to get each car
            split each car to get the car details

    */
}