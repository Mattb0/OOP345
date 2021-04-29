#include <istream>
#include <ostream> 
#include <cstring>
#include "Product.h"
#include "general.h"
using namespace std;

namespace sict{

	Product::Product()
	{
		sku_ = nullptr;
		name_ = nullptr;
		taxed_ = true;
		price_ = 0;
		quantity_ = 0;
		qtyNeeded_ = 0;
	}

	Product::Product(const char* sku, const char* name, bool taxed, int price, int qtyNeeded)
	{	
		this->sku((char *)sku);
		this->name((char *)name);
		this->taxed(taxed);
		this->price(price);
		this->qtyNeeded(qtyNeeded);
		quantity(0);
	}

	void Product::sku(const char* sku)
	{
		sku_ = new char[*sku + 1];
		strncpy(sku_, sku, MAX_SKU_LEN + 1);
	}

	void Product::price(int price)
	{
		price_ = price;
	}

	void Product::name(const char* name)
	{
		name_ = new char[*name + 1];
		strncpy(name_, name, *name + 1);
	}

	void Product::taxed(bool taxed)
	{
		taxed_ = taxed;
	}

	void Product::quantity(int set)
	{
		quantity_ = set;
	}

	void Product::qtyNeeded(int qtyNeeded)
	{
		qtyNeeded_ = qtyNeeded;
	}

	char * Product::sku()const
	{
		return sku_;
	}

	double Product::price()const
	{
		return price_;
	}

	char * Product::name()const
	{
		return name_;
	}

	bool Product::taxed()const
	{
		return taxed_;
	}

	int Product::quantity()const
	{
		return quantity_;
	}

	int Product::qtyNeeded()const
	{
		return qtyNeeded_;
	}

	double Product::cost()const
	{
		return price_;
	}

	bool Product::isEmpty()const
	{
		if (sku_ == nullptr && name_ == nullptr && taxed_ == true && price_ == 0 && quantity_ == 0 && qtyNeeded_ == 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool Product::operator==(char* compare)const
	{
		bool rtnVal = false;

		if (strcmp(sku_, compare) == 1)
		{
			rtnVal = true;
		}

		return rtnVal;
	}

	int Product::operator+=(int add)
	{
		add += quantity_;
		return add;
	}

	int Product::operator-=(int subtract)
	{
		subtract -= quantity_;
		return subtract;
	}

	double operator+=(double& left, const Product& b)
	{
		double a;
		a = b.cost() * b.quantity();
		left += a;

		return a;
	}

	std::ostream & operator<<(ostream & ostr, const Product& a)
	{
		a.write(ostr, true);
		return ostr;
	}

	std::istream & operator>>(istream & istr, Product& a)
	{
		a.read(istr);
		return istr;
	}
}