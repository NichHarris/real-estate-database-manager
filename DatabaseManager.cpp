// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include"Client.h"
#include"RealEstateAgent.h"
//#include"Property.h"
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
	std::cout << "Creating land for sale using LandSale class" << std::endl;
	LandSale* land1;
	land1 = new LandSale;

	land1->setAddress(prop3->getAddress());
	land1->setCity(prop3->getCity());
	land1->setSeller(c3);
	land1->setAgent(r2);
	land1->setlistdate(prop3->getlistdate());
	land1->setArea(1500);
	land1->setPrice(550000);
	land1->print();
	std::cout << std::endl;

	// Creating house for sale using HouseSale class
	std::cout << "Creating house for sale using HouseSale class and propert2" << std::endl;
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
}

// IDEAS: 
// Set only Client, Agent, Property as pointers. House, Land and Apartment can all stay as non pointers



/*
// Creating an agent
std::cout << "Creating an agent using RealEstateAgent class" << std::endl;

RealEstateAgent r1;
r1.setName("Emy Lafond");
r1.setAddress("20 Bugle Call");
Date hiredate(12, 21, 2012);
r1.setHireDate(hiredate);
r1.setID(1337);
r1.print();

// Creating a person
std::cout << "Creating a person using Person class" << std::endl;

Person p1;
p1.setName("Theo Perring");
p1.setAddress("10 rosemount");
p1.print();
std::cout << std::endl;

// Creating a client
std::cout << "Creating a client using Client class" << std::endl;

Client c1;
c1.setName("Nick Harris");
c1.setAddress("2456 ascot park");
c1.setSIN("17750");
c1.print();
std::cout << std::endl;

// Creating client using Person
std::cout << "Creating a client using Person class" << std::endl;

Client c2;
c2.setName(p1.getName());
c2.setAddress(p1.getAddress());
c2.setSIN("90210");
c2.print();
std::cout << std::endl;

// Person 2
std::cout << "Person 2: " << std::endl;

Person p2;
p2.setName("Matthew Vallieres");
p2.setAddress("10 Yacht Club road");
p2.print();
std::cout << std::endl;

// Realestate agent 2
std::cout << "Agent 2 using Person 2" << std::endl;

RealEstateAgent r2;
Date date2(5, 26, 2014);
r2.setName(p2.getName());
r2.setAddress(p2.getAddress());
r2.setHireDate(date2);
r2.setID(1738);
r2.print();
std::cout << std::endl;

// Creating Properties using Property class
std::cout << "Creating properties using Property class" << std::endl << std::endl;

Property prop1;
prop1.setAddress(c1.getAddress());
prop1.setCity("St-Lazare");
prop1.setSeller(&c1);
prop1.setAgent(&r1);
Date list_date(10, 26, 2019);
prop1.setlistdate(list_date);
prop1.print();
std::cout << std::endl;

// Creating property2 using Property Class

Property prop2;
prop2.setAddress(c2.getAddress());
prop2.setCity("Westmount");
prop2.setSeller(&c2);
prop2.setAgent(&r2);
Date list_date2(5, 21, 2018);
prop2.setlistdate(list_date2);
prop2.print();
std::cout << std::endl;

// Property 3
Date list_date3(10, 11, 2019);
Client c3;
c3.setAddress("9120 Venne");
c3.setName("Olivia Valcourt");
c3.setSIN("65845");
Property prop3(c3.getAddress(), "Pierrefonds", &c3, &r2, list_date3);

// Creating land for sale using LandSale class
std::cout << "Creating land for sale using LandSale class" << std::endl;
LandSale land1;

land1.setAddress(prop3.getAddress());
land1.setCity(prop3.getCity());
land1.setSeller(&c3);
land1.setAgent(&r2);
land1.setlistdate(prop3.getlistdate());
land1.setArea(1500);
land1.setPrice(550000);
land1.print();
std::cout << std::endl;

// Creating house for sale using HouseSale class
std::cout << "Creating house for sale using HouseSale class and propert2" << std::endl;
HouseSale house1;

house1.setAddress(prop2.getAddress());
house1.setCity(prop2.getCity());
house1.setSeller(&c2);
house1.setAgent(&r2);
house1.setlistdate(prop2.getlistdate());
house1.setAge(1965);
house1.setRooms(8);
house1.setPrice(1200000);
house1.print();
*/

