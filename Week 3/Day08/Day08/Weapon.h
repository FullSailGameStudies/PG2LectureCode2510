#pragma once
class Weapon
{
private:
	int mRange;
	int mDamage;

public:
	Weapon(int range, int damage);

	//OVERRIDING a base method:
	//1) mark the base method with the keyword 'virtual'
	//	 virtual tells the compiler that this method MIGHT 
	//   be overridden in a derived class
	//2) go to the derived class and add a new method to override the behavior
	virtual void showMe();
	int calcDamage();

	int range() const
	{
		return mRange;
	}
	int damage() const
	{
		return mDamage;
	}
};

