#include "Shop.h";
#include "Pants.h";
#include "Shirt.h";
#include "Quotation.h";
#include <string>;
#include <iostream>;

using namespace std;

Shop::Shop() {
	
	_quotation = new Quotation();

}

Shop::~Shop() 
{
	delete _quotation;
	for (Clothes* clothe : _clothes) { delete clothe;};
	_clothes.clear();
	for (Quotation* history : _quotationHistory) { delete history; };
	_quotationHistory.clear();
}


void Shop::loadShopData()
{
	_name = "Tienda 1";
	_direction = "Calle false 123";
}

void Shop::loadSellerData()
{
	_seller.setSellerFullName("Antonio", "Quark");
	_seller.setSellerId(1);
}

void Shop::loadShopAndSellerData()
{
	loadShopData();
	loadSellerData();
}


string Shop::showInfoShop()
{
	return _name + " | " + _direction;
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

void Shop::loadStockClothes()
{

	// Stock shirt
	//200

	_clothes.push_back(new Shirt("Camisa", "Standard", 100, "Cuello Mao", "Manga Corta"));
	_clothes.push_back(new Shirt("Camisa", "Premium", 100, "Cuello Mao", "Manga Corta"));


	//300
	_clothes.push_back(new Shirt("Camisa", "Standard", 150, "Cuello Comun", "Manga Corta"));
	_clothes.push_back(new Shirt("Camisa", "Premium", 150, "Cuello Comun", "Manga Corta"));

	//150
	_clothes.push_back(new Shirt("Camisa", "Standard", 75, "Cuello Mao", "Manga Larga"));
	_clothes.push_back(new Shirt("Camisa", "Premium", 75, "Cuello Mao", "Manga Larga"));

	//350
	_clothes.push_back(new Shirt("Camisa", "Standard", 175, "Cuello Comun", "Manga Larga"));
	_clothes.push_back(new Shirt("Camisa", "Premium", 175, "Cuello Comun", "Manga Larga"));


	// stock pants

	//250 - Normal
	_clothes.push_back(new Pants("Pantalones", "Standard", 250, "Normal"));
	_clothes.push_back(new Pants("Pantalones", "Premium", 250, "Normal"));

	//750 - chupin
	_clothes.push_back(new Pants("Pantalones", "Standard", 750, "Chupin"));
	_clothes.push_back(new Pants("Pantalones", "Premium", 750, "Chupin"));

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


list<Quotation*> Shop::showHistoryQuotation()
{
	list<Quotation*> history = {};

	for (Quotation* quotation : _quotationHistory)
	{
		if (quotation->getSellerId() == _seller.showSellerId())
		{
			history.push_back(quotation);
		}
	}

	return history;
}

void Shop::saveHistoryQuotation()
{
	int idQuotation = getQuotationData()->getQuotationId();
	string date = getQuotationData()->getDate();
	Clothes* clothe = getQuotationData()->getClotheData();
	int sellerId = getQuotationData()->getSellerId();
	int amount = getQuotationData()->getAmount();
	double finalPrice = getQuotationData()->getFinalPrice();

	Quotation* saveQuotation = new Quotation(idQuotation, date, sellerId, clothe, amount, finalPrice);

	_quotationHistory.push_back(saveQuotation);
}


void Shop::makeQuotation()
{
	int sellerId = _seller.showSellerId();


	getQuotationData()->makeQuotation(sellerId);

	saveHistoryQuotation();
}