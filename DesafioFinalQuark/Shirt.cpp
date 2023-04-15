#include "Shirt.h";


Shirt::Shirt(
	string typeClothe, string quality, 
	string neckType, string armType):Clothes(typeClothe, quality)
{
	_neckType = neckType;
	_armType = armType;
}

string Shirt::showNeckType()
{
	return _neckType;
}
void Shirt::setNeckType(string neckType)
{
	_neckType = neckType;
}
string Shirt::showArmType()
{
	return _armType;
}
void Shirt::setArmType(string armType)
{
	_armType = armType;
}