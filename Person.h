#pragma once
#include<iostream>
#include<string>
#include "Date.h"

class Person {
public:
	Person();
	Person(std::string, std::string, Date);
	~Person();
	virtual void print() const;

	void setName(std::string);
	void setAddress(std::string);
	void setDate(Date);

	std::string getName() const;
	std::string getAddress() const;
	void getDate() const;

private:
	std::string name;
	std::string address;
	Date date;
};