#include "Clothes.h";


Clothes::Clothes(string typeClothe) 
{
	_typeClothe = typeClothe;
}

Clothes::Clothes(string typeClothe,string quality, int stockAmount)
{
	_typeClothe = typeClothe;
	_quality = quality;
	_stockAmount = stockAmount;
}

Clothes::~Clothes(){}

// muestra si es camisa o pantalon

string Clothes::showTypeChothe()
{
	return _typeClothe;
}


string Clothes::showQuality()
{
	return _quality;
}

void Clothes::setQuality(string quality)
{
	_quality = quality;
}

double Clothes::showUnitaryPrice() 
{
	return _unitaryPrice;
}

void Clothes::setUnitaryPrice(double unitaryPrice)
{
	_unitaryPrice = unitaryPrice;
}

int Clothes::showStockAmount()
{
	return _stockAmount;
}