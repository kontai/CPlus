#pragma once
class One {
private:
	int m_unused;
	int func();
};

class OneClass {
public:
	static 	OneClass* creator() {
		count++;
		return newObject;
	}

	static int count;
private:
	OneClass() {  };
	OneClass(const OneClass& one) {};
	static OneClass* newObject;
};

