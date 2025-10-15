#include "Student.h"

//preferred to use the member initialization list to set the fields
Student::Student(const std::string& name, const std::string& degree, int id) :
	//member initialization list (this happens before the {  } )
	name_(name),
	degree_(degree),
	id_(id),
	gpa_(0)
{
	////initialize the fields w/ the parameters
	////id = id_;//backwards
	//name_ = name;
	//degree_ = degree;
	//id_ = id;
	//gpa_ = 0;
}
