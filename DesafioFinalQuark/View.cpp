#include "View.h";
#include "Presenter.h";
#include <ctype.h>
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

		_presenter->showHistory();

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
	bool valid = false;
	bool isValid = false;
	bool isValidNeck = false;
	bool isTypePantsValidOption = false;
	bool isQualityClotheValidOption = false;

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

		do
		{
			cin >> option;
			if (option == "1" || option == "2")
			{
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
					
					do {

						cin >> option;

						if (option == "1" || option == "2")
						{
							_presenter->selectingTypeShirtArm(option.c_str());


							system("cls");
							showText("COTIZADOR EXPRESS - COTIZAR");
							showText(separator);
							showText("Presiona 3 para volver al menu principal");
							showText(separator);
							showText("PASO 2.b: La camisa a cotizar, ¿Es cuello mao?: ");
							showText("1) Si");
							showText("2) No");

							do 
							{
								cin >> option;
								if (option == "1" || option == "2")
								{
									_presenter->selectingTypeShirtNeck(option.c_str());
									system("cls");
									isValidNeck = true;
								}
								else {

									system("cls");
									showText(separator);
									showText("INFORMACION:");
									showText("Opcion invalida, vuelva a ingresar un valor");
									showText(separator);
									showText("PASO 2.a: La camisa a cotizar, ¿Es manga corta?: ");
									showText("1) Si");
									showText("2) No");
								}


							} 
							while (!isValidNeck);


							isValid = true;

						}
						else {
							system("cls");
							showText(separator);
							showText("INFORMACION:");
							showText("Opcion invalida, vuelva a ingresar un valor");
							showText(separator);
							showText("PASO 2.a: La camisa a cotizar, ¿Es manga corta?: ");
							showText("1) Si");
							showText("2) No");
						}


					} while (!isValid);


				}else if (option == "2") {

					system("cls");
					showText("COTIZADOR EXPRESS - COTIZAR");
					showText(separator);
					showText("Presiona 3 para volver al menu principal");
					showText(separator);
					showText("PASO 2: El pantalon a cotizar, ¿Es Chupin?: ");
					showText("1) Si");
					showText("2) No");

					do 
					{
						cin >> option;

						if (option == "1" || option == "2")
						{
							_presenter->selectingTypePants(option.c_str());
							system("cls");
							isTypePantsValidOption = true;
						}
						else {
							system("cls");
							showText(separator);
							showText("INFORMACION:");
							showText("Opcion invalida, vuelva a ingresar un valor");
							showText(separator);
							showText("PASO 2: El pantalon a cotizar, ¿Es Chupin?: ");
							showText("1) Si");
							showText("2) No");
						}

					} while (!isTypePantsValidOption);

					isValid = true;

				}
				valid = true;
			}
			else {
				system("cls");
				showText(separator);
				showText("INFORMACION:");
				showText("Opcion invalida, vuelva a ingresar un valor");
				showText(separator);
				showText("PASO 1: Selecciona la prenda a cotizar: ");
				showText("1) Camisa");
				showText("2) Pantalon");
			}

		} while (!valid);


		
		//analizamos si la ropa es standar o premium

		showText("COTIZADOR EXPRESS - COTIZAR");
		showText(separator);
		showText("Presiona 3 para volver al menu principal");
		showText(separator);
		showText("PASO 3: Seleccione la calidad de la prenda: ");
		showText("1) Standard");
		showText("2) Premium");

		do 
		{
			cin >> option;

			if (option == "1" || option == "2")
			{
				_presenter->selectingQualityClothe(option.c_str());
				system("cls");
				isQualityClotheValidOption = true;
			}
			else {
				system("cls");
				showText(separator);
				showText("INFORMACION:");
				showText("Opcion invalida, vuelva a ingresar un valor");
				showText(separator);
				showText("PASO 3: Seleccione la calidad de la prenda: ");
				showText("1) Standard");
				showText("2) Premium");
			}


		} while (!isQualityClotheValidOption);




		// se ingresa el precio unatio
		//solo se puede ingresar numeros

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
	bool exitCondition = false;

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
			optionSelected(option.c_str(), exitCondition);
	} while (!exitCondition);


}

void View::optionSelected(const char* option, bool& exitCondition)
{
	auto str_option = string(option);

	if (str_option == "1")
	{
		showHistorySeller();
		std::cin.get();
		exitCondition = false;

	}
	else if (str_option == "2")
	{
		showQuotationMenu();
		exitCondition = false;

	}
	else if (str_option == "3")
	{
		cout.flush();
		exit(EXIT_SUCCESS);

	}else {
		system("cls");
		showText(separator);
		showText("INFORMACION:");
		showText("Opcion invalida, vuelva a ingresar un valor");
		showText(separator);
		exitCondition = false;
	}
}
