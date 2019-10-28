// Nicholas Harris - 40111093
// harris.nicholas1998@gmail.com

// Vejay Tham. - 40112236
// V-jayy21@hotmail.com

#pragma once
#include<iostream>

class Date {
public:
	Date();
	Date(int, int, int);
	void print() const;

	void setDate(int, int, int);
	void setMonth(int);
	void setDay(int);
	void setYear(int);

	int getMonth() const;
	int getDay() const;
	int getYear() const;

private:
	int month;
	int day;
	int year;
};