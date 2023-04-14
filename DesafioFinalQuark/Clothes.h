#pragma once

#include <string>

using namespace std;

class Clothes
{
private:
	//experiment
	string _typeClothe;
	//
	string _quality;
	double _unitaryPrice;
	int _stockAmount;
public:
	Clothes(string typeClothe,string quality);
	~Clothes();
	string showTypeChothe();
	string showQuality();
	void setQuality(string quality);
	double showUnitaryPrice();
	void setUnitaryPrice(double unitaryPrie);
	int showStockAmount();
};