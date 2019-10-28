// Nicholas Harris - 40111093
// harris.nicholas1998@gmail.com

// Vejay Tham. - 40112236
// V-jayy21@hotmail.com

#pragma once
#include"Property.h"
#include<iostream>
#include<string>

class LandSale : public Property {
public:
	LandSale();
	LandSale(std::string, std::string, Client*, RealEstateAgent*, Date, double, int);
	~LandSale();
	
	virtual void print();

	void setArea(double);
	void setPrice(int);

	double getArea();
	int getPrice();

private:
	double area;
	int price;
};