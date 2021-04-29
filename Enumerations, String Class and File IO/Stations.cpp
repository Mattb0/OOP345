#include <fstream>
#include <iostream>
#include <string>
#include "Stations.h"
#include "Station.h"
#include <iomanip>
using namespace std;
/*
	Stations processes information about the monthly passes stored at a set of
	monitored Subway stations.  

	The Stations constructor receives the name of a file in the form of a C-style, 
	null-terminated string. 

	The file contains all of the data for the monitored stations (see below). 
	The first record holds the number of stations and the delimiter character for name input. 

	Each subsequent record holds the name of a station followed by the delimiter, 
	the number of students passes and the number of adult passes.  

	Upon instantiation, a Stations object opens the file,  allocates memory for the 
	monitored stations and copies the data from the file to each Station object.

	Upon destruction,  a Stations object copies the updated data from memory to the same file, 
	overwriting the previous records.
 */

namespace w2
{
	Stations::Stations()
	{
		int stationCount = 0;  
		Station* stationTable = nullptr;
	}

	Stations::~Stations()
	{
		delete[] stationTable;
	}

	Stations::Stations(char* filename)   // gets called by main, opens the filename. using fstream
	{
		fstream in(filename); // opens file and is refered to it by 'in'
							
		 if (in.is_open() == true ) // check if file is open.
		 {
			 in >> stationCount; // ???
			// cout << "stationCount =" << stationCount << "\n"; // debug - disable
			 char curChar;
			 in.get(curChar);
			 if (curChar != ';') 
			 {
				 //cerr << "BAD DATA: no ';', student count', adult count" << "\n"; 	 // DEBUG PURPOSES 
				 exit(10); // uncomment 
			 }
			 else
			 {
				 stationTable = new Station[stationCount];
				 for (int s = 0; s < stationCount; s++)
				 {
					 stationTable[s] = Station(in);
				 }
			 }
			 in.close();  // closes the file (good practice)
		 }
	}

	void Stations::update() const  // this func is supposed to remove passes
	{
		cout << "Passes Sold :";
		cout << "\n";
		cout << " -------------";
		cout << "\n";
		for (int s = 0; s < stationCount; s++)
		{
			int adultSold;
			int studentSold;
				
			cout << stationTable[s].getName();
			cout << "\n";
			cout << " Student Passes sold : ";
			cin >> studentSold;
			cout << " Adult Passes sold : ";
			cin >> adultSold;
			cout << "\n";

			// turn user input into negative numbers, to prevent miscalculation with Station.cpp .update()
			studentSold = -studentSold;
			adultSold = -adultSold;
			// if they are not negative numbers, they will add to number of passes instead of subtract.
			// Update student
			stationTable[s].update(PASS_ADULT, adultSold);
			stationTable[s].update(PASS_STUDENT, studentSold);
		}
	}

	// 1st numbers in .dat are student passes, 2nd numbers are adult passes
	void Stations::restock() const // this func is supposed to add passes
		{
			cout << "Passes Added : ";
			cout << "\n";
			cout << "--------------";
			cout << "\n";

			for (int s = 0; s < stationCount; s++)
			{
				int adultAdded;
				int studentAdded;

				cout << stationTable[s].getName();
				cout << "\n";
				cout << " Student Passes added : ";
				cin >> studentAdded;
				cout << " Adult Passes added : ";
				cin >> adultAdded;
				cout << "\n";

				stationTable[s].update(PASS_STUDENT, studentAdded);
				stationTable[s].update(PASS_ADULT, adultAdded);
			}
		}

		// 1st numbers in .dat are student passes, 2nd numbers are adult passes
		void Stations::report() const
		{

			cout << "Passes in Stock : Student  Adult";
			cout << "\n";
			cout << " -------------------------------";
			cout << "\n";

			for (int s = 0; s < stationCount; s++)
			{

				cout << left << setw(20) << stationTable[s].getName();
				cout << right << setw(6) << stationTable[s].inStock(PASS_STUDENT);
				cout << "   " << right << stationTable[s].inStock(PASS_ADULT);
				cout << "\n";
			}
		}
};
