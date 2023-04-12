#pragma once

#include <string>

using namespace std;

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
	void calculatePrice(); // cotizacion

};

