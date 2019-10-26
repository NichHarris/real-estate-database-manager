#pragma once

#include<iostream>
#include<string>
#include"Property.h"

class HouseSale : public Property {
public:
	HouseSale();
	HouseSale(std::string, std::string, Client*, RealEstateAgent*, Date, int, int, int);
	~HouseSale();
	virtual void print();

	void setAge(int);
	void setRooms(int);
	void setPrice(int);

	int getAge() const;
	int getRooms() const;
	int getPrice() const;
	

private:
	int year_of_built;
	int no_of_rooms;
	int price;
};