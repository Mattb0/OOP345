#include <iostream>
#include <fstream>
#include <iomanip> // setw requires iomanip
#include "iProduct.h"

static double HST = 1.13;
static double PST = 1.08;

namespace w7
{
	Product::Product(int no, double cost)
	{
		pNo = no;
		pCost = cost;
	}

	double Product::getCharge() const
	{
		return pCost;
	}

	void Product::display(std::ostream& ost) const
	{
		ost << std::right << std::setw(10) << pNo << std::setw(10);
		ost << std::setw(10) << std::setw(10);
		ost << pCost;
		ost << std::endl;

	}

	TaxableProduct::TaxableProduct(int no, double cost, char tax)
	{
		pNo = no;
		pCost = cost;
		pTax = tax;
	}

	double TaxableProduct::getCharge() const
	{
		double taxPercentage = 1;

		if (pTax == 'H')
		{
			taxPercentage = HST;
		}
		else if (pTax == 'P')
		{
			taxPercentage = PST;
		}

		return pCost * taxPercentage;
	}

	void TaxableProduct::display(std::ostream& ost) const
	{
		ost << std::setw(10) << std::right << pNo << std::setw(10) << std::right << pCost;
		ost << std::setw(13);

		if (pTax == 'H')
		{
			ost << "HST";
		}
		else if (pTax == 'P')
		{
			ost << "PST";
		}

		ost << std::endl;

	}

	std::ostream& operator<<(std::ostream& ostr, const iProduct& product) {
		product.display(ostr);
		return ostr;
	}

	iProduct* readProduct(std::ifstream& istr) {
		int no;
		double cost;
		char tax;

		iProduct* currentVal;

		istr >> no >> cost;

		if (istr.get() != '\n')
		{
			istr.get(tax);

			currentVal = new TaxableProduct(no, cost, tax);
		}
		else
		{
			currentVal = new Product(no, cost);
		}

		return currentVal;
	}
}

