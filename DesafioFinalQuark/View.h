#pragma once

#include "IView.h";
#include <string>

using namespace std;

class Presenter;

class View : public IView
{
private:
	Presenter* _presenter;
	void showInitialMenu();
	void optionSelected(const char* option, bool& exit);

	
 public:
	View();
	~View() override;
	void showText(const char* text) override;
	void showText(const string& text) override;
	void showHistoryQuotation(const list<Quotation*>& list) override;
	void showQuotationMenu();
	void showHeaderSubMenus();
	void showChoosingClotheMenu();
	void showClotheQualityMenu();
	void showInsertAmountMenu();
	void showInsertUnitaryPriceMenu();
	void comeBackToMainMenu();
	void showQuotationResult();

};