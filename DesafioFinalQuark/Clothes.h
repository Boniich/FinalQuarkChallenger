#pragma once

#include <string>

using namespace std;

class Clothes
{
private:
	string _quality;
	double _unitaryPrice;
	int _stockAmount;
public:
	Clothes(string quality);
	~Clothes();
	string showQuality();
	void setQuality(string quality);
	double showUnitaryPrice();
	void setUnitaryPrice(double unitaryPrie);
	int showStockAmount();
};