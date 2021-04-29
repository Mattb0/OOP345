// Workshop 6 - Lambda Expression
// w6.cpp

#include <iostream>
using namespace std;

int main()
{
	try {
		auto X = [] { throw nullptr; }
		auto Y = [X] { X(); };
		auto Z = [Y] { Y(); };

		Z();
	}
	catch (const char* e) {
		cerr << "something threw a char* exception\n";
	}
	catch (const std::string* e) {
		cerr << "something threw a string exception\n";
	}
	catch (...) {
		cerr << "something threw a ... exception\n";
	}

	cin.ignore();
	return 0;
}