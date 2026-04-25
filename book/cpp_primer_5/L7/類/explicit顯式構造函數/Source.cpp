#include<iostream>
#include<string>

using namespace std;

class Sales_data
{
public:
	Sales_data() = default;
	Sales_data(const std::string& s, unsigned n, double p) :
		bookNo(s), units_sold(n), revenue(p* n) {
	}
	explicit Sales_data(const std::string& s) : bookNo(s) {}
	explicit Sales_data(std::istream& in) {
		string stmp;
		while (in >> stmp)
			;
		this->bookNo += stmp;

	};
	Sales_data& combine(const Sales_data& s) {
		this->bookNo += s.bookNo;
		return *this;
	}
private:
	string bookNo;
	unsigned int units_sold;
	double revenue;
};

int main() {
	string null_book = "9-999-99999-9";

	Sales_data sd(null_book);

	//只能直接初始化
	//Sales_data csd = null_book;

	//Sales_data sd2(cin);

	//無法隱式轉換
	//sd.combine(null_book);
}