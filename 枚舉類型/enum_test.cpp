/*************************
[18/6/2018 7:48
enum_test.cpp
*************************/

#include<iostream>
#include<string>

using namespace std;

enum  Ram_type { DDR4, DDR3, DDR2 };

class RAM {
	double storage;
	int frenqency;
	Ram_type type;

public:

	RAM(Ram_type rt, double size, int fre) :type(rt), storage(size), frenqency(fre) {
		cout << "calling constructor of RAM" << endl;
	}
	RAM(const RAM&);
	void get_ram_info();
	double get_strage_info() { return storage; }
	int get_frenqency_info() { return frenqency; }

	~RAM() { cout << "--------destructor RAM" << endl; }
};

RAM::RAM(const RAM &i) {
	frenqency = i.frenqency;
	storage = i.storage;
	type = i.type;
	cout << "calling copy constructor of RAM" << endl;
}

void RAM::get_ram_info() {
	string s;
	switch (type) {
	case DDR4:
		s = "DDR4";
		break;
	case DDR3:
		s = "DDR3";
		break;
	case DDR2:
		s = "DDR2";
		break;
	}
	cout << s << frenqency << storage << endl;
}


enum  CDROM_socket { SATA, USB, IDE };
enum  CDROM_Plug { EXT, BUILT_IN };

class CDROM {
	short buffer;
	CDROM_Plug plug;
	CDROM_socket socket;
public:
	CDROM(CDROM_Plug cp, CDROM_socket cs, int bf) :plug(cp), socket(cs), buffer(bf) {
		cout << "calling constructor of CDROM" << endl;
	}
	CDROM(const CDROM&);
	~CDROM() { cout << "---------destructor of CDROM" << endl; }
};

CDROM::CDROM(const CDROM& cd) {
	buffer = cd.buffer;
	cout << "calling copy constructor of CDROM" << endl;
}
class COMPUTER {
	RAM my_ram;
	CDROM my_cdrom;
public:
	COMPUTER(RAM ram, CDROM cdrom) :my_cdrom(cdrom), my_ram(ram) {
		cout << "calling constructor of CONPUTER" << endl;
	}


	~COMPUTER(){ cout << "-----------destructor of COMPUTER" << endl; }
};



int mainEN() {
	RAM r1(DDR4, 4096, 3168);
	cout << "............................" << endl;
	CDROM cd1(BUILT_IN, SATA, 2048);
	cout << "............................" << endl;
	COMPUTER(r1, cd1);


	system("pause");
	return 0;
}