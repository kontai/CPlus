#include <iostream>

using namespace std;

class Item_base {

public:
  Item_base(const string &book = "", double sales_price = 0.0)
      : isbn(book), price(sales_price) {}

  string book() const { return isbn; };

  virtual double net_price(size_t n)const {
    return n*price;
  }

virtual ~Item_base(){}

private:
  string isbn;

protected:
  double price;
};

int main() { return 0; }