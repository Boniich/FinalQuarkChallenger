#pragma once

#include <string>

using namespace std;

class Presenter;

class View 
{
private:
	Presenter* _presenter;
	string working = "View class is working";
	
 public:
	View();
	~View();
	void showViewWorking();
};