#pragma once
#include <string>
#include <vector>
class FullSailCourse
{
public:
	void EraseGrades(std::vector<float>& grades, float minGrade = 59.5) const;

	void GetGrades(std::vector<float>& grades);

	//TOPIC: pass by ref + const
	//add a PrintGrades method to print the vector
	void PrintGrades(const std::vector<float>& grades) const;

	//getters/setters
	//const methods: 
	//   prevents the method from changing the class variables
	std::string GetName() const
	{
		return name;
	}
	void SetName(const std::string& newName)
	{
		if (newName.size() > 0)
		{
			name = newName;
		}
	}

private:
	std::string name;
};

