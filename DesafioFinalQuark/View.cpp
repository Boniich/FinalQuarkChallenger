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

void View::showHistoryQuotation(const list<Quotation*>& list)
{

	string comeBack = "";

	showText("COTIZADOR EXPRESS - HISTORIAL DE COTIZACIONES");
	showText(separator);
	showText("Presiona 3 para volver al menu principal");
	showText(separator);

	do
	{

		if (list.empty())
		{
			showText("\n");
			showText("INFORMACION:");
			showText("No Hay historial del vendedor! Ve a hacer una cotizacion ya!!!");
			showText("\n");
		}
		else {
			for (const auto& quotation : list)
			{
				showText("\n");
				showText(quotation->getResultQuotation());
				showText("\n");
			}
		}

		showText(separator);
		showText("Presiona 3 para volver al menu principal");
		showText(separator);
		cin >> comeBack;

		if (comeBack != "3") 
		{
			system("cls");
			showText(separator);
			showText("INFORMACION:");
			showText("Opcion invalida, vuelva a ingresar un valor");
			showText(separator);
			showText("Presiona 3 para volver al menu principal");
			showText(separator);
		}

	} while (comeBack != "3");

	system("cls");


}


void View::comeBackToMainMenu()
{
	bool comeBackToMainMenu = false;

	string option = "";

	system("cls");
	showText(separator);
	showText("INFORMACION:");
	showText(separator);
	showText("SEGURO QUE DESEA VOLVER AL MENU INICIAL? El proceso de cotizacion sera cancelado!");
	showText("1) Si");
	showText("2) No");

	do {

		cin >> option;

		if (option == "1") {
			system("cls");
			comeBackToMainMenu = true;
			showInitialMenu();
		}
		else if(option == "2")
		{
			comeBackToMainMenu = true;
		}
		else {
			system("cls");
			showText(separator);
			showText("INFORMACION:");
			showText("Opcion invalida, vuelva a ingresar un valor");
			showText(separator);
			showText("SEGURO QUE DESEA VOLVER AL MENU INICIAL? El proceso de cotizacion sera cancelado!");
			showText("1) Si");
			showText("2) No");
		}

	} while (!comeBackToMainMenu);

}

void View::showHeaderSubMenus() 
{
	system("cls");
	showText("COTIZADOR EXPRESS - COTIZAR");
	showText(separator);
	showText("Presiona 3 para volver al menu principal");
	showText(separator);
}

