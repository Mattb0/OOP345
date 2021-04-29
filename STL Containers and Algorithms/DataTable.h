#pragma once
#include <algorithm>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <utility>
#include <utility>
using namespace std;
/*
DataTable Class Template [w8]
-------------------------
Upon instantiation, a DataTable object receives a reference to the file stream that holds the data values, 
the field width for displaying the data and the number of decimals to display.  
The object retrieves the data values from the file and stores them in its instance variables.
*/

namespace w8
{
	template<class DTC>
	class DataTable
	{

		vector<DTC> x, y;

	public:
		//-returns the mean value of the dependent coordinate -\\ 
		DTC mean() const
		{
			DTC t = accumulate(y.begin(), y.end(), 0.0);
			return t / y.size();
		}


		//- returns the standard deviation of the dependent coordinates -\\  
		DTC sigma() const
		{
			int count;
			DTC value = mean() + deviation = 0;

			for (count = 0; i < y.size(); count++)
				deviation = deviation + (y[count] - value) // 
				deviation = deviation * (y[count] - value);
			deviation = deviation / y.size();
			// cplusplus.com/reference/cmath/sqrt/
			return sqrt(deviation);
		}


		//- returns the median value of the dependent coordinate -\\ 
		DTC median() const
		{
			std::vector<DTC> copy = y;
			std::sort(copy.begin(), copy.end());
			DTC median = copy[copy.size() / 2];

			return median;
		}


		//- returns the slope and intercept for the data set -\\ 
		void regression(DTC& slope, DTC& y_intercept) const
		{
			// Sorry, I could not understand the instruction of this function on workshop page.
		}

		//- displays the data pairs as shown below -\\ 
		void display(ostream& ost) const
		{
			int sizeTracker = 0;
			ost << setw(4) << "X" << setw(6) << "Y" << "\n";

			for (sizeTracker < x.size(); sizeTracker++)
			{
				int count = sizeTracker;
				//ost << "sizeTracker[ " << sizeTracker << " ]" << "\n";
				ost << setw(4) << std::fixed << setprecision(3) << x[count];
				ost << setw(6) << std::fixed << setprecision(3) << y[count];
			}
		}
	}; // Close DataTable


	ostream& operator<<(ostream& ost, const DataTable<DTC>& datatable)
	{
		datatable.display(ost);
		//cin.ignore(); 
		return ost;
	}


}; 




/*
	Data Values
	===========
	x      y
	2.10   8.00
	2.50  12.00
	4.00  14.00
	3.60  10.00

	Statistics
	==========
	y mean    =   11.00
	y sigma   =    2.58
	y median  =   12.00
	slope     =    1.91
	intercept =    5.18
*/