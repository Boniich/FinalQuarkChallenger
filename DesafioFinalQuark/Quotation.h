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

	void saveCurrentDataTime();

public:
	Quotation();
	Quotation(int id, string date, int sellerId, Clothes* clothes, int amount, double finalPrice);
	~Quotation();

	int getQuotationId();
	void setQuotationId(int id);

	//date
	
	string getDate();

	// final price

	double getFinalPrice();


	int getSellerId();
	void setSellerId(const int sellerId);

	// clothes method

	void selectingClothe(string option);
	void selectingQualityClothe(string option);
	void selectingUnitaryPrice(double unitaryPrice);

	// clothes method - shirts

	void selectingTypeShirtArm(string option);
	void selectingTypeShirtNeck(string option);

	// clothes methods - pants

	void selectingTypePants(string option);

	int getAmount();
	void setAmount(const int amount);

	Clothes* getClotheData();


	void makeQuotation(const int sellerId);
	void showHistoryQuotationBySeller(const int seller_id);
	string getResultQuotation();

};