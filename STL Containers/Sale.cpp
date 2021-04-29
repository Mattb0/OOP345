#include "Sale.h"

namespace w7
{	
	Sale::Sale(const char* fileN)
	{
		std::ifstream file(fileN);
			while (file.good())
			{
				iProduct* curProduct = readProduct(file);
				productList.push_back(curProduct);
			}
			productList.pop_back();
	}

	void Sale::display(std::ostream& ost )
	{
		double total = 0;
		ost << "Product No    |    Cost     |    Taxable" << "\n";
		for (auto prod : productList) 
		{
			ost << *prod;
			total += prod->getCharge();
		}
		ost << std::endl << std::right << std::setw(10) << "Total:" << std::setw(5) << std::right << "$" <<  total << '\n'; 
		for (int fInt = 0; fInt < 3;)
		{
			fInt++;
			ost << std::endl << ".";
		}
		ost << std::endl << "Program Complete!" << std::endl;
	}
}