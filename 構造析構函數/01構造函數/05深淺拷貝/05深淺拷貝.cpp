#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>

using namespace std;

struct Student {
public:
	Student(const char* Name, int Age) {
		this->name = (char*)malloc(strlen(Name) + 1);
		if (this->name == nullptr) {
			cout << "allocate fail." << endl;
			exit(-1);
		}
		strcpy(this->name, Name);
		this->age = Age;
		cout << "Student(const char* Name,int Age) called." << endl;
	}

	Student(const Student& st) {
		if (st.name == nullptr) {
			cout << "name不可為空." << endl;
			return;
		}
		this->name = (char*)malloc(strlen(st.name) + 1);
		if (this->name == nullptr) {
			cout << "allocate fail." << endl;
			exit(-1);
		}
		strcpy(this->name, st.name);
		this->age = st.age;
		cout << "copy constructor is called." << endl;
	}

	//移動構造
	Student(Student&& st) noexcept :name(st.name), age(st.age) {
		//避免誤刪
		st.name = nullptr;
		cout << "move constructor  calleed." << endl;
	}

	~Student() {
		//釋放空間
		if (this->name != nullptr)
		{
			free(this->name);
			this->name = nullptr;
		}
		cout << "~Student() called." << endl;
	}

	string getName() {
		return this->name;
	}
	int getAge() {
		return this->age;
	}

private:
	char* name;
	int age;
};

void copyFunc() {
	Student st1("kontai", 19);
	Student st2(st1);
	Student st3 = move(st1);
	cout << st3.getName() << endl;
}

int main() {
	copyFunc();
}

