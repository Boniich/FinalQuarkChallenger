#include "Quotation.h";
#include "Pants.h";
#include "Shirt.h";
#include <ctime>
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
	return _id;
}
void Quotation::setQuotationId()
{

}

//date

void Quotation::saveCurrentDataTime()
{
	string day, month, year, hour, min;
	struct tm newtime;
	time_t t = time(nullptr);
	localtime_s(&newtime,&t);
	day = to_string(newtime.tm_mday);
	month = to_string(1+ newtime.tm_mon);
	year = to_string(1900 + newtime.tm_year);
	hour = to_string(newtime.tm_hour);
	min = to_string(newtime.tm_min);
 
	_date = day + "/" + month + "/" +year + " " + hour+":"+ min;
}


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
		_clothes = new Shirt("Camisa", "", "", "");
	}
	else if (option == "2")
	{
		_clothes = new Pants("Pantalones","","");
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

// Shirt method

void Quotation::selectingTypeShirtArm(string option)
{

	if (option == "1")
	{
		// definimos si la camisa es manga corta
		static_cast<Shirt*>(_clothes)->setArmType("Manga Corta");
		
	}
	else if (option == "2")
	{
		// definimos si la camisa es manga larga
		static_cast<Shirt*>(_clothes)->setArmType("Manga Larga");
		
	}
}

void Quotation::selectingTypeShirtNeck(string option)
{

	if (option == "1")
	{
		// definimos si la camisa es cuello mao
		static_cast<Shirt*>(_clothes)->setNeckType("Cuello Mao");
	}
	else if (option == "2")
	{
		// definimos si la camisa es cuello comun

		static_cast<Shirt*>(_clothes)->setNeckType("Cuello Comun");
	}
}



// Pants method

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
	double price = _clothes->showUnitaryPrice();

	_id++;
	

	//tipo de prenda

	if (_clothes->showTypeChothe() == "Camisa")
	{

		if (static_cast<Shirt*>(_clothes)->showArmType() == "Manga Corta") 
		{
			price -= (_clothes->showUnitaryPrice() * 10) / 100;
		}

		if (static_cast<Shirt*>(_clothes)->showNeckType() == "Cuello Mao")
		{
			price += (price * 3) / 100;
		}
	}
	else {

		if (static_cast<Pants*>(_clothes)->showTypePants() == "Chupin")
		{
			price -= (_clothes->showUnitaryPrice() * 12) / 100;
		}
	}


	// calidad
	
	if (_clothes->showQuality() == "Premium") {

		price += (price * 30) / 100;
	}

	_finalPrice = price * getAmount();
	saveCurrentDataTime();
}


