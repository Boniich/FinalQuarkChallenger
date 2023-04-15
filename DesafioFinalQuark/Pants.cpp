#include "Pants.h";


Pants::Pants(string typeClothe, string quality, int stockAmount, string typePants):Clothes(typeClothe, quality, stockAmount)
{
	_typePants = typePants;
}

string Pants::showTypePants()
{
	return _typePants;
}

void Pants::setTypePants(string typePants)
{
	_typePants = typePants;
}
