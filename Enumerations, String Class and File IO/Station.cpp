#include <string>
#include <fstream>
#include "Station.h"
#include <iostream>
using namespace std;

namespace w2		
{
	Station::Station(string sName, int sPass, int aPass)  // constructor = (sets args that are sent to it)
	{
		set(sName, sPass, aPass); // calls set with following args
	}

	Station::Station(std::fstream& in)
	{
		string name;
		// ---- getline ----
		getline(in, name, ';');
		// extracts characters from 'in'.
		// stores them into string 'name'.
		// until ';' is found. ('\n') also works.
		// ------------------
		int adult;
		int student;
		char curChar;

		in >> student;
		in >> adult; 
		in.get(curChar); // .get() reads the next character from a stream
	
		// DEBUG //
		/*
		cout << "\n";
		cout << "debug" << "\n------------------";
		cout << "\n";
		cout << "name : " << name;
		cout << "\n";
		cout << "student : " << student;
		cout << "\n";
		cout << "adult : " << adult;
		cout << "\n";
		cout << "curChar : " << curChar;
		cout << "\n";
		*/

		Station::set(name, student, adult); // set accepts string, unsigned int (student) and unsigned int (adult)
	}

	Station::Station()  
	// default constructor   (sets variables to pre defined values)
	{
		set("", 0, 0);  // calls set with following args
	}
	
	void Station::set(const std::string& n, unsigned student, unsigned adult)
	// sets the instance variables to the values received in its parameters
	{
		stationName = n;
		passes[PASS_STUDENT] = student;
		passes[PASS_ADULT] = adult;
	}

	void Station::update(PassType pt, int num) // NOTE to self: sent types from passes sold is supposed to DEDUCT not add! So make sure to fix it before you call .update() otherwise they will ADD
	{
		passes[pt] += num;  
	}

	unsigned Station::inStock(PassType pt) const
	{
		return passes[pt];
	}

	const std::string& Station::getName() const
	{
		return stationName;
	}
};


