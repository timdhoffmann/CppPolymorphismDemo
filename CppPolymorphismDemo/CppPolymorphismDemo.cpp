// CppPolymorphismDemo.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "CppPolymorphismDemo.h"

/// Overloading (Ad-hoc Polymorphism).
#pragma region Overloading
int GetSize(int x)
{
	return x;
}

int GetSize(std::string x)
{
	return x.length();
}


#pragma endregion

/// Polymorphism (Sub-type Polymorphism).
#pragma region Polymorphism
class Animal
{
public:
	virtual void MakeNoise()
	{
		std::cout << "Animal noise." << std::endl;
	}
};

class Dog : public Animal
{
public:
	void MakeNoise() override // "override" is optional, but ensures that an actual override happens.
	{
		std::cout << "Wuff." << std::endl;
	}
};

class Cat : public Animal
{
public:
	void MakeNoise() override
	{
		std::cout << "Meow." << std::endl;
	}
};

void Stroke(Animal* animal) // Needs a pointer or reference (&) as parameter to work. Otherwise, the object is treaded as being of the parent class (type).
{
	animal->MakeNoise();
};
#pragma endregion


/// Main function.
int main()
{
	/// Overloading (Ad-hoc Polymorphism).
	std::cout << GetSize(5) << std::endl;
	std::cout << GetSize("Howdy!") << std::endl;

	/// Polymorphism (Sub-type Polymorphism).
	Dog dog;
	Cat cat;
	Stroke(&dog);
	Stroke(&cat);

	// Exit.
	return 0;
}

#pragma region Tips
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file  
#pragma endregion
