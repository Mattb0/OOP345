#pragma once
#ifndef _I_PRODUCT_H_
#define _I_PRODUCT_H_
#include <iostream>
#include <fstream>

// Workshop 7 - STL Containers
// iProduct.h

namespace w7 {

	//The iProduct hierarchy holds information about the different products purchased by a customer.
	class iProduct {
	public:
		virtual double getCharge() const = 0;
		virtual void display(std::ostream&) const = 0;
	};

	// Product - Holds information about a product that consists of its product number and its cost
	class Product : public iProduct { // make it derive from iProduct 

		int pNo;
		double pCost;

	public:
		Product(const int productNo, const double productCost);
		void display(std::ostream&) const;
		double getCharge() const;

	};

	// TaxableProduct - Derives from Product and holds additional information about the product's taxable status
	class TaxableProduct : public iProduct {

		int pNo;
		double pCost;
		char pTax;

	public:
		TaxableProduct(const int productNo, const double productCost, const char productTax);
		double getCharge() const;
		void display(std::ostream&) const;

	};

	std::ostream& operator<<(std::ostream& os, const iProduct& p);
	iProduct* readProduct(std::ifstream& is);
}
#endif