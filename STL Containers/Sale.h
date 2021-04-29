#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "iProduct.h"
#include <iomanip> /

namespace w7 {
	class Sale {

	public:
		Sale(const char*);
		void display(std::ostream&);

	private:
		std::vector<iProduct*> productList;
	};
}