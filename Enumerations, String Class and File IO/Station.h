#pragma once
#include <fstream>
#include <string> 
using namespace std;

namespace w2 
{
	// 1st numbers in .dat are student passes, 2nd numbers are adult passes
	enum PassType
	{
		PASS_STUDENT, 
		PASS_ADULT,
		PASS_COUNT
	};
	// use enum if you have more than 1 thing to define
	// emum AKA define.

	//Alternate way of doing it:
	//--------------------------
	//#define PASS_STUDENT 1
	//#define PASS_ADULT   2
	//#define PASS_COUNT   3

	class Station 
	{
		std::string stationName;	// the name of the station - stored as a string object
		int passes[PASS_COUNT];
	//	unsigned int studentPasses; // the number of student passes - stored as an unsigned int
	//	unsigned int adultPasses;   // the number of adult passes - stored as an unsigned int

	public:
	
		// member function is a function that objects of that class can call.  testobj.Testfunc();
		// ----- member functions ----- //

		Station(); // - a default constructor that initializes the instance variables through an initialization list
		Station(string sName, int sPass, int aPass);
		Station(std::fstream& in);

		// int - 8bytes  <---- signed
		// unsigned lets you have twice as many numbers, because in signed, half of the numbers were used for
		// negative. When using unsigned, this negative half can be use

		// 1bit 0-1
		// 2bit 0-3
		// 3bit 0-7

		// signed 3bit		-4, -3, -2, -1, 0, 1, 2, 3
		// unsigned 3bit	0, 1, 2, 3, 4, 5, 6, 7    More positive numbers because bits arent allocated for negative numbers

		void set(const std::string&, unsigned, unsigned); // sets the instance variables to the values received in its parameters
		void update(PassType, int); // updates the number of passes - sold if negative, added if positive
		unsigned inStock(PassType) const; // returns the number of passes of the requested type
		 
		 //PassType is an enumeration type that identifies pass types. 
		const std::string& getName() const; // returns a reference to a string object holding the name of the station
	};

};