void View::showClotheQualityMenu()
{
	string option = "";
	bool isValidOption = false;

	showHeaderSubMenus();
	showText("PASO 3: Seleccione la calidad de la prenda: ");
	showText("1) Standard");
	showText("2) Premium");

	do
	{
		cin >> option;

		if (option == "1" || option == "2")
		{
			_presenter->selectQualityClotheForQuotation(option.c_str());
			system("cls");
			isValidOption = true;
		}
		else if (option == "3") {
			//preguntamos si quiere volver al menu principal
			//si dice que si volvemos al menu principal
			//si dice que no, volvemos a preguntar por la cotizacion

			comeBackToMainMenu();
			showHeaderSubMenus();
			showText("PASO 3: Seleccione la calidad de la prenda: ");
			showText("1) Standard");
			showText("2) Premium");

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


	} while (!isValidOption);
}

void View::showInsertAmountMenu()
{
	int amount;
	bool isNotAmountMoreThanStock = false;

	// se muestran las cantidades de unidades y se pide ingresar la cantidad de unidades a cotizar

	system("cls");
	showText("COTIZADOR EXPRESS - COTIZAR");
	showText(separator);
	showText("Presiona 0 para volver al menu principal");
	showText(separator);
	showText("INFORMACION: ");

	do
	{
		//muestra el stock disponible de la prenda seleccionada
		_presenter->showStockAvailable();
		showText("PASO 5: Ingresa la cantidad de unidades a cotizar");

		cin >> amount;
		if (amount == 0) {
			//preguntamos si quiere volver al menu principal
			//si dice que si volvemos al menu principal
			//si dice que no, volvemos a preguntar por la cotizacion

			comeBackToMainMenu();
			system("cls");
			showText("COTIZADOR EXPRESS - COTIZAR");
			showText(separator);
			showText("Presiona 0 para volver al menu principal");
			showText(separator);
			showText("INFORMACION: ");

		}else if (amount > _presenter->getClotheAmountFromStock())
		{
			showHeaderSubMenus();
			showText("INFORMACION: ");
			showText("DATO INVALIDO: La cantidad ingresada supera lo disponible en stock, por favor, ingresa un valor valido");
			showText(separator);

		}
		else {
			_presenter->insertClotheAmountForQuotation(amount);
			isNotAmountMoreThanStock = true;
			showText(separator);
			system("cls");
		}

	} while (isNotAmountMoreThanStock != true);
}

void View::showInsertUnitaryPriceMenu()
{
	double unitaryPrice;

	//solo se puede ingresar numeros

	showHeaderSubMenus();
	showText("PASO 4: Ingrese el precio unitario de la prenda a cotizar: ");

	cin >> unitaryPrice;
	_presenter->insertUnitaryPriceForQuotation(unitaryPrice);
	showText(separator);
	system("cls");
}


void View::showChoosingClotheMenu()
{

	string option = "";
	bool valid = false;
	bool isValid = false;
	bool isValidNeck = false;
	bool isTypePantsValidOption = false;

		showHeaderSubMenus();
		showText("PASO 1: Selecciona la prenda a cotizar: ");
		showText("1) Camisa");
		showText("2) Pantalon");
		showText(separator);

		do
		{
			cin >> option;
			if (option == "1" || option == "2")
			{
				_presenter->selectTypeClotheForQuotation(option.c_str());

				if (option == "1")
				{

					showHeaderSubMenus();
					showText("PASO 2.a: La camisa a cotizar, ¿Es manga corta?: ");
					showText("1) Si");
					showText("2) No");

					do {

						cin >> option;

						if (option == "1" || option == "2")
						{
							_presenter->selectTypeShirtArmForQuotation(option.c_str());


							showHeaderSubMenus();
							showText("PASO 2.b: La camisa a cotizar, ¿Es cuello mao?: ");
							showText("1) Si");
							showText("2) No");

							do
							{
								cin >> option;
								if (option == "1" || option == "2")
								{
									_presenter->selectTypeShirtNeckForQuotation(option.c_str());
									system("cls");
									isValidNeck = true;
								}
								else if (option == "3") {

									//preguntamos si quiere volver al menu principal
									//si dice que si volvemos al menu principal
									//si dice que no, volvemos a preguntar por la cotizacion

									comeBackToMainMenu();
									showHeaderSubMenus();
									showText("PASO 2.b: La camisa a cotizar, ¿Es cuello mao?: ");
									showText("1) Si");
									showText("2) No");
								}else {

									system("cls");
									showText(separator);
									showText("INFORMACION:");
									showText("Opcion invalida, vuelva a ingresar un valor");
									showText(separator);
									showText("PASO 2.a: La camisa a cotizar, ¿Es manga corta?: ");
									showText("1) Si");
									showText("2) No");
								}


							} while (!isValidNeck);


							isValid = true;

						}
						else if (option == "3") {

							//preguntamos si quiere volver al menu principal
							//si dice que si volvemos al menu principal
							//si dice que no, volvemos a preguntar por la cotizacion
							comeBackToMainMenu();
							showHeaderSubMenus();
							showText("PASO 2.a: La camisa a cotizar, ¿Es manga corta?: ");
							showText("1) Si");
							showText("2) No");


						}else {
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


				}
				else if (option == "2") {

					showHeaderSubMenus();
					showText("PASO 2: El pantalon a cotizar, ¿Es Chupin?: ");
					showText("1) Si");
					showText("2) No");

					do
					{
						cin >> option;

						if (option == "1" || option == "2")
						{
							_presenter->selectTypePantsForQuotation(option.c_str());
							system("cls");
							isTypePantsValidOption = true;
						}
						else if (option == "3") {
							//preguntamos si quiere volver al menu principal
							//si dice que si volvemos al menu principal
							//si dice que no, volvemos a preguntar por la cotizacion
							comeBackToMainMenu();
							showHeaderSubMenus();
							showText("PASO 2: El pantalon a cotizar, ¿Es Chupin?: ");
							showText("1) Si");
							showText("2) No");
						}else {
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
			}else if (option == "3")
			{
				comeBackToMainMenu();

				showHeaderSubMenus();
				showText("PASO 1: Selecciona la prenda a cotizar: ");
				showText("1) Camisa");
				showText("2) Pantalon");
				showText(separator);

			}
			else {
				showHeaderSubMenus();
				showText("INFORMACION:");
				showText("Opcion invalida, vuelva a ingresar un valor");
				showText(separator);
				showText("PASO 1: Selecciona la prenda a cotizar: ");
				showText("1) Camisa");
				showText("2) Pantalon");
			}

		} while (!valid);
}

void View::showQuotationResult()
{
	string option = "";
	bool comeBackToMainMenu = false;

	showHeaderSubMenus();
	_presenter->showQuotationResult();

	do
	{

		showText(separator);
		showText("Presiona 3 para volver al menu principal");
		showText(separator);
		cin >> option;
		if (option == "3")
		{
			system("cls");
			comeBackToMainMenu = true;
			showInitialMenu();

		}
		else {
			system("cls");
			showText(separator);
			showText("INFORMACION:");
			showText("Opcion invalida, vuelva a ingresar un valor");
			showText(separator);
		}
	} while (!comeBackToMainMenu);
}

void View::showQuotationMenu()
{

		//mostramos y vamos guardo la informacion que va seleccionando el vendedor
		showChoosingClotheMenu();

		
		//analizamos si la ropa es standar o premium
		showClotheQualityMenu();


		// se ingresa el precio unatio
		showInsertUnitaryPriceMenu();


		// se muestran las cantidades de unidades de la ropa seleccionada
		//y se pide ingresar la cantidad de unidades a cotizar
		showInsertAmountMenu();


		// hace la cotizacion con todos los datos ingresados
		_presenter->makeQuotation();


		// nos muestra el resultado de la cotizacion
		showQuotationResult();

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
		_presenter->showHistoryQuotation();
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
