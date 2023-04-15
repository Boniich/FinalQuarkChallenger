#pragma once

#include <string>

using namespace std;

class Quotation;

class Seller
{
private:
	int sellerId = 1;
	string name = "Carlos";
	string lastName = "Tierra";

public:
	Seller();
	~Seller();
	string showSellerFullName();
	int showSellerId();

};

