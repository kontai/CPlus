#pragma once
#ifndef _1_H
#define _1_H
#include<iostream>
class SavingsAccount {
public:

	SavingsAccount() = default;
	int getId() {
		return Id();
	}
	SavingsAccount(int id, double rate);
	double getBalance() {
		return Rate() / 23;
	}
private:
	int id;		//�b��
	double rate;	//�s�ڪ�
	double balance;
	void show();	//���
};




#endif