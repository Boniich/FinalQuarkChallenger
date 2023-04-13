#include "Presenter.h";
#include "IView.h";
#include "Seller.h";
#include <iostream>;

using namespace std;

Presenter::Presenter(IView* view) : _view(view), _seller(new Seller())
{

}

Presenter::~Presenter()
{
	delete _seller;
}

void Presenter::presentSeller() {

	string sellerName = _seller->showSellerFullName();
	_view->showText(sellerName);
}