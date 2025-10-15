#pragma once
#include "Weapon.h"
class Pistol : public Weapon
{
public:

	//ctors in the derived MUST call a base ctor
	//we call the base ctor in the member initialization list
	//syntax: baseClassName(arguments...)

	//the order of the ctor calls:
	//   base first, then derived
	//		why? b/c the derived code MIGHT be dependent on the base
	Pistol(int range, int damage, int rounds, int magCapacity)
		: Weapon(range,damage), rounds_(rounds), magCapacity_(magCapacity)
	{
	}

	//override the base method
	//	the signature of this method MUST MATCH EXACTLY as the base
	//  the 'override' keyword is optional but GOOD programming practice
	void showMe() override;

	int Rounds() const { return rounds_; }
	int MagCapacity() const { return magCapacity_; }

	void Rounds(int rounds) {
		if (rounds >= 0 && rounds <= magCapacity_)
			rounds_ = rounds;
	}
	void MagCapacity(int newCapacity) {
		if (newCapacity > 0 && newCapacity <= 50)
			magCapacity_ = newCapacity;
	}
private:
	int rounds_, magCapacity_;


};

