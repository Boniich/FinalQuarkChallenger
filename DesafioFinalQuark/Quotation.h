#pragma once

#include "Clothes.h";
#include <string>

using namespace std;

class Clothes;

class Quotation
{
private: 
	int _id = 0;
	string _date;
	int _sellerId;
	Clothes* _clothes = NULL;
	int _amount = 0;
	double _finalPrice;

public:
	Quotation();
	~Quotation();

	int getQuotationId();
	void setQuotationId();

	//date
	//
	int getSellerId();
	void setSellerId(const int sellerId);

	// clothes method

	void selectingClothe(string option);
	void selectingQualityClothe(string option);
	void selectingUnitaryPrice(double unitaryPrice);

	// clothes methods - pants

	void selectingTypePants(string option);

	int getAmount();
	void setAmount(const int amount);


	void makeQuotation();
	void showHistoryQuotationBySeller(const int seller_id);

};