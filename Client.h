#pragma once
#include<iostream>
#include<string>
#include "Person.h"

class Client : public Person {
public:
	Client();
	Client(std::string, std::string, std::string);
	Client(const Client&);
	~Client();
	virtual void print();

	void setSIN(std::string);

	std::string getSIN() const;

private:
	std::string socialinsurancenumber;
};