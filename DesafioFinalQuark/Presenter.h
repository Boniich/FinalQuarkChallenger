

class Seller;

class Presenter
{
private:
	Seller* _seller = nullptr;

public:
	Presenter();
	~Presenter();
	void presentSeller();
};