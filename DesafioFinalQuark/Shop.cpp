#include "Shop.h";
#include "Pants.h";
#include "Shirt.h";
#include "Quotation.h";
#include <string>;
#include <iostream>;

using namespace std;

Shop::Shop() {}

Shop::~Shop() {}

string Shop::showInfoShop()
{
	return name + " | " + direction;
}

string Shop::showInfoSeller()
{
	string id = to_string(_seller.showSellerId());

	return _seller.showSellerFullName() + " | " + id;
}

Quotation* Shop::getQuotationData()
{
	return _quotation;
}

void Shop::stockPants()
{

	Pants* normalStandarPants = new Pants("Pantalones", "Standard", 250, "Normal");
	Pants* normalPremiumPants = new Pants("Pantalones", "Premium", 250, "Normal");

	Pants* chupinStandarPants = new Pants("Pantalones", "Standard", 750, "Chupin");
	Pants* chupinPremiumPants = new Pants("Pantalones", "Premium", 750, "Chupin");


	Shirt* shirtStandarShortArmMao = new Shirt("Camisa", "Standard", 100, "Cuello Mao", "Manga Corta");
	Shirt* shirtPremiumShortArmMao = new Shirt("Camisa", "Premium", 100, "Cuello Mao", "Manga Corta");

	_clothes.push_back(normalStandarPants);
	_clothes.push_back(normalPremiumPants);
	_clothes.push_back(chupinStandarPants);
	_clothes.push_back(chupinPremiumPants);


	_clothes.push_back(shirtStandarShortArmMao);
	_clothes.push_back(shirtPremiumShortArmMao);
	//200
	//_clothes.push_back(new Shirt("Camisa", "Standard", 100, "Cuello Mao", "Manga Corta"));
	//_clothes.push_back(new Shirt("Camisa", "Premium", 100, "Cuello Mao", "Manga Corta"));
	
	
	//300
	_clothes.push_back(new Shirt("Camisa", "Standard", 150, "Cuello Comun", "Manga Corta"));
	_clothes.push_back(new Shirt("Camisa", "Premium", 150,  "Cuello Comun","Manga Corta"));

	//150
	_clothes.push_back(new Shirt("Camisa", "Standard", 75,"Cuello Mao" ,"Manga Larga"));
	_clothes.push_back(new Shirt("Camisa", "Premium", 75, "Cuello Mao", "Manga Larga"));

	//350
	_clothes.push_back(new Shirt("Camisa", "Standard", 175, "Cuello Comun", "Manga Larga"));
	_clothes.push_back(new Shirt("Camisa", "Premium", 175, "Cuello Comun", "Manga Larga"));

}


string Shop::showStockAvailable() 
{

	int  stock = getClotheAmountFromStock();

	return "EXISTE: " + to_string(stock) + " CANTIDAD DE UNIDADES EN STOCK DE LA PRENDA SELECCIONADA";

}


int Shop::getClotheAmountFromStock()
{

	int stock = 0;

	for (Clothes* clothe : _clothes)
	{

		if (clothe->showTypeChothe() == getQuotationData()->getClotheData()->showTypeChothe()
			&& clothe->showQuality() == getQuotationData()->getClotheData()->showQuality())
		{
			if (clothe->showTypeChothe() == "Camisa")
			{
				if (static_cast<Shirt*>(clothe)->showArmType() == static_cast<Shirt*>(getQuotationData()->getClotheData())->showArmType()
					&& static_cast<Shirt*>(clothe)->showNeckType() == static_cast<Shirt*>(getQuotationData()->getClotheData())->showNeckType())
				{

					stock = clothe->showStockAmount();
					return stock;

				}
			}
			else {
				if (static_cast<Pants*>(clothe)->showTypePants()
					== static_cast<Pants*>(getQuotationData()->getClotheData())->showTypePants()) {
					stock = clothe->showStockAmount();
					return stock;
				}
			}

		}
	}

}




/*funciona bien
string Shop::showStockPants()
{

	int stock = 0;

	for (Clothes* clothe : _clothes)
	{

		if (clothe->showTypeChothe() == getQuotationData()->getClotheData()->showTypeChothe()
			&& clothe->showQuality() == getQuotationData()->getClotheData()->showQuality())
		{
			if (clothe->showTypeChothe() == "Camisa")
			{
				if (static_cast<Shirt*>(clothe)->showArmType() == static_cast<Shirt*>(getQuotationData()->getClotheData())->showArmType()
					&& static_cast<Shirt*>(clothe)->showNeckType() == static_cast<Shirt*>(getQuotationData()->getClotheData())->showNeckType())
				{

					stock = clothe->showStockAmount();
					return "EXISTE: " + to_string(stock) + " CANTIDAD DE UNIDADES EN STOCK DE LA PRENDA SELECCIONADA";

				}
			}
			else {
				if (static_cast<Pants*>(clothe)->showTypePants()
					== static_cast<Pants*>(getQuotationData()->getClotheData())->showTypePants()) {
					stock = clothe->showStockAmount();
					return "EXISTE: " + to_string(stock) + " CANTIDAD DE UNIDADES EN STOCK DE LA PRENDA SELECCIONADA";
				}
			}

		}
	}

}*/