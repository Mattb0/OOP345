#pragma once
#include <iostream>
#include <string>	

using namespace std;

namespace w5 {

	// Message object holds nothing or a single message that has been successfully retrieved from an std::ifstream file object.
	// An object that holds nothing is in a safe empty state.
	class Message {
		string name;
		string reply;
		string tweet;
	public:

		Message()
		{
		}

		Message(std::ifstream& in, char c) //- constructor retrieves a record from the in file object, parses the record (as described above) and stores its components in the Message object.  c is the character that delimits each record
		{
			string readLine; // store file in this string 'readLine'
			getline(in, readLine);   // read file
			size_t index = 0;

			// process name
			while (index < readLine.size() && readLine[index] != ' ')
			{
				name += readLine[index];
				index++;
			}

			index++;  // skip ' '

			// process reply
			if (index < readLine.size() && readLine[index] == '@') // if the next character is an @ sign
			{
				index++; // skip '@'
				// process reply
				while (index < readLine.size() && readLine[index] != ' ')
				{
					reply += readLine[index];
					index++;
				}
				index++; // skip
			}

			// process tweet
			while (index < readLine.size())
			{
				tweet += readLine[index];
				index++;
			}

			// set object to safe emtpy state if its incomplete
			if (tweet.empty())
			{
				// can use .clear() to achieve that
				name.clear();
				reply.clear();
			}
			else
			{
				cout << "\n" << "Message";
				cout << "\n" << "Name: " << name << "\n";

				if (!reply.empty())
				{
					cout << "Reply: " << reply << "\n";
				}

				cout << "Tweet: " << tweet << "\n";

			}
		}

		bool empty() const //- returns true if the object is in a safe empty state
		{
			return tweet.empty();

		}

		void display(std::ostream& os) const //- displays the Message objects within the container
		{
			os << "Name: " << name;
			if (reply.empty() == false)
			{
				os << "Name: " << name;
				os << "Reply: " << reply;
				os << "Tweet" << tweet;

			}
		}

	}
};  namespace w5