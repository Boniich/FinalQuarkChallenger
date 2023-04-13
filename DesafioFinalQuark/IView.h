#pragma once
#include <string>
using namespace std;

class IView
{
public:
	virtual ~IView() = default;
	
	virtual void showText(const char* text) = 0;
	virtual void showText(const string& text) = 0;
	virtual void showText(const string& text, int value) = 0;
};