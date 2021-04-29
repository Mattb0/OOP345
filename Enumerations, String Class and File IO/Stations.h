#pragma once
#include "Station.h"

namespace w2
{
	class Stations
	{
	private:
		//	int stationCount = 0;  // C++14 
		//	Station* stationTable = nullptr; //C++14 
		// if its not C++14, their values cannot be set here. use the default constructor
		int stationCount;  
		Station* stationTable;

	public:
		Stations();					// default constructor
		Stations(char* filename);	// constructor setter
		~Stations();				// deconstructor

		// ----- member functions ----- //
		void update() const;		// accepts the number of passes sold and updates the data for each station in turn
		void restock() const;		// accepts the number of passes added and updates the data for each station in turn
		void report() const;		// reports the number of passes currently available at each station
	};
};