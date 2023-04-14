#include "Quotation.h";
#include "Pants.h";
#include <iostream>

using namespace std;

Quotation::Quotation() 
{

}

Quotation::~Quotation()
{

}

int Quotation::getQuotationId()
{
	return 0;
}
void Quotation::setQuotationId()
{

}

//date
//


int Quotation::getSellerId()
{
	return 0;
}
void Quotation::setSellerId(const int sellerId)
{
	_sellerId = sellerId;
}

// prenda


void Quotation::selectingClothe(string option)
{
	if (option == "1")
	{
		
	}
	else if (option == "2")
	{
		_clothes = new Pants("","");
	}
}

void Quotation::selectingQualityClothe(string option)
{
	if (option == "1")
	{
		// seteamos la calidad en standard
		_clothes->setQuality("Standard");
	}
	else if (option == "2")
	{
		//seteamos la calidad en premium
		_clothes->setQuality("Premium");
	}
}


void Quotation::selectingUnitaryPrice(double unitaryPrice)
{
	_clothes->setUnitaryPrice(unitaryPrice);
}

void Quotation::selectingTypePants(string option)
{

	if (option == "1")
	{
		// definimos si el pantaon es chupin
		static_cast<Pants*>(_clothes)->setTypePants("Chupin");
	}
	else if (option == "2")
	{
		// definimos si el pantalon es normal

		static_cast<Pants*>(_clothes)->setTypePants("Normal");
	}
	
}


/// amount

int Quotation::getAmount()
{
	return _amount;
}
void Quotation::setAmount(const int amount)
{
	_amount = amount;
}


void Quotation::makeQuotation()
{
	cout << "Realizando cotizacion" << endl;
}


