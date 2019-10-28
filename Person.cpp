// Nicholas Harris - 40111093
// harris.nicholas1998@gmail.com

// Vejay Tham. - 40112236
// V-jayy21@hotmail.com

#include<stdio.h>
#include<string>
#include"Person.h"

Person::Person() {
	name = " ";
	address = " ";
}

Person::Person(std::string n, std::string adr, Date date) {
	name = n;
	address = adr;
}

Person::~Person() {
	std::cout << "Person destructor called" << std::endl;
}

void Person::print() const{
	std::cout << "Name: " << name << std::endl;
	std::cout << "Address: " << address << std::endl;
}

void Person::setName(std::string n) {
	name = n;
}

void Person::setAddress(std::string adr) {
	address = adr;
}

void Person::setDate(Date date) {
	date.setDay(date.getDay());
	date.setMonth(date.getMonth());
	date.setYear(date.getYear());
}

std::string Person::getName() const{
	return name;
}

std::string Person::getAddress() const{
	return address;
}