

class IView;
class Seller;


class Presenter
{
private:
	
	IView* _view = nullptr;
	Seller* _seller = nullptr;

public:
	
	explicit Presenter(IView* view);
	~Presenter();
	void presentSeller();
	
};