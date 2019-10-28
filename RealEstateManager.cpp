#include<stdio.h>
#include<string>
#include"RealEstateManager.h"

class RealEstateAgent;
class Property;

RealEstateManager::RealEstateManager() {
	for (int i = 0; i < max_number_of_agents; i++) {
		agentRecordsArray[i] = new RealEstateAgent;
		agentRecordsArray[i] = nullptr;
	}
	for (int j = 0; j < listingsize; j++) {
		propertyListingArray[j] = new Property;
		propertyListingArray[j] = nullptr;
	}
	for (int k = 0; k < archivesize; k++) {
		archiveRecordsArray[k] = new Property;
		archiveRecordsArray[k] = nullptr;
	}
}

RealEstateManager::~RealEstateManager() {
	std::cout << "RealEstateManager destructor called" << std::endl;
}

bool RealEstateManager::insertAgent(RealEstateAgent& agent) {
	for (int i = 0; i < max_number_of_agents; i++) {
		if (agentRecordsArray[i] == &agent){
			std::cout << "Agent already exists, exiting.\n\n";
			return 0;
		}
		if (agentRecordsArray[i] == nullptr) {
			agentRecordsArray[i] = &agent;
			return 1;
		}
	}
	std::cout << "Unable to add real-estate agent, max exceeded" << std::endl;
	return 0;
}

bool RealEstateManager::insertProperty(Property* property) {
	for (int i = 0; i < listingsize; i++) {
		if (propertyListingArray[i] == property) {
			std::cout << "Property already exists, exiting.\n\n";
			return 0;
		}
		if (propertyListingArray[i] == nullptr) {
			propertyListingArray[i] = property;
			return 1;
		}
	}
	std::cout << "Unable to add property, max exceeded" << std::endl;
	return 0;
}

bool RealEstateManager::propertySold(Property& sold_property, Client& buyer) {

	for (int i = 0; i < archivesize; i++) {
		if (archiveRecordsArray[i] == nullptr) {
			archiveRecordsArray[i] = &sold_property;
			sold_property.setBuyer(&buyer);
			for (int j = 0; j < listingsize; j++) {
				if (propertyListingArray[j] == &sold_property) {
					propertyListingArray[j] = nullptr;

					for (int k = j; k < listingsize-1; k++) {
						propertyListingArray[k] = propertyListingArray[k + 1];
					}
					std::cout << "\narchiveRecordsArray: " << std::endl;
					archiveRecordsArray[i]->print();
					break;
				}
			}
			return 1;
		}
	}
	std::cout << "Unable to add buyer, archive is full" << std::endl;
	return 0;
}

void RealEstateManager::findHousesCity(std::string cityname) {
	for (int i = 0; i < listingsize; i++) {
		if (propertyListingArray[i]->getCity() == cityname) {
			std::cout << "Listing " << i + 1 << ":" << std::endl;
			propertyListingArray[i]->print();
			std::cout << std::endl;
		}
	}
}

void RealEstateManager::findPropertiesAgent(RealEstateAgent& agent) {
	for (int i = 0; i < max_number_of_agents; i++) {
		if (agentRecordsArray[i] == &agent) {
			std::cout << "Agent Name: " << agent.getName() << std::endl;
			int count = 0;
			for (int j = 0; j < listingsize; j++) {
				if (propertyListingArray[j]->getAgent()->getName() == agent.getName()) {
					std::cout << "\nProperty " << ++count << ":" << std::endl;
					propertyListingArray[j]->print();
				}
			}
		}
	}
	std::cout << "End of property listings for agent " << agent.getName() << std::endl;
}
