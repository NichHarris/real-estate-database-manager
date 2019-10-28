// Nicholas Harris - 40111093
// harris.nicholas1998@gmail.com

// Vejay Tham. - 40112236
// V-jayy21@hotmail.com

#include<stdio.h>
#include<string>
#include"HouseSale.h"

HouseSale::HouseSale() : Property() {
	year_of_built = 0;
	no_of_rooms = 0;
	price = 0;
}

HouseSale::HouseSale(std::string street_addr, std::string city_name, Client* h_client, RealEstateAgent* h_agent, Date h_list_date, int build_year ,int rooms ,int houseprice) : Property() {
	year_of_built = build_year;
	no_of_rooms = rooms;
	price = houseprice;
}

HouseSale::~HouseSale() {
	std::cout << "HouseSale destructor called" << std::endl;
}

void HouseSale::print() {
	std::cout << "House info: " << std::endl;
	std::cout << "Year built: " << year_of_built << std::endl;
	std::cout << "Number of rooms: " << no_of_rooms << std::endl;
	std::cout << "Price: " << price << std::endl;
	Property::print();
}

void HouseSale::setAge(int y) {
	year_of_built = y;
}

void HouseSale::setRooms(int r) {
	no_of_rooms = r;
}

void HouseSale::setPrice(int p) {
	price = p;
}

int HouseSale::getAge() const{
	return year_of_built;
}

int HouseSale::getRooms() const{
	return no_of_rooms;
}

int HouseSale::getPrice() const{
	return price;
}