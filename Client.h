// Nicholas Harris - 40111093
// harris.nicholas1998@gmail.com

// Vejay Tham. - 40112236
// V-jayy21@hotmail.com

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