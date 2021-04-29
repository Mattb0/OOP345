#pragma once
#include <iostream>
#include "message.h"
using namespace std;
const size_t NOTIFICATION_MAX = 10;

namespace w5
{
	class Notifications
	{

		Message messageTable[NOTIFICATION_MAX];
		size_t count = 0; // C++ 14

	/*
		A Notifications object manages access to a set of up to 10 Message objects.
		The Notifications object collects copies of the Message objects, owns those copies and destroys them once they are no longer needed.
	*/
	public:
		Notifications()  //- default constructor - empty
		{
			//count = 0; // c++ 98, not needed
		}

		//  --------------- RULE OF 5 ----------------
		Notifications(const Notifications& rhs) //- copy constructor
		{
			*this = rhs;
		}

		Notifications& operator=(const Notifications& rhs) //- copy assignment operator
		{
			if (this != &rhs)
			{
				for (size_t i = 0; i < rhs.count; i++)
					messageTable[i] = rhs.messageTable[i];
			}
			return *this;
		}

		Notifications(Notifications&& rhs) //- move constructor
		{
			*this = std::move(rhs);
		}

		Notifications&& operator=(Notifications&& rhs) //- move assignment operator
		{
			if (this != &rhs)
			{
				for (size_t i = 0; i < rhs.count; i++)
					messageTable[i] = std::move(rhs.messageTable[i]);  // copy assignment opreator and move assignment operators only differences is std:move
				rhs.count = 0; // rhs is a zombie
			}
			return std::move(*this);  // copy assignment opreator and move assignment operators only differences is std:move
		}

		~Notifications() //- destructor
		{

		}

		void operator+=(const Message& msg) //- adds msg to the set from Message object																
		{
			if (count < NOTIFICATION_MAX)
			{
				messageTable[count] = msg;
				count++;
			}
			else {
				cerr << "class Notifications: table full, increse size of NOTIFICATION_MAX, recompile and re-run\n";
				exit(99);

			}
		}

		void display(std::ostream& os) const //- inserts the Message objects to the os output stream
		{

			for (size_t i = 0; i < count; i++)
			{
				messageTable[i].display(os);
			}

		}
	}
};