#include "Car.h"

std::string Car::vehicleInformation()
{
	return std::to_string(mModelYear) + " " + mMake + " " + mModel;
}

void Car::SerializeCSV(std::ostream& outFile, char delimiter) const
{
	outFile << mModelYear << delimiter << mMake << delimiter << mModel;
}

void Car::DeserializeCSV(const std::string& csvData, char delimiter)
{
	std::string data;
	std::stringstream csvStream(csvData);
	std::getline(csvStream, data, delimiter);
	mModelYear = std::stoi(data);
	std::getline(csvStream, mMake, delimiter);
	std::getline(csvStream, mModel, delimiter);
}
