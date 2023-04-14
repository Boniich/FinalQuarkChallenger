#include "Pants.h";


Pants::Pants(string typeClothe, string quality, string typePants):Clothes(typeClothe, quality)
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
