#pragma once
#include<iostream>
#include<string>
#include"Person.h"

class RealEstateAgent : public Person {
public:
	RealEstateAgent();
	RealEstateAgent(std::string, std::string, Date, int);
	~RealEstateAgent();
	virtual void print() const;

	void setHireDate(Date);
	void setID(int);

	Date getHireDate() const;
	int getID() const;

private:
	Date employment_date;
	int employee_id;
};