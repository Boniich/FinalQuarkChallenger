
#include <string>;

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
	Quotation* _quotation = nullptr;

public:
	
	explicit Presenter(IView* view);
	~Presenter();
	void showInfoSeller();
	void showInfoShop();

	//quotation methos
	void chooseClothe(const char* option);
	void selectingQualityClothe(const char* option);
	void selectingUnitaryPrice(const double unitaryPrice);
	void setAmount(const int amount);

	void selectingTypeShirtArm(const char* option);
	void selectingTypeShirtNeck(const char* option);

	void selectingTypePants(const char* option);
	void makeQuotation(const int sellerId);

	void showQuotationResult();
	

	
};