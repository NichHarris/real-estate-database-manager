// Nicholas Harris - 40111093
// harris.nicholas1998@gmail.com

// Vejay Tham. - 40112236
// V-jayy21@hotmail.com

#include<stdio.h>
#include"Date.h"

Date::Date() {
	month = 0;
	day = 0;
	year = 0;
}

Date::Date(int m, int d, int y) {
	month = m;
	day = d;
	year = y;
}

void Date::print() const{
	std::cout << month << "/" << day << "/" << year << std::endl;
}


void Date::setDate(int m, int d, int y) {
	month = (m > 0 && m <= 12 ? m : 0);
	day = (d > 0 && d <= 30 ? d : 0);
	year = (y > 0 ? y : 0);
}

void Date::setMonth(int m) {
	month = (m > 0 && m <= 12 ? m : 0);

	if (month == 0)
		std::cout << "Invalid month";
}

void Date::setDay(int d) {
	day = (d > 0 && d <= 30 ? d : 0);

	if (day == 0)
		std::cout << "Invalid day";
}

void Date::setYear(int y) {
	year = (y > 0 ? y : 0);

	if (year == 0)
		std::cout << "Invalid year";
}

int Date::getMonth() const{
	return month;
}

int Date::getDay() const{
	return day;
}

int Date::getYear() const{
	return year;
}
