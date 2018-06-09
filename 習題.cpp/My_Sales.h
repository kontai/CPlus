#pragma once
#include <iostream>

class My_Sales {
public:
	double avg_price()const;
	bool same_isbn(const My_Sales &rbn)const {
		return rbn.isbn == isbn;
	}
	My_Sales::My_Sales() :units_order(0), revenue(0.0) {
	}

	std::istream &input(std::istream &in);
	std::ostream &output(std::ostream &out)const;
	My_Sales add(My_Sales &other);

private:
	std::string isbn;
	unsigned units_order;
	double revenue;
};
