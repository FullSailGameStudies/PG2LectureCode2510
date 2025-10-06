#include "FullSailCourse.h"
#include <iostream>
#include <Console.h>

void FullSailCourse::EraseGrades(std::vector<float>& grades, float minGrade) const
{
	for (int i = 0; i < grades.size();)
	{
		if (grades[i] < minGrade) grades.erase(grades.begin() + i);
		else i++;
	}
}

void FullSailCourse::GetGrades(std::vector<float>& grades)
{
	for (int i = 0; i < 20; i++)
	{
		grades.push_back(rand() % 10001 / 100.0F);
	}
}

void FullSailCourse::PrintGrades(const std::vector<float>& grades) const
{
	Console::WriteLine("\n" + name, ConsoleColor::Magenta);
	for (auto& grade : grades)
	{
		std::cout << grade << "\n";
	}
}
