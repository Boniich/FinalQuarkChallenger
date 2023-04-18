#pragma once

#include <string>
#include "Seller.h";
#include "Clothes.h";
#include "Quotation.h";
#include <list>

using namespace std;

class Seller;
class Quotation;

class Shop
{
private:
	string name = "Tienda 1";
	string direction = "Calle falsa 123";
	Seller _seller;
	list<Clothes*> _clothes = {};
	Quotation* _quotation = nullptr;
	list<Quotation*> _quotationHistory = {};
public:
	Shop();
	~Shop();
	string showInfoShop();
	string showInfoSeller();
	void loadStockClothes();
	Quotation* getQuotationData();
	void makeQuotation();
	int getClotheAmountFromStock();
	string showStockAvailable();
	list<Quotation*> showHistoryQuotation();
	void saveQuotations();
};