#pragma once

#include "Clothes.h";

class Pants : public Clothes
{

private:
	string _typePants;

public:
	Pants(string typeClothe);
	Pants(string typeClothe,string quality, int stockAmount, string typePants);
	string showTypePants();
	void setTypePants(string typePants);
};