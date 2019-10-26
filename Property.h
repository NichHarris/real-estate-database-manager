#pragma once
#include<iostream>
#include<string>
#include"Client.h"
#include"RealEstateAgent.h"

class Property {
public:
	Property();
	Property(std::string, std::string, Client* ,RealEstateAgent*, Date);
	Property(const Property&);
	~Property();
	virtual void print();

	void setAddress(std::string);
	void setCity(std::string);
	void setSeller(Client*);
	void setBuyer(Client*);
	void setAgent(RealEstateAgent*);
	void setlistdate(Date);

	std::string getAddress() const;
	std::string getCity() const;
	Client getSeller() const;
	Client getBuyer() const;
	RealEstateAgent getAgent() const;
	Date getlistdate() const;

private:
	std::string street_address;
	std::string cityname;
	Client* seller;
	Client* buyer;
	RealEstateAgent* agent;
	Date listingdate;
};