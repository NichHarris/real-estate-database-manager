#include<stdio.h>
#include<string>
#include"RealEstateManager.h"

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
	std::cout << "Unable to add realestate agent, max exceeded" << std::endl;
	return 0;
}

bool RealEstateManager::insertProperty(Property& property) {
	for (int i = 0; i < listingsize; i++) {
		if (propertyListingArray[i] == &property) {
			std::cout << "Property already exists, exiting.\n\n";
			return 0;
		}
		if (propertyListingArray[i] == nullptr) {
			propertyListingArray[i] = &property;
			return 1;
		}
	}
	std::cout << "Unable to add property, max exceeded" << std::endl;
	return 0;
}

bool RealEstateManager::propertySold(Property& sold_property, Client& buyer) {
	sold_property.setBuyer(&buyer);
	for (int i = 0; i < archivesize; i++) {
		if (archiveRecordsArray[i] == nullptr) {
			archiveRecordsArray[i] = &sold_property;

			for (int j = 0; j < listingsize; j++) {
				if (propertyListingArray[j] == &sold_property) {
					propertyListingArray[j] = nullptr;

					for (int k = j; k < listingsize-1; k++) {
						propertyListingArray[k] = propertyListingArray[k + 1];
					}
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
			propertyListingArray[i]->print();
		}
	}
}

/*void RealEstateManager::findPropertiesAgent(const RealEstateAgent& agent) {
	for (int i = 0; i < listingsize; i++) {
		if (propertyListingArray[i]->getAgent() == &agent) {
			propertyListingArray[i]->print();
		}
	}
}
*/

