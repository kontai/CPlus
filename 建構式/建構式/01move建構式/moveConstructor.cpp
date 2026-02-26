#include<iostream>
#include<cstring>
#include<cstdint>

using namespace std;

class String {
public:
	String(const char* name = "") {
		cout << "creating" << endl;
		if (!name)name = "";
		m_size = strlen(name);
		m_name = new char[m_size + 1];
		memcpy(m_name, name, m_size + 1);
	}
	String(const String& data) {
		cout << "copied" << endl;
		m_size = data.m_size;
		m_name = new char[m_size + 1];
		memcpy(m_name, data.m_name, m_size + 1);
	}
	String(String&& data)noexcept {
		cout << "moved" << endl;
		m_size = data.m_size;
		m_name = data.m_name;
		data.m_size = 0;
		data.m_name = nullptr;
	}
	// Copy assignment
	String& operator=(const String& other) {
		cout << "copy assigned\n";
		if (this == &other)
			return *this;

		delete[] m_name;

		m_size = other.m_size;
		m_name = new char[m_size + 1];
		memcpy(m_name, other.m_name, m_size + 1);

		return *this;
	}

	// Move assignment
	String& operator=(String&& other) noexcept {
		cout << "move assigned\n";
		if (this == &other)
			return *this;

		delete[] m_name;

		m_size = other.m_size;
		m_name = other.m_name;

		other.m_size = 0;
		other.m_name = nullptr;

		return *this;
	}
	~String()
	{
		cout << "destroyed" << endl;
		delete[] m_name;
	}

	void print() const {
		for (uint32_t i = 0; i < m_size; ++i) {
			printf("%c", m_name[i]);
		}
		printf("\n");
	}
private:
	char* m_name;
	uint32_t m_size;
};

class Entity {
public:
	Entity(const String& name) :m_name(name) {}
	Entity(String&& name) :m_name(move(name)) {}
	void print() const {
		m_name.print();
	}
private:
	String m_name;
};

int main() {
	Entity e1("hello");
	e1.print();
	cin.get();
	return 0;
}