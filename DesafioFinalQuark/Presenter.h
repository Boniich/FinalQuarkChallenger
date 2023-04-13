

class IView;
class Seller;
class Shop;


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
	void makeQuotation();

	
};