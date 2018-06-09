#include<iostream>
#include<string>

using namespace std;

class Sub_class{
    public:
    Sub_class(const string &st=""){}
    Sub_class(string& str){
        ptrchar=new string(str);
        *ptrchar=str;
    }
Sub_class& operator[](const size_t);
Sub_class& operator[](const size_t)const;

    private:
    string *ptrchar;

};

Sub_class& Sub_class::operator[](const size_t index){
    return ptrchar[index];
}

Sub_class& Sub_class::operator[](const size_t index)const{
    return ptrchar[index];
}

Sub_class(string& chptr){
Sub_class *ptr=new string(strlen(chptr));
if(!ptr)
throw
cout<<"error"<<endl;
strcpy(ptr,chptr);
ptrchar=ptr;
}

int mainaa(){
    Sub_class ss("abc");
    string str("abc");
    string *str2=new string(str);
    *str2="def";
    cout<<str2<<endl;




    return 0;
}