#include "Seller.h"
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
	string fullName = name + " " + lastName;

	return fullName;
}

int Seller::showSellerId()
{
	return sellerId;
}
