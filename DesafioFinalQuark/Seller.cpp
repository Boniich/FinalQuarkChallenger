#include "Seller.h"
#include "Quotation.h";
#include <string>

using namespace std;

Seller::Seller()
{

}

Seller::~Seller()
{

}

string Seller:: showSellerFullName()
{
	string fullName = _name + " " + _lastName;

	return fullName;
}

int Seller::showSellerId()
{
	return _sellerId;
}

void Seller::setSellerFullName(string name, string lastName)
{
	_name = name;
	_lastName = lastName;
}
void Seller::setSellerId(const int sellerId)
{
	_sellerId = sellerId;
}
