#pragma once
#include<iostream>
#include <string>
#include "My_Sales.h"

double My_Sales::avg_price()const {
	if (units_order) {
		return revenue / units_order;
	}
	else
		return 0;
}

std::istream& My_Sales::input(std::istream &in) {
	double price;
	in >> isbn >> units_order >> price;
	if (in) {
		revenue = units_order*price;
	}
	else {
		units_order = 0;
		revenue = 0.0;
	}

	return in;
}

std::ostream &My_Sales::output(std::ostream &out)const {
	double price;
	price = units_order*revenue;
	out << isbn << '\t' << units_order << '\t' << price << '\t' << avg_price() << std::endl;
	return out;
}

My_Sales My_Sales::add(My_Sales &other) {
	revenue += other.revenue;
	units_order += other.units_order;
	return *this;
}