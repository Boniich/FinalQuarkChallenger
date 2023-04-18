
#include <list>
#include <string>
#include "Quotation.h";


class IView;
class Seller;
class Shop;
class Quotation;


class Presenter
{
private:
	
	IView* _view = nullptr;
	Seller* _seller = nullptr;
	Shop* _shop = nullptr;

public:
	
	explicit Presenter(IView* view);
	~Presenter();
	void showInfoSeller();
	void showInfoShop();

	void loadStockClothes();
	void showStockAvailable();
	int getClotheAmountFromStock();

	//quotation methos
	void selectTypeClotheForQuotation(const char* option);

	void selectQualityClotheForQuotation(const char* option);
	void insertUnitaryPriceForQuotation(const double unitaryPrice);
	void insertClotheAmountForQuotation(const int amount);

	void selectTypeShirtArmForQuotation(const char* option);
	void selectTypeShirtNeckForQuotation(const char* option);

	void selectTypePantsForQuotation(const char* option);
	void makeQuotation();

	void showQuotationResult();

	void showHistoryQuotation();
	
	
};