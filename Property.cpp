#include<stdio.h>
#include<string>
#include"Property.h"

Property::Property() {
	street_address = " ";
	cityname = " ";
	seller = new Client;
	buyer = new Client;
	agent = new RealEstateAgent;
	listingdate.setDate(0, 0, 0);
}

Property::Property(std::string adr, std::string city, Client* c1, RealEstateAgent* r_agent, Date listDate) {
	street_address = adr;
	cityname = city;
	seller = new Client;
	agent = new RealEstateAgent;
	*seller = *c1;
	buyer = new Client;
	buyer = nullptr;
	*agent = *r_agent;
	listingdate = listDate;
}

Property::Property(const Property& property) {
	street_address = property.street_address;
	cityname = property.cityname;
	seller = property.seller;
	buyer = property.buyer;
	agent = property.agent;
	listingdate = property.listingdate;
}

Property::~Property() {
	std::cout << "Property destructor called" << std::endl;
	delete seller;
	delete buyer;
	delete agent;
}

void Property::print() {
	std::cout << "Street Address: " << street_address << std::endl;
	std::cout << "City Name: " << cityname << std::endl;
	std::cout << "Listing Date: ";
	listingdate.print();
	std::cout << "\nSeller info: " << std::endl;
	seller->print();
	if (buyer == nullptr) {
		// do nothing
	}
	else {
		std::cout << "\nBuyer info: " << std::endl;
		buyer->print();
	}
	agent->print();
}

void Property::setAddress(std::string adr) {
	street_address = adr;
}

void Property::setCity(std::string city) {
	cityname = city;
}

void Property::setSeller(Client* set_seller) {
	*seller = *set_seller;
}

void Property::setBuyer(Client* set_buyer){
	*buyer = *set_buyer;
}

void Property::setAgent(RealEstateAgent* set_agent) {
	*agent = *set_agent;
}

void Property::setlistdate(Date date) {
	listingdate = date;
}

std::string Property::getAddress() const {
	return street_address;
}

std::string Property::getCity() const {
	return cityname;
}

Client Property::getSeller() const {
	return *seller;
}

Client Property::getBuyer() const {
	return *buyer;
}

RealEstateAgent* Property::getAgent() const {
	return agent;
}

Date Property::getlistdate() const {
	return listingdate;
}