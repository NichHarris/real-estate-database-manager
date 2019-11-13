// Nicholas Harris - 40111093
// harris.nicholas1998@gmail.com

// Vejay Tham. - 40112236
// V-jayy21@hotmail.com

#pragma once
#include<iostream>
#include<string>
#include"Property.h"

class ApartmentSale : public Property {
public:
	ApartmentSale();
	ApartmentSale(std::string, std::string, Client*, RealEstateAgent*, Date, int, int, int, int);
	~ApartmentSale();
	virtual void print();

	void setAge(int);
	void setRooms(int);
	void setFee(int);
	void setPrice(int);

	int getAge() const;
	int getRooms() const;
	int getFee() const;
	int getPrice() const;

private:
	int year_of_built;
	int no_of_rooms;
	int condominium_fee;
	int price;
};