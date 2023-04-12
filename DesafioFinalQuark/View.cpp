#include "View.h";
#include "Presenter.h";
#include <iostream>

View::View()
{
	//inicia el programa (borrar funcion despues)
	_presenter = new Presenter();
	//delete later
	_presenter->presentSeller();
	showViewWorking();
}

View::~View()
{
	delete _presenter;
};

void View::showViewWorking() {

	std::cout << working << std::endl;
}