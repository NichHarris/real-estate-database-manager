#include<stdio.h>
#include<string>
#include"ApartmentSale.h"

ApartmentSale::ApartmentSale() : Property() {
	year_of_built = 0;
	no_of_rooms = 0;
	condominium_fee = 0;
	price = 0;
}

ApartmentSale::ApartmentSale(std::string street_addr, std::string city, Client* client, RealEstateAgent* agent, Date listdate, int buildyear, int rooms, int fee, int p) : Property() {
	year_of_built = buildyear;
	no_of_rooms = rooms;
	condominium_fee = fee;
	price = p;
}

ApartmentSale::~ApartmentSale() {
	std::cout << "ApartmentSale destructor called" << std::endl;
}

void ApartmentSale::print() {
	std::cout << "Apartment info: " << std::endl;
	std::cout << "Year built: " << year_of_built << std::endl;
	std::cout << "Number of rooms: " << no_of_rooms << std::endl;
	std::cout << "Condominium fee: " << condominium_fee << std::endl;
	std::cout << "Price: " << price << std::endl;
	Property::print();
}

void ApartmentSale::setAge(int y) {
	year_of_built = y;
}

void ApartmentSale::setRooms(int r) {
	no_of_rooms = r;
}

void ApartmentSale::setFee(int f) {
	condominium_fee = f;
}

void ApartmentSale::setPrice(int p) {
	price = p;
}

int ApartmentSale::getAge() const {
	return year_of_built;
}

int ApartmentSale::getRooms() const {
	return no_of_rooms;
}

int ApartmentSale::getFee() const {
	return condominium_fee;
}

int ApartmentSale::getPrice() const {
	return price;
}