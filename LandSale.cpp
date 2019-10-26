#include<stdio.h>
#include<string>
#include"LandSale.h"

LandSale::LandSale() : Property() {
	area = 0;
	price = 0;
}

LandSale::LandSale(std::string street_addr, std::string city, Client* land_seller, RealEstateAgent* a1, Date listDate, double m_area, int m_price) : Property() {
	area = m_area;
	price = m_price;
}

LandSale::~LandSale() {
	std::cout << "LandSale destructor called" << std::endl;
}

void LandSale::print() {
	std::cout << "Land info: " << std::endl;
	std::cout << "Land Area: " << area << std::endl;
	std::cout << "Land Price: " << price << std::endl;
	Property::print();
}

void LandSale::setArea(double A) {
	area = A;
}

void LandSale::setPrice(int p) {
	price = p;
}

double LandSale::getArea() {
	return area;
}

int LandSale::getPrice() {
	return price;
}
