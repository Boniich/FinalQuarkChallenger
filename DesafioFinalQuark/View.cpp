#include "View.h";
#include "Presenter.h";
#include <iostream>

using namespace std;

const string separator = "---------------------------------------------";

View::View()
{
	_presenter = new Presenter(this);
	showInitialMenu();
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

void View::showText(const string& text, int value) {

	cout << text << " " << value << std::endl;
}


void View::showHistorySeller() 
{
	string comeBack = "";
	do
	{
		showText("COTIZADOR EXPRESS - HISTORIAL DE COTIZACIONES");
		showText(separator);
		showText("Presiona 3 para volver al menu principal");
		showText(separator);

		for (int e = 0; e < 2; e++) {
			showText("Numero de identifiacion: ", e);
			showText("Fecha y hora de la cotizacion: ", e);
			showText("Codigo del vendedor: ", e);
			showText("Prenda Cotizada: ", e);
			showText("Precio Unitario: ", e);
			showText("Cantidades de unidades cotizadas: ", e);
			showText("precio final: ", e);
			
			showText("\n");
		}

		showText(separator);
		showText("Presiona 3 para volver al menu principal");
		showText(separator);
		cin >> comeBack;
	} while (comeBack != "3");

	system("cls");

}

void View::showInitialMenu() 
{
	string option;
	bool exit = false;

	do
	{
		showText("COTIZADOR EXPRESS - MENU PRINCIPAL");
		showText(separator);
		_presenter->showInfoShop();
		showText(separator);
		_presenter->showInfoSeller();
		showText(separator);
		showText("\n");

		showText("SELECCIONE UNA OPCION DEL MENU");
		showText("1- Historial de cotizaciones");
		showText("2- Realizar cotizacion");
		showText("3- Salir");
		cin >> option;
		system("cls");
		optionSelected(option.c_str(), exit);
	} while (!exit);


}

void View::optionSelected(const char* option, bool& exit)
{
	auto str_option = string(option);

	if (str_option == "1")
	{
		showHistorySeller();
		std::cin.get();
		exit = false;
	}
	else {
		showText("Cualquier opcion");
	}
}
