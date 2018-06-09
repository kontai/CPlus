#include<iostream>
#include<fstream>

using namespace std;

void st(istream &in) {
	cout << "cin.bad()=" << in.bad() << endl;
	cout << "cin.fail()=" << in.fail() << endl;
	cout << "cin.eof()=" << in.eof() << endl;
}

int mainIOstream() {
	int n = 0, sum = 0;
	while (cin >> n, !cin.eof()) {
		st(cin);
		if (cin.bad())
			cerr << "bad input,error corrupt" << endl;
		if (cin.fail()) {
			cerr << "wrong input,try again!" << endl;
			cin.clear(iostream::failbit);
			//清除錯誤狀態 , 引數形式j為iostate(iostate有三種狀態:badbit,failbit,eofbit)
			cin.ignore(200, '\n');
			//清除cin緩存 cin.ignore(number,delimiter)  清除的字元數量,或清除直到遇到換行符或文件結束為止'\n'
		   //如問清空緩存(flushed,寫入檔案或實際裝置),cin持續接收道存緩存的錯誤輸入,形成無限循環(死循環)

			continue;
		}
		else {
			sum += n;
			cout << sum << endl;
		}
	}
	if (cin.eof())
		cout << "End Of File!" << endl;

	system("pause");
	return 0;
}