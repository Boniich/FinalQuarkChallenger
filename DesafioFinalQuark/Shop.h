#pragma once

#include <string>
#include "Seller.h";

using namespace std;

class Seller;


class Shop
{
private:
	string name = "Tienda 1";
	string direction = "Calle falsa 123";
	Seller _seller;
	//prenda
public:
	Shop();
	~Shop();
	string showInfoShop();
	string showInfoSeller();
	//metodos prenda
};