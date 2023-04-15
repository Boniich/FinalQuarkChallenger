#include "Shop.h";
#include "Pants.h";
#include <string>;
#include <iostream>;

using namespace std;

Shop::Shop(){}

Shop::~Shop(){}

string Shop::showInfoShop()
{
	return name + " | " + direction;
}

string Shop::showInfoSeller()
{
	string id = to_string(_seller.showSellerId());

	return _seller.showSellerFullName() + " | " + id ;
}

void Shop::stockPants()
{

	Pants* normalStandarPants = new Pants("Pantalones", "Standard",250, "Normal");
	Pants* normalPremiumPants = new Pants("Pantalones", "Premium", 250, "Normal");

	Pants* chupinStandarPants = new Pants("Pantalones", "Standard", 750, "Chupin");
	Pants* chupinPremiumPants = new Pants("Pantalones", "Premium", 750, "Chupin");


	_clothes.push_back(normalStandarPants);
	_clothes.push_back(normalPremiumPants);
	_clothes.push_back(chupinStandarPants);
	_clothes.push_back(chupinPremiumPants);

	/*
	Pants* _pantsStandard = new Pants("Standard", "Chupin");
	Pants* _pantsPremium = new Pants("Premium", "Chupin");
	Pants* _normalPantsStandard = new Pants("Standard", "Normal");
	Pants* _normalPantsPremium = new Pants("Premium", "Normal");

	for (int e = 0; e < 750; e++) {
		
		_clothes.push_back(_pantsStandard);
		_clothes.push_back(_pantsPremium);
	}

	for (int e = 0; e < 250; e++) {

		_clothes.push_back(_normalPantsStandard);
		_clothes.push_back(_normalPantsPremium);
	}

	list<Clothes*>::iterator it = _clothes.begin();

	while (_pantsStandard->showQuality() == "Chupin") it++;
	cout << *it;

	/// funciona
	auto pan = (Pants*)_clothes.front();
	//cout << pan->showTypePants();

	// nos devuelve el tamaño de la lista
	cout << _clothes.size();
	
	*/
	
	
}