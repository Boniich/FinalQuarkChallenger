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
	string _name;
	string _direction;
	Seller _seller;
	list<Clothes*> _clothes = {};
	Quotation* _quotation = nullptr;
	list<Quotation*> _quotationHistory = {};
	void loadShopData();
	void loadSellerData();
public:
	Shop();
	~Shop();
	void loadShopAndSellerData();
	string showInfoShop();
	string showInfoSeller();
	void loadStockClothes();
	Quotation* getQuotationData();
	void makeQuotation();
	int getClotheAmountFromStock();
	string showStockAvailable();
	list<Quotation*> showHistoryQuotation();
	void saveHistoryQuotation();
};