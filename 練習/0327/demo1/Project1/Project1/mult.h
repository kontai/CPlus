#pragma once

#include<iostream>

using namespace std;

template<class T>
class MyArray {
public:
	MyArray() {}
	MyArray( T m_data) {
		this->m_capacity = 0;
		this->m_size = 0;
		const int SIZE = sizeof(m_data);
		if (SIZE != 0) {
			this->m_data = new T[SIZE + 1];
			for (int i = 0; i < SIZE; i++) {
				this->m_data[i] = i;
			}
		}
		else {
			cout << "資料有誤!" << endl;
			exit(-1);
		}
		}
	MyArray(const MyArray &array) {
		m_capacity = array->m_capacity;
		m_size++;
		const int SIZE = sizeof(array.m_data);
		m_data = new T[SIZE + 1];
		for (int i = 0; i < SIZE; i++) {
			m_data[i] = array->m_data[i];
		}

	}
	~MyArray() {
		if (m_data != NULL) {
			delete[] m_data;
			m_data = NULL;
			cout << "析構函數被調用" << endl;
		}
	}
	//void showInfo() {
	//	cout << *m_data << endl;
	//}

	int m_capacity;
	T *m_data;
	int m_size;

};


