#pragma once

#include <string>

using namespace std;

class Quotation
{
private: 
	int id;
	string date;
	int seller_id;
	//prenda
	int amount;
	double finalPrice;

public:
	Quotation();
	~Quotation();
	void makeQuotation();
	void showHistoryQuotationBySeller(const int seller_id);

};