#pragma once

#include <string>
#include "Seller.h";
#include "Clothes.h";
#include <list>

using namespace std;

class Seller;

class Shop
{
private:
	string name = "Tienda 1";
	string direction = "Calle falsa 123";
	Seller _seller;
	list<Clothes*> _clothes = {};
public:
	Shop();
	~Shop();
	string showInfoShop();
	string showInfoSeller();
	void stockPants();
	//metodos prenda
};