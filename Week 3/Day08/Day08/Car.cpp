#include "Car.h"



//initialize explicitly using the class name scoping
int Car::mNumberOfCarsMade = 0;


//non-static method
//	can access non-static AND static members
// 
//there is a HIDDEN parameter called 'this'
//'this' is a POINTER to the object the method was called on
std::string Car::vehicleInformation()
{
	//ONLY time you should use 'this->' is to remove ambiguity in variable names
	int mModelYear = 99;
	return std::to_string(this->mModelYear) + " " + mMake + " " + mModel;
}
