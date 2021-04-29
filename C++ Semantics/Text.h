#pragma once
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

namespace w3
{
	class Text
	{
		size_t s = 0; // c++ 14
		std::string* b = nullptr; // c++ 14

	public:
		Text()
		{
			// in c++14 class vars can be declared right under the class, without having to initiliaze them in a constructor.
			// however, constructor HAS to be declared
			//size_t s = 0;
			//std::string* b = nullptr;
		}

		Text(char* filename)  
		{
			std::fstream in(filename, std::ios::in);
			// ^^ --->in<--- so that 'in' can be used to refer to that file (fstream).
			if (in.is_open() == false ) // if file cannot be opened
			{
				std::cerr << "Cannot open file " << filename << "\n";
				// system("PAUSE"); // debug - disable 
				exit(99);
			}

			std::string line;

			// count the number of lines in the file
			while (getline(in, line))
				s++;
			std::cout << "file " << filename << " has " << s << " lines\n";
			// -------------------------------------

			// allocate memory for lines
			b = new std::string[s];
			// ----------------

			in.clear(); // file is in an error state. .clear() the error state

			// rewind it data file before reading it again. seekp will set the position back to the begining.
			in.seekp(0); // seekp() *Sets the position where the next character is to be inserted into the output stream.

			// read data file
			for (size_t i = 0; i < s; i++)
			{
				getline(in, b[i]);
			}
			// --------------------------
			in.close();
		}

		~Text()   // deconstructor
		{
			delete [] b;
		}

		Text& operator=(const Text& rhs)  // copy assignment operator
		{
			if (this != &rhs)
			{
				delete [] b;
				b = nullptr;
				s = 0;
				if (rhs.b)
				{
					s = rhs.s; // rhs = right hand side
					b = new std::string[s];
					for (size_t i = 0; i < s; i++) // deep copy
						b[i] = rhs.b[i];
				}
			}
			else
			{
				std::cout << "copy assignment operator: self assignemnt\n";
			}
			return *this;
		}

		Text(const Text& rhs) // copy constructor - sets a var in class to incoming arg
		{
			*this = rhs;	
		}

		Text(Text&& rhs)  // move constructor
		{
			*this = rhs;
		}

		Text&& operator=(Text&& rhs)  // move assignment operator
		{
			if (this != &rhs)
			{
				delete [] b; // delete our brains
				b = rhs.b; // steal rhs brains
				s = rhs.s;
				rhs.b = nullptr; // make rhs a zombie
				rhs.s = 0;
			}
			else
			{
				std::cout << "move assignment operator: self assignment\n";
			}
			return std::move(*this);
		}

		size_t size() // member function size
		{
			return s;
		}

	};
};
