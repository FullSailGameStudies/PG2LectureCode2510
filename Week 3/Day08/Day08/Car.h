#pragma once
#include <string>
#include <iostream>

class Car
{
public:
	Car() : mMake("Ford"), mModel("A"), mModelYear(1908), mFuelLevel(0), mMaxFuelLevel(15)
	{
		mNumberOfCarsMade++;
	}

	Car(int year, std::string make, std::string model)
		: mModelYear(year), mMake(make), mModel(model), mFuelLevel(0), mMaxFuelLevel(15)
	{
		mNumberOfCarsMade++;
	}
	std::string vehicleInformation();

	void refuel()
	{
		mFuelLevel = mMaxFuelLevel;
	}

	//getter (accessor)
	int modelYear() const
	{
		return mModelYear;
	}

	//setter (mutator)
	void modelYear(int newModelYear)
	{
		if (newModelYear > 1908 && newModelYear < 2100)
		{
			mModelYear = newModelYear;
		}
	}

	//static methods 
	//	there is NO 'this' parameter
	//	can ONLY access other static members
	//  can NOT access non-static members
	static void reporting()
	{
		//std::cout << "Model year: " << mModelYear << "\n"; //ERROR! cannot access non-static members
		std::cout << "Number of cars made: " << mNumberOfCarsMade << "\n";
	}

protected:
	int mModelYear;
	std::string mModel;
	std::string mMake;

	int mFuelLevel;
	int mMaxFuelLevel;

	//STATIC fields
	//	SHARED variables for ALL instances
	static int mNumberOfCarsMade; //shared by ALL cars
private:
};

