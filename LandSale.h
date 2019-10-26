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