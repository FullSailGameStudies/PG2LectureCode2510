#pragma once
#include <string>
//ONLY #include header files that THIS header needs
class Student
{
	//what can this class do? (methods or member functions)
	//  DropClass, Enroll, UpdateGrade
	// 
	//what describes the class? (fields or data members)
	//	name, Id, GPA, degree

	//who can see what in your class? Access Modifiers
	//in general, hide things (protect it from other code)
	//access modifiers:
	//  public: ALL code can see it
	//  protected: this class and all descendent classes can see it.
	//  private: ONLY this class can see it (*)
	//
	//  can have any number of these
	//	can be in any order

public:
	//constructors (ctors) - their only purpose is to initialize the object
	//	IF you do not create a ctor, the compiler will give you a default ctor
	//  IF you create a ctor, the compiler's ctor is no longer available
	//  ctors are special methods
	//  RULES:
	//	  1) must be named EXACTLY the same as the class
	//    2) cannot have a return type (not even void)

	//a default ctor is a ctor w/out parameters
	//   the compiler's default ctor doesn't do anything other that create the object
	Student(const std::string& name, const std::string& degree, int id);



	//getters and setters are USUALLY defined in the header
	//  both the declaration and definition are in the header
	// 
	//getters (accessors to the fields)
	//	they are most of the time const
	//  return type usually matches the field type
	//  usually don't have parameters
	std::string GetDegree() const //declaration + definition
	{
		return degree_;
	}
	//alternative naming for getters...don't prefix with 'Get'
	float GPA() const
	{
		return gpa_;
	}

	//setters (mutators)
	//  they cannot be const
	//  return type is usually void
	//  usually has 1 parameter that matches the type of the field
	void SetDegree(const std::string& newDegree)
	{
		//here is where we protect the data
		if (not newDegree.empty() && newDegree.size() < 24)
		{
			degree_ = newDegree;
		}
	}
	void GPA(float gpa)
	{
		if (gpa >= 0 && gpa <= 4.0f)
			gpa_ = gpa;
	}

protected:
	//FIELDS (data members)
	//  generally they should be PRIVATE for protection
	//  follow a camelCasingNamingConvention
	//		PLUS something to make it standout as part of the class
	//		EX: m_iId, m_id, mId, _id, id_
	
private:
	float gpa_;
	int id_;
	std::string degree_;
	std::string name_;
};

