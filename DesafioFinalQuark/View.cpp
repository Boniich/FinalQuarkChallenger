#include "View.h";
#include "Presenter.h";
#include <iostream>

using namespace std;

const string separator = "---------------------------------------------";

View::View()
{
	_presenter = new Presenter(this);
	_presenter->loadStockClothes();
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

void View::showQuotationMenu()
{
	string option = "";
	double unitaryPrice;
	int amount;
	bool isNotAmountMoreThanStock = false;

	do
	{
		showText("COTIZADOR EXPRESS - COTIZAR");
		showText(separator);
		showText("Presiona 3 para volver al menu principal");
		showText(separator);
		showText("PASO 1: Selecciona la prenda a cotizar: ");
		showText("1) Camisa");
		showText("2) Pantalon");
		showText(separator);

		cin >> option;
		_presenter->chooseClothe(option.c_str());

		if (option == "1")
		{

			system("cls");
			showText("COTIZADOR EXPRESS - COTIZAR");
			showText(separator);
			showText("Presiona 3 para volver al menu principal");
			showText(separator);
			showText("PASO 2.a: La camisa a cotizar, ¿Es manga corta?: ");
			showText("1) Si");
			showText("2) No");
			cin >> option;
			_presenter->selectingTypeShirtArm(option.c_str());
			system("cls");


			system("cls");
			showText("COTIZADOR EXPRESS - COTIZAR");
			showText(separator);
			showText("Presiona 3 para volver al menu principal");
			showText(separator);
			showText("PASO 2.b: La camisa a cotizar, ¿Es cuello mao?: ");
			showText("1) Si");
			showText("2) No");
			cin >> option;
			_presenter->selectingTypeShirtNeck(option.c_str());
			system("cls");


		}
		else if (option == "2") {

			system("cls");
			showText("COTIZADOR EXPRESS - COTIZAR");
			showText(separator);
			showText("Presiona 3 para volver al menu principal");
			showText(separator);
			showText("PASO 2: El pantalon a cotizar, ¿Es Chupin?: ");
			showText("1) Si");
			showText("2) No");
			cin >> option;
			_presenter->selectingTypePants(option.c_str());
			system("cls");
		}
		else {
			showText("Opcion no valida");
		}
		//analizamos si la ropa es standar o premium

		showText("COTIZADOR EXPRESS - COTIZAR");
		showText(separator);
		showText("Presiona 3 para volver al menu principal");
		showText(separator);
		showText("PASO 3: Seleccione la calidad de la prenda: ");
		showText("1) Standard");
		showText("2) Premium");

		cin >> option;
		_presenter->selectingQualityClothe(option.c_str());
		system("cls");


		// se ingresa el precio unatio

		showText("COTIZADOR EXPRESS - COTIZAR");
		showText(separator);
		showText("Presiona 3 para volver al menu principal");
		showText(separator);
		showText("PASO 4: Ingrese el precio unitario de la prenda a cotizar: ");

		cin >> unitaryPrice;
		_presenter->selectingUnitaryPrice(unitaryPrice);
		showText(separator);
		system("cls");

		// se muestran las cantidades de unidades y se pide ingresar la cantidad de unidades a cotizar

		showText("COTIZADOR EXPRESS - COTIZAR");
		showText(separator);
		showText("Presiona 3 para volver al menu principal");
		showText(separator);
		showText("INFORMACION: ");
		//se debe buscar la forma de mostrar un numero dentro de una variable

		do
		{
			_presenter->showStockAvailable();
			showText("PASO 5: Ingresa la cantidad de unidades a cotizar");

			cin >> amount;

			if (amount > _presenter->getClotheAmountFromStock())
			{
				system("cls");
				showText("COTIZADOR EXPRESS - COTIZAR");
				showText(separator);
				showText("Presiona 3 para volver al menu principal");
				showText(separator);
				showText("INFORMACION: ");
				showText("DATO INVALIDO: La cantidad ingresada supera lo disponible en stock, por favor, ingresa un valor valido");
				showText(separator);

			}else {
				_presenter->setAmount(amount);
				isNotAmountMoreThanStock = true;
				showText(separator);
				system("cls");
			}

		} while (isNotAmountMoreThanStock != true);

		// mostramos el resultado de la cotizacion
		_presenter->makeQuotation();
		showText("COTIZADOR EXPRESS - COTIZAR");
		showText(separator);
		showText("Presiona 3 para volver al menu principal");
		showText(separator);

		_presenter->showQuotationResult();

		showText(separator);
		showText("Presiona 3 para volver al menu principal");
		showText(separator);
		cin >> option;
		system("cls");

	} while (option != "3");

	
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
	else if (str_option == "2")
	{
		showQuotationMenu();

	}else {
		showText("Cualquier opcion");
	}
}
