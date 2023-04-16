#include "Presenter.h";
#include "IView.h";
#include "Seller.h";
#include "Quotation.h";
#include "Shop.h";
#include <iostream>;
#include <string>;

using namespace std;

Presenter::Presenter(IView* view) : _view(view), _seller(new Seller()), _shop(new Shop), _quotation(new Quotation())
{

}

Presenter::~Presenter()
{
	delete _seller;
}

void Presenter::showInfoSeller() {

	string sellerName = _shop->showInfoSeller();
	_view->showText(sellerName);
}

void Presenter::showInfoShop()
{
	string shopName = _shop->showInfoShop();
	_view->showText(shopName);
}

void Presenter::loadStockClothes()
{
	_shop->loadStockClothes();
}

void Presenter::showStockAvailable()
{

	string stock = _shop->showStockAvailable();
	_view->showText(stock);
}


void Presenter::setAmount(const int amount)
{
	_shop->getQuotationData()->setAmount(amount);
}

void Presenter::makeQuotation(const int sellerId)
{
	_shop->makeQuotation();
}

void Presenter::chooseClothe(const char* option)
{
	_shop->getQuotationData()->selectingClothe(option);
}

void Presenter::selectingQualityClothe(const char* option)
{
	_shop->getQuotationData()->selectingQualityClothe(option);
}

void Presenter::selectingUnitaryPrice(const double unitaryPrice)
{
	_shop->getQuotationData()->selectingUnitaryPrice(unitaryPrice);
}

void Presenter::selectingTypeShirtArm(const char* option)
{
	_shop->getQuotationData()->selectingTypeShirtArm(option);
}
void Presenter::selectingTypeShirtNeck(const char* option)
{
	_shop->getQuotationData()->selectingTypeShirtNeck(option);
}

void Presenter::selectingTypePants(const char* option)
{
	_shop->getQuotationData()->selectingTypePants(option);
}

void Presenter::showQuotationResult()
{
	string result = _shop->getQuotationData()->getResultQuotation();
	_view->showText(result);
}

int Presenter::getClotheAmountFromStock()
{
	return _shop->getClotheAmountFromStock();
}