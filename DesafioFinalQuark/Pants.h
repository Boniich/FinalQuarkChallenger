#pragma once

#include "Clothes.h";

class Pants : public Clothes
{

private:
	string _typePants;

public:
	Pants(string quality,string typePants);
	string showTypePants();
	void setTypePants(string typePants);
};