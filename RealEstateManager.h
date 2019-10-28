#pragma once

#include<iostream>
#include<string>
#include"Property.h"
#include"RealEstateAgent.h"

class RealEstateManager {
private:
	static const int max_number_of_agents = 30;
	static const int listingsize = 1000;
	static const int archivesize = 2000;

	RealEstateAgent* agentRecordsArray[max_number_of_agents];
	Property* propertyListingArray[listingsize];
	Property* archiveRecordsArray[archivesize];

public:
	RealEstateManager();
	~RealEstateManager();
	bool insertAgent(RealEstateAgent&);
	bool insertProperty(Property*);

	bool propertySold(Property&, Client&);

	void findHousesCity(std::string);
	void findPropertiesAgent(RealEstateAgent&);
};