#pragma once



class MEM {
public:
	MEM();
	MEM(int s, int p);
	MEM(const MEM &mem);
	~MEM();
	void showInfo()const;
private:
	unsigned int size ;
	unsigned int price;
};