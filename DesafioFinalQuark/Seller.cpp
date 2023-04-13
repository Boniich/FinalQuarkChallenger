#include "Seller.h"
#include "Quotation.h";
#include <string>

using namespace std;

Seller::Seller() : _quotation(new Quotation())
{

}

Seller::~Seller()
{

}

string Seller:: showSellerFullName()
{
	string fullName = name + " " + lastName;

	return fullName;
}

int Seller::showSellerId()
{
	return sellerId;
}

void Seller::makeQuotation()
{
	_quotation->makeQuotation();
}
