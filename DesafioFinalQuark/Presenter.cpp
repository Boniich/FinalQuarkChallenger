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

void Presenter::setAmount(const int amount)
{
	_quotation->setAmount(amount);
}

void Presenter::makeQuotation(const int sellerId)
{
	_quotation->makeQuotation(sellerId);
}

void Presenter::chooseClothe(const char* option)
{
	_quotation->selectingClothe(option);
}

void Presenter::selectingQualityClothe(const char* option)
{
	_quotation->selectingQualityClothe(option);
}

void Presenter::selectingUnitaryPrice(const double unitaryPrice)
{
	_quotation->selectingUnitaryPrice(unitaryPrice);
}

void Presenter::selectingTypeShirtArm(const char* option)
{
	_quotation->selectingTypeShirtArm(option);
}
void Presenter::selectingTypeShirtNeck(const char* option)
{
	_quotation->selectingTypeShirtNeck(option);
}

void Presenter::selectingTypePants(const char* option)
{
	_quotation->selectingTypePants(option);
}

void Presenter::showQuotationResult()
{
	string result = _quotation->getResultQuotation();
	_view->showText(result);
}