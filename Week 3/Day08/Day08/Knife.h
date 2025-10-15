#pragma once
#include "Weapon.h"
class Knife : public Weapon
{
public:
	Knife(int range, int damage, int length, bool serrated)
		: Weapon(range, damage), length_(length), serrated_(serrated)
	{
	}

	int Length() const { return length_; }
	bool Serrated() const { return serrated_; }

	void Length(int length) {
		if (length >= 0 && length <= 12)
			length_ = length;
	}
	void Serrated(bool serrated) {
		serrated_ = serrated;
	}
private:
	int length_;
	bool serrated_;

};

