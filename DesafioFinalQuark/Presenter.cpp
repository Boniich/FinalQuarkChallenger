#include "Presenter.h";
#include "IView.h";
#include "Seller.h";
#include "Quotation.h";
#include "Shop.h";
#include <iostream>;
#include <string>;

using namespace std;

Presenter::Presenter(IView* view) : _view(view), _seller(new Seller()), _shop(new Shop)
{

}

Presenter::~Presenter()
{
	delete _seller;
	delete _shop;
}


void Presenter::loadShopAndSellerData()
{
	_shop->loadShopAndSellerData();
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


void Presenter::insertClotheAmountForQuotation(const int amount)
{
	_shop->getQuotationData()->setAmount(amount);
}

void Presenter::makeQuotation()
{
	_shop->makeQuotation();
}

void Presenter::selectTypeClotheForQuotation(const char* option)
{
	_shop->getQuotationData()->selectingClothe(option);
}

void Presenter::selectQualityClotheForQuotation(const char* option)
{
	_shop->getQuotationData()->selectingQualityClothe(option);
}

void Presenter::insertUnitaryPriceForQuotation(const double unitaryPrice)
{
	_shop->getQuotationData()->selectingUnitaryPrice(unitaryPrice);
}

void Presenter::selectTypeShirtArmForQuotation(const char* option)
{
	_shop->getQuotationData()->selectingTypeShirtArm(option);
}
void Presenter::selectTypeShirtNeckForQuotation(const char* option)
{
	_shop->getQuotationData()->selectingTypeShirtNeck(option);
}

void Presenter::selectTypePantsForQuotation(const char* option)
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


void Presenter::showHistoryQuotation() {

	list<Quotation*> quotation = _shop->showHistoryQuotation();
	_view->showHistoryQuotation(quotation);
}