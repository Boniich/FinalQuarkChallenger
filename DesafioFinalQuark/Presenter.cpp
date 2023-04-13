#include "Presenter.h";
#include "IView.h";
#include "Seller.h";
#include "Shop.h";
#include <iostream>;

using namespace std;

Presenter::Presenter(IView* view) : _view(view), _seller(new Seller()), _shop(new Shop)
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

void Presenter::makeQuotation()
{

}
