#pragma once

#include "IView.h";
#include <string>

using namespace std;

class Presenter;

class View : public IView
{
private:
	Presenter* _presenter;

	
 public:
	View();
	~View() override;
	void showText(const char* text) override;
	void showText(const string& text) override;
};