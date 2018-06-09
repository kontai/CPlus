#include<iostream>

using namespace std;

class LongDouble{
    public:
    LongDouble(double  x=0.0):db(x){}
operator double();
operator float();
operator int();
private:
int in;
double db;
};

LongDouble::operator double(){
    cout<<"operator double"<<endl;
    return db;
}

LongDouble::operator float(){
    cout<<"operator float"<<endl;
    return db;
}

LongDouble::operator int(){
    return db;
}
int mainExam14_44(){
LongDouble ldobj(2.3);
int ex1=ldobj;
float ex2=ldobj;


    return 0;
}

