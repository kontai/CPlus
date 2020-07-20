/****************************************
[6/4/2017  18:11]
Exam14.31.cpp
****************************************/

#include<iostream>

using namespace std;

struct If {
	int operator()(int i,int j,int k){
		if (i % 2 == 0)
			return i;
		else
			if (j % 2 == 0)
				return j;
		return k;
	}
};

int mainExam4_31(){

	If whatif;
	cout << whatif(3, 4, 5) << endl;
	



system("pause");
return 0;
}