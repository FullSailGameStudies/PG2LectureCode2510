#include "Pistol.h"
#include <iostream>

void Pistol::showMe()
{
	//2 kinds of override:
	//  1) FULL override. do not call the base method.
	//  2) EXTENSION override. happens when we call the base method too.

	std::cout << "Pistol: rounds (" << rounds_ << ")\tCapacity (" << magCapacity_ << ")\n\t";
	//DO NOT DUPLICATE what the base does
	//call the base method instead
	Weapon::showMe();
}