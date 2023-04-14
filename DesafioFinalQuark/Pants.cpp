#include "Pants.h";


Pants::Pants(string quality, string typePants):Clothes(quality)
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
