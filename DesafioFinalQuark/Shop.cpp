#include "Shop.h";
#include <string>;

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