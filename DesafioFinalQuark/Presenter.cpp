#include "Presenter.h";
#include "Seller.h";
#include <iostream>;

using namespace std;

//pregunta: que significa los dos puntos en un constructor
Presenter::Presenter() : _seller(new Seller())
{

}

Presenter::~Presenter()
{

}

void Presenter::presentSeller() {

	string sellerName = _seller->showSellerFullName();
	cout << sellerName << std::endl;
	//we need the IView method
}