// Day08.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <memory>
#include "Inheritance.h"
#include "Polymorphism.h"
#include "Car.h"
#include "Weapon.h"
#include "Pistol.h"
#include "Knife.h"
#include <vector>

void Counter()
{
	//static variables "live" in a special section of memory
	//  used for statics
	//static variables remain in memory for as long as
	//  the app is running.
	//	therefore, be careful how much static memory that you use
	static int i = 0;
	std::cout << i << " ";
	i++;
}

Pistol* CreateGun()
{
	Pistol gun1(5, 5, 5, 5);//stack
	Pistol* pGun = new Pistol(5, 5, 5, 5);//heap
	new Pistol(5, 5, 5, 5);//memory leak
	return pGun;
}

void LoadGun(Pistol* gun)
{
	// -> is the same as * when it comes to dereferencing
	gun->showMe();
	(*gun).showMe();
}
int main()
{
	Car car1(2010, "Ford", "Expedition");
	Car car2(2023, "Hyundai", "Sonata");
	car1.vehicleInformation();
	car2.vehicleInformation();
	Car::reporting();


	for (int i = 0; i < 10; i++)
	{
		Counter();
	}
	int rng = 50, dmg = 100;
	//ONLY purpose of abstract base class is to be a starting place for other classes
	//Weapon wpn(rng, dmg); //cannot create an object of an abstract base class
	int rnds = 10, magCap = 20;

	//if you do NOT override the pure virtual function, your child class becomes abstract too
	Pistol pewpew(rng, dmg, rnds, magCap);//on the stack
	LoadGun(&pewpew);//we do not need to delete stack pointers
	pewpew.showMe();

	Knife stabby(3, 10, 5, true);

	Account acct1;
	acct1.mBalance = 1000;
	Account acct2;
	acct2.mBalance = 20000;
	Account acct3 = acct1 + acct2;
	/*
		╔═══════════════╗
		║  Inheritance  ║
		╚═══════════════╝

								╔═════════╗     ╔══════════╗
						 class  ║SomeClass║  :  ║OtherClass║
								╚═════════╝     ╚══════════╝
									 │                │
									 └──┐             └──┐
								   ┌────▼────┐      ┌────▼────┐
								   │ Derived │      │  Base   │
								   │  Class  │      │  Class  │
								   └─────────┘      └─────────┘

			Access modes:
				public inheritance:
				protected inheritance:
				private inheritance: (default if not specified)



				CONSTRUCTORS: the derived constructor must call a base constructor
				public SomeClass(.....) : baseClass(....)


			Lecture Code: add a FlyingCar class that derives from Car

	*/


	//pointers can be 32-bit or 64-bit depending on the app
	//if 32-bit app, then pointers are 4-bytes
	//if 64-bit app, then pointers are 8-bytes

	int a = 5;
	int* aPtr;
	aPtr = &a;//on the right-hand side (rhs), it is the address-of operator
	//a pointer to a variable on the STACK
	std::cout << "\n\n" << a << "\n" << aPtr << "\n";
	std::cout << *aPtr << "\n"; //* here is used to DEREFERENCE the pointer

	//heap memory (dynamic memory)
	//	devs allocate the memory manually
	//	" = new " means HEAP memory
	//	this memory MUST be cleaned up by the devs when no longer needed
	//		for EVERY "=new" you MUST HAVE a corresponding "delete"
	aPtr = new int(10);
	//to "clean up" means to deallocate to release the memory back to the system
	delete aPtr;

	{
		float* fPtr = new float(5.3f);//allocate HEAP memory 
	}
	//fPtr variable goes OUT-of scope. we've LEAKED the memory
	//memory leak means it has been allocated but cannot be deallocated
	//AND we cannot access the memory any more
	//std::cout << fPtr;

	Pistol* pGun = new Pistol(50, 100, 10, 15);//on the heap
	delete pGun;

	//how to assign a memory address to a pointer...
	//1) get the address-of an existing variable
	// OR...
	//2) allocate new memory

	//2 areas of memory that you can access:
	//  1) the stack (local variables, parameters)
	//		lifetime of these are controlled by scope
	//		when the variables go out of scope, they
	//		are removed from memory automatically
	//  2) the heap (dynamic memory)
	//		lifetime of these are controlled by the devs


	//a unique_ptr manages the memory for us
	//when the unique_ptr goes out of scope, it deletes the memory
	
	//unique_ptr is the ONLY variable that can point to that object

	//int* aPtr = new int(5);
	int* bPtr = aPtr;//copies the memory address, NOT the integer

	//delete aPtr;//frees the memory at that address
	//aPtr = nullptr;
	//if (aPtr != nullptr)
	//{

	//}

	std::unique_ptr<Pistol> uGun = 
		std::make_unique<Pistol>(5, 10, 10, 15);
	//std::unique_ptr<Pistol> uGun2 = uGun;//cannot have 2 unique_ptrs to the same object
	std::unique_ptr<Pistol> uGun2 = std::move(uGun);//ownership transfers to uGun2
	//Pistol* rawPtr = new Pistol(5, 5, 5, 5);
	//std::unique_ptr<Pistol> uGun3(rawPtr);
	//delete rawPtr;
	//uGun3->showMe();
	/*
		╔*************╗
		║  CHALLENGE  ║
		╚*************╝

			add a new class, Pistol, that derives from Weapon.
			Pistol should have fields with getters/setters for rounds and magCapacity.
			Add a constructor that calls the base constructor

	*/

	Weapon wpn2(5,5);
	Pistol pew(5, 5, 5, 5);
	wpn2 = pew;//??? just copies the weapon parts to wpn2

	std::vector<Weapon> weapons;//store pistols AND knives
	weapons.push_back(Pistol(5, 5, 5, 5));//copies the pistol
	weapons.push_back(Knife(3, 10, 12, true));//copies the knife

	Weapon* wpnPtr2;
	wpnPtr2 = &pewpew;//stores the MEMORY ADDRESS to pewpew

	{
		std::vector<std::unique_ptr<Weapon>> weapons2;
		//UPCASTING to a weapon*
		//UPCAST - ALWAYS safe
		weapons2.push_back(std::make_unique<Pistol>(5, 5, 5, 5));//copies the pistol POINTER
		weapons2.push_back(std::make_unique<Knife>(3, 10, 12, true));//copies the knife POINTER
		//weapons2.push_back(new int(10));

		std::cout << "\n\nWeapons\n";
		for (int i = 0; i < weapons2.size(); i++)
		{
			//Weapon* pWeapon = weapons2[i];
			//std::cout << pWeapon << "\n";
			//std::unique_ptr<Weapon>* pWeapon = &weapons2[i];

			weapons2[i]->showMe();//runtime polymorphism

			//IF I need to get to the type-specific info, I would need to DOWNCAST (NOT SAFE!!!)
		}
		std::cout << "\n\n";

		//for (size_t i = 0; i < weapons2.size(); i++)
		//{
		//	delete weapons2[i];
		//}
	}//cleans up the unique_ptrs automatically


	/*
		╔═════════════════════════════╗
		║  COMPILE-TIME Polymorphism  ║
		╚═════════════════════════════╝

		Method Overloading:
			- changing the number of parameters
			- changing the types of the parameters

		Lecture Code: Overload the refuel method in Car

	*/



	/*
		╔*************╗
		║  CHALLENGE  ║
		╚*************╝

			Add an OVERLOAD of the calcDamage method in the Weapon class.
			The overload should take an int parameter called modifier
			to increase the damage when calculating the damage.

	*/





	/*
		╔═════════════════════════════╗
		║  COMPILE-TIME Polymorphism  ║
		╚═════════════════════════════╝

		Operator Overloading

		Lecture Code: overload the + operator in Account

	*/



	/*
		╔*************╗
		║  CHALLENGE  ║
		╚*************╝

		overload the + in the Pistol class to add 2 pistols
			- it sets the magCapacity to the max of the 2 pistols
			- adds the # of rounds from both pistols. should not exceed the magCapacity.
	*/






	/*
		╔════════════════════════╗
		║  RUNTIME Polymorphism  ║
		╚════════════════════════╝

		╔═════════════╗
		║ OVERRIDING  ║ - changing the behavior of a base method
		╚═════════════╝

		1) add 'virtual' to the base method
		2) add a method to the derived class that has the same signature as the base.
			OPTIONALLY put 'override' on the derived method


		FULLY OVERRIDING:
			not calling the base method from the derived method

		EXTENDING:
			calling the base method from the derived method
			to call the base method...  baseClassName::method(...)



		Lecture Code: override the print method in the base/derived classes in the Polymorphism.h file

	*/
	derived der1("Gotham", 1);
	base base1 = der1; //calls the assignment operator of base therefore you lose all the derived parts. base1 is JUST a base object.
	der1.print();
	std::cout << "\n";
	base1.print();



	/*
		╔*************╗
		║  CHALLENGE  ║
		╚*************╝

			Override Weapon's showMe method in the Pistol class.
			In Pistol's version, call the base version then print out the rounds and magCapacity



	*/



}

