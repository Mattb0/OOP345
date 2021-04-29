#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	string myArray[15] = { "0", "1", "1", "1", "1", "1", "1", "0", "1", "1", "1", "1", "1", "1", "0" };
	string newArray[17] = {};
	int length = 15;
	int buffer = 0;

	cout << "Before Stuffing: ";
	for (int ii = 0; ii < length; ii++)
	{
		cout << myArray[ii];
	}

	for (int i = 0; i <= length; i++)
	{
		if (myArray[i] == "1")
		{
			if (buffer >= 5)
			{
				newArray[i] = "0";
				newArray[i + 1] = myArray[i];
				cout << endl << "adding a 0 to array no: " << i;
				buffer = 0;
				buffer++;

			}
			else
			{
				buffer++;
				newArray[i] = myArray[i];
			}
		}
		else
		{
			newArray[i] = myArray[i];
			buffer++;
			cout << "\n" << "buffer appended to: " << buffer;
		}
	}

	int length2 = 17;
	cout << endl << "After Stuffing: ";
	for (int ii = 0; ii < length; ii++)
	{
		cout<< newArray[ii];
	}

	cin.ignore();
}