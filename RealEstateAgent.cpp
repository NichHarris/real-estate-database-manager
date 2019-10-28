// Nicholas Harris - 40111093
// harris.nicholas1998@gmail.com

// Vejay Tham. - 40112236
// V-jayy21@hotmail.com

#include<stdint.h>
#include<string>
#include"RealEstateAgent.h"

RealEstateAgent::RealEstateAgent() : Person(){
	employment_date.setDate(0, 0, 0);
	employee_id = 0;
}

RealEstateAgent::RealEstateAgent(std::string name, std::string address, Date hire_date, int id) : Person(){
	employment_date = hire_date;
	employee_id = id;
}

RealEstateAgent::~RealEstateAgent() {
	std::cout << "RealEstateAgent destructor called" << std::endl;
}

void RealEstateAgent::print() const {
	std::cout << "\nAgent info:" << std::endl;
	Person::print();
	std::cout << "Employment Date: ";
	employment_date.print();
	std::cout << "Employee ID: " << employee_id << std::endl;
}

void RealEstateAgent::setHireDate(Date hire_Date) {
	employment_date = hire_Date;
}

void RealEstateAgent::setID(int id) {
	employee_id = id;
}

Date RealEstateAgent::getHireDate() const{
	return employment_date;
}

int RealEstateAgent::getID() const{
	return employee_id;
}
