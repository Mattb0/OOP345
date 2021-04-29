#ifndef SICT_PRODUCT_H__
#define SICT_PRODUCT_H__
#include <istream>
#include <ostream> 
#include <cstring>
#include "Streamable.h"

using namespace std;
namespace sict{
	class Product : public Streamable{
		char* sku_;
		char* name_;
		double price_;
		bool taxed_;
		int quantity_;
		int qtyNeeded_;

	public:
		Product();
		Product(const char* sku, const char* name, bool taxed = true, int price = 0, int qtyNeeded = 0);

		// Setters
		void sku(const char* sku);
		void price(int price);
		void name(const char* name);
		void taxed(bool taxed);
		void quantity(int set);
		void qtyNeeded(int qtyNeeded);

		// Getters 
		char * sku() const;
		double price()const;
		char* name()const;
		bool taxed()const;
		int quantity()const;
		int qtyNeeded()const;

		double cost()const;
		bool  isEmpty()const;

		// Operators 
		bool operator==(char* compare)const;
		int operator+=(int add);
		int operator-=(int subtract);
	};

	// Non-Member operators
	double operator+=(double& left, const Product& b);

	//IO operators
	std::ostream & operator<<(ostream & ostr, const Product& a);
	std::istream & operator>>(istream & istr, Product& a);
}

#endif