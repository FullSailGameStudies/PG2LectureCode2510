// Day04.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
#include <string_view>
#include "Console.h"
#include "Input.h"


std::string toUpper(const std::string& original)
{
	std::string copy = original;
	for (auto& c : copy)
		c = toupper(c);
	return copy;
}

void recursiveLoop(int N)
{
	//EVERY recursive method REQUIRES an exit condition
	//the exit condition, when hit, prevents the method from calling itself
	if (N >= 10)
	{
		std::cout << "EXIT!\n";
		return;//loop while false!
	}

	std::cout << N << "\n";
	recursiveLoop(N + 1);//the recursive condition
	Console::WriteLine(N, ConsoleColor::Green);

}//last line of code
//where do methods return to? to whoever called it!

unsigned long factorial(unsigned int N)
{
	if (N <= 1) return 1; //here's the exit condition!
	return N * factorial(N - 1);
}
/*
for(int i = 0;i < 100;++i)
{
	std::cout << (char)78 << (char)65 << ' ';
}
			*/
void Bats(int i = 0)
{
	if (i < 100)
	{
		std::cout << (char)78 << (char)65 << ' ';//the going-out loop
		//i++ -- post-increment
		//++i -- pre-increment (slightly better performance)
		Bats(++i);
	}
}

void ReverseWord(const std::string& word, int index = 0)
{
	if (index == word.size()) return;
	ReverseWord(word, index + 1);
	std::cout << word[index];//the coming back loop
}

/*
	╔═══════╗
	║Sorting║
	╚═══════╝

	Sorting is used to order the items in a vector/array is a specific way

	CHALLENGE 2:

		Convert this BubbleSort pseudo-code into a method

		O(n^2)
		basic algorithm requires nested loops

		procedure bubbleSort(A : list of sortable items)
		  n := length(A)
		  repeat
			  swapped := false
			  for i := 1 to n - 1 inclusive do
				  if A[i - 1] > A[i] then
					  swap(A, i - 1, i)
					  swapped = true
				  end if
			  end for
			  n := n - 1
		  while swapped
		end procedure

*/
//procedure bubbleSort(A : list of sortable items)
void bubbleSort(std::vector<std::string>& A)
{
	//n := length(A)
	int n = A.size();
	bool swapped = false;
	//repeat
	do 
	{
		//swapped := false
		swapped = false;
		//for i := 1 to n - 1 inclusive do
		for (int i = 1; i <= n-1; i++)
		{
			//if A[i - 1] > A[i] then
			if (A[i - 1] > A[i])
			{
				//TODO: figure this out!!
				//swap(A, i - 1, i)  
				//1) OG swap
				//  
				//  temp variable (matches the type of the data stored)
				//		to store one item
				//  copy one value to the other spot in the vector
				//  copy temp into the first spot
				//std::string temp = A[i - 1];
				//A[i - 1] = A[i];
				//A[i] = temp;

				//2) CG swap
				std::swap(A[i - 1], A[i]);

				//swapped = true
				swapped = true;
			}//end if
		}//end for
		//n := n - 1
		n = n - 1;
	} while (swapped);
}//end procedure

int main()
{
	int fNum = 5;
	int fResult = factorial(fNum);
	for (size_t i = 0; i < 10; i++)//exit conditions MUST be true to loop
	{
		std::cout << i << " ";
	}
	std::vector<std::string> names = { "Wonder Woman", "Superman", "Batman", "Flash", "Aquaman" };
	//call your BubbleSort on the names vector.

	Console::WriteLine("--UNSORTED--", ConsoleColor::Yellow);
	//print the sorted vector.
	for (auto& name : names)
		std::cout << name << "\n";

	//call BubbleSort
	bubbleSort(names);

	Console::WriteLine("--SORTED--", ConsoleColor::Yellow);
	//print the sorted vector.
	for (auto& name : names)
		std::cout << name << "\n";


	/*
		╔═════════╗
		║Recursion║
		╚═════════╝

		Recursion happens when a method calls itself. This creates a recursive loop.

		All recursive methods need an exit condition, something that prevents the loop from continuing.

	*/
	int N = 0;
	recursiveLoop(N);


	/*
		CHALLENGE 1:

			convert this for loop to a recursive method called Bats.
			Call Bats here in Main.

			for(int i = 0;i < 100;i++)
			{
				std::cout << (char)78 << (char)65 << ' ';
			}
	*/
	//call Bats here.
	Bats();

	char c[] = { '\n', 66, 65, 84, 77, 65, 78, 33, 33 };
	for (auto ch : c) std::cout << ch;
	std::cout << "\n\n";

	ReverseWord("Bruce Wayne");
	std::cout << "\n\n";



	/*
		╔═════════════════╗
		║  Swapping Items ║
		╚═════════════════╝

		add #include <string_view>
		make sure the project is using C++17 or greater.

	*/
	std::cout << "\n\n---SWAPPING ITEMS---\n";
	std::vector<int> nums = { 1,2,3,4,5 };
	for (auto i : nums)
		std::cout << i << " ";
	std::cout << " (original)\n";

	//write code to swap 2 items in the vector

	std::cout << " (after swapping)\n";
	for (auto i : nums)
		std::cout << i << " ";

	/*
		╔═════════════════╗
		║Comparing Strings║
		╚═════════════════╝

		the compare functions return an int that will tell you
		how the strings compare to each other.
		< 0 means s1 is LESS THAN (or comes before) s2
		  0 means s1 is EQUAL TO s2
		> 0 means s1 is GREATER THAN (or comes after) s2

		_stricmp: case-insensitive string comparison.
			The methods needs pointers to char arrays therefore
			you need to call c_str on the std::string

		std::string::compare:  case-sensitive string comparison
			If you want to ignore case, you can convert the strings
			to all uppercase/lowercase

	*/
	std::string s1 = "Batman", s2 = "Aquaman";
	int compResult = _stricmp(s1.c_str(), s2.c_str());
	//OR...
	int compareResult = toUpper(s1).compare(toUpper(s2));





}