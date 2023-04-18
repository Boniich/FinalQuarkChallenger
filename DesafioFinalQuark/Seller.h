#pragma once

#include <string>

using namespace std;

class Quotation;

class Seller
{
private:
	int _sellerId;
	string _name;
	string _lastName;

public:
	Seller();
	~Seller();
	string showSellerFullName();
	int showSellerId();
	void setSellerFullName(string name, string lastName);
	void setSellerId(const int sellerId);

};

