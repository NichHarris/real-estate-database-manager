// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include"Client.h"
#include"RealEstateAgent.h"
#include"RealEstateManager.h"
#include"LandSale.h"
#include"HouseSale.h"
#include"ApartmentSale.h"

int main()
{
	// Creating an agent
	std::cout << "Creating an agent using RealEstateAgent class" << std::endl;

	RealEstateAgent* r1;
	r1 = new RealEstateAgent;

	r1->setName("Emy Lafond");
	r1->setAddress("20 Bugle Call");
	Date hiredate(12, 21, 2012);
	r1->setHireDate(hiredate);
	r1->setID(1337);
	r1->print();

	// Creating a person
	std::cout << "Creating a person using Person class" << std::endl;

	Person* p1;
	p1 = new Person;
	p1->setName("Theo Perring");
	p1->setAddress("10 rosemount");
	p1->print();
	std::cout<<std::endl;

	// Creating a client
	std::cout << "Creating a client using Client class" << std::endl;

	Client* c1;
	c1 = new Client;
	c1->setName("Nick Harris");
	c1->setAddress("2456 ascot park");
	c1->setSIN("17750");
	c1->print();
	std::cout << std::endl;

	// Creating client using Person
	std::cout << "Creating a client using Person class" << std::endl;
	
	Client* c2;
	c2 = new Client;
	c2->setName(p1->getName());
	c2->setAddress(p1->getAddress());
	c2->setSIN("90210");
	c2->print();
	std::cout << std::endl;

	// Person 2
	std::cout << "Person 2: " << std::endl;

	Person* p2;
	Date emptydate;
	p2 = new Person("Matthew Vallieres", "10 Yacht Club road", emptydate);
	p2->print();
	std::cout << std::endl;

	// Realestate agent 2
	std::cout << "Agent 2 using Person 2" << std::endl;

	Date date2(5, 26, 2014);
	RealEstateAgent* r2;
	r2 = new RealEstateAgent;
	r2->setName(p2->getName());
	r2->setAddress(p2->getAddress());
	r2->setDate(date2);
	r2->setID(1738);
	r2->print();
	std::cout << std::endl;

	// Creating Properties using Property class
	std::cout << "Creating properties using Property class" << std::endl << std::endl;

	Property* prop1;
	prop1 = new Property;
	prop1->setAddress(c1->getAddress());
	prop1->setCity("St-Lazare");
	prop1->setSeller(c1);
	prop1->setAgent(r1);
	Date list_date(10, 26, 2019);
	prop1->setlistdate(list_date);
	prop1->print();
	std::cout << std::endl;

	// Creating property2 using Property Class

	Property* prop2;
	Date list_date2(5, 21, 2018);
	std::string client2addr;
	client2addr = c2->getAddress();
	prop2 = new Property(client2addr, "Westmount", c2, r2, list_date2);
	prop2->print();
	std::cout << std::endl;

	// Property 3
	Date list_date3(10, 11, 2019);
	Client* c3;
	c3 = new Client;
	c3->setAddress("9120 Venne");
	c3->setName("Olivia Valcourt");
	c3->setSIN("65845");
	Property* prop3;
	prop3 = new Property;
	prop3->setAddress(c3->getAddress());
	prop3->setCity("Pierrefonds");
	prop3->setSeller(c3);
	prop3->setAgent(r2);
	prop3->setlistdate(list_date3);

	// Creating land for sale using LandSale class
	std::cout << "Creating land for sale using LandSale class using property3" << std::endl;

	LandSale land1;
	land1.setAddress(prop3->getAddress());
	land1.setCity(prop3->getCity());
	land1.setSeller(c3);
	land1.setAgent(r2);
	land1.setlistdate(prop3->getlistdate());
	land1.setArea(1500);
	land1.setPrice(550000);
	land1.print();
	std::cout << std::endl;
	
	// Creating house for sale using HouseSale class
	std::cout << "Creating house for sale using HouseSale class and property2" << std::endl;
	HouseSale house1;

	house1.setAddress(prop2->getAddress());
	house1.setCity(prop2->getCity());
	house1.setSeller(c2);
	house1.setAgent(r2);
	house1.setlistdate(prop2->getlistdate());
	house1.setAge(1965);
	house1.setRooms(8);
	house1.setPrice(1200000);
	house1.print();
	std::cout << std::endl;

	// Creating an apartment using ApartmentSale class
	std::cout << "Creating an apartment using ApartmentSale class and property1" << std::endl;

	ApartmentSale apart1;
	apart1.setAddress(prop1->getAddress());
	apart1.setCity(prop1->getCity());
	apart1.setSeller(c1);
	apart1.setAgent(r1);
	apart1.setlistdate(prop1->getlistdate());
	apart1.setAge(1998);
	apart1.setRooms(4);
	apart1.setPrice(110000);
	apart1.setFee(1100);
	apart1.print();
	std::cout << std::endl;


	// Testing RealEstateManager

	//Testing boolinsertAgent

	std::cout << "Adding r1 and r2 to agentRecordsArray using insertAgent function" << std::endl;
	
	RealEstateManager manager;

	if (manager.insertAgent(*r1)) {
		std::cout << "Agent: " << r1->getName() << " succesfully added." << std::endl;
	}
	if (manager.insertAgent(*r2)) {
		std::cout << "Agent: " << r2->getName() << " succesfully added." << std::endl;
	}
	
	std::cout << "\nTesting adding same agent twice.\n";
	manager.insertAgent(*r1);

	std::cout << "\nTesting adding too many agents (using empty agents)\n";
	RealEstateAgent* agents = new RealEstateAgent[30];
	for (int i = 0; i < 30; i++) {
		if (manager.insertAgent(agents[i])) {
			std::cout << "Added test agent " << i+1 << std::endl;
		}
	}

	// Inserting properties into propertyListingArray

	std::cout << "\nAddding prop1, prop2, and prop3, to propertyListingArray using insertPorperty function\n";

	if (manager.insertProperty(*prop1)) {
		std::cout << "Property at address: " << prop1->getAddress() << " succesfully added to listing.\n";
	}
	if (manager.insertProperty(*prop2)) {
		std::cout << "Property at address: " << prop2->getAddress() << " succesfully added to lsiting.\n";
	}
	if (manager.insertProperty(*prop3)) {
		std::cout << "Property at address: " << prop3->getAddress() << " succesfully added listing.\n\n";
	}

	std::cout << "Testing adding the same property twice." << std::endl;
	manager.insertProperty(*prop1);

	std::cout << "Testing adding too many properties" << std::endl;
	Property* properties = new Property[1000];

	for (int i = 0; i < 1000; i++) {
		manager.insertProperty(properties[i]);
	}

	// propertySold function from RealEstateManager class

	std::cout << "Testing propertySold function from RealEstateManager class\n\n";

	manager.propertySold(*prop1, *c1);
	std::cout << "Buyer of property at address " << prop1->getAddress() << ": ";
	std::cout << std::endl;
}