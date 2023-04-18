#pragma once
#include <string>
#include <list>
using namespace std;

class Quotation;

class IView
{
public:
	virtual ~IView() = default;
	
	virtual void showText(const char* text) = 0;
	virtual void showText(const string& text) = 0;
	virtual void showHistoryQuotation(const list<Quotation*>& list) = 0;
};