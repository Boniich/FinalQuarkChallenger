#include "View.h";
#include "Presenter.h";
#include <iostream>

using namespace std;

View::View()
{
	_presenter = new Presenter(this);
	//delete later
	_presenter->presentSeller();
}

View::~View()
{
	delete _presenter;
};


void View::showText(const char* text) {

	cout << text << std::endl;
}

void View::showText(const string& text) {

	cout << text << std::endl;
}

