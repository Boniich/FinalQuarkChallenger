#pragma once
#include "Clothes.h";
#include <string>;

using namespace std;

class Shirt : public Clothes
{

private:
	string _neckType;
	string _armType;
public:
	Shirt(string typeClothe, string quality, string neckType, string armType);
	string showNeckType();
	void setNeckType(string neckType);
	string showArmType();
	void setArmType(string armType);
};