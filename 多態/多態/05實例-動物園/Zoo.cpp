#include <iostream>
#include <string>
#include <vector>
#include <memory>
using namespace std;

// ========================================
// 優化版本
// ========================================

// 基礎動物類 - 提供共用實現
class Animal {
protected:
	string name;
	int age;

public:
	Animal(const string& n, int a) : name(n), age(a) {}

	// 純虛函數 - 子類必須實現
	virtual void bow() const = 0;

	// 共用實現 - 避免重複
	virtual string getName() const {
		return name;
	}

	int getAge() const {
		return age;
	}

	virtual ~Animal() {
		cout << name << " 已從動物園移出" << endl;
	}
};

// 具體動物類 - 只需實現 bow()
class Dog : public Animal {
public:
	Dog(const string& name, int age) : Animal(name, age) {
		cout << "Dog constructed: " << name << endl;
	}

	void bow() const override {
		cout << name << " 汪汪叫" << endl;
	}
};

class Cat : public Animal {
public:
	Cat(const string& name, int age) : Animal(name, age) {
		cout << "Cat constructed: " << name << endl;
	}

	void bow() const override {
		cout << name << " 喵喵叫" << endl;
	}
};

class Chicken : public Animal {
public:
	Chicken(const string& name, int age) : Animal(name, age) {
		cout << "Chicken constructed: " << name << endl;
	}

	void bow() const override {
		cout << name << " 咕咕叫" << endl;
	}
};

class Horse : public Animal {
public:
	Horse(const string& name, int age) : Animal(name, age) {
		cout << "Horse constructed: " << name << endl;
	}

	void bow() const override {
		cout << name << " 嗷嗷叫" << endl;
	}
};

class Tiger : public Animal {
public:
	Tiger(const string& name, int age) : Animal(name, age) {
		cout << "Tiger constructed: " << name << endl;
	}

	void bow() const override {
		cout << name << " 吼吼叫" << endl;
	}
};

class Bird : public Animal {
public:
	Bird(const string& name, int age) : Animal(name, age) {
		cout << "Bird constructed: " << name << endl;
	}

	void bow() const override {
		cout << name << " 吱吱叫" << endl;
	}
};

// 動物園 - 使用智能指針管理記憶體
class Zoo {
private:
	vector<unique_ptr<Animal>> animals;  // 自動管理記憶體

public:
	Zoo() {
		cout << "Zoo constructed" << endl;
	}

	// 添加動物 - 接受 unique_ptr
	void addAnimal(unique_ptr<Animal> animal) {
		animals.push_back(move(animal));
	}

	// 所有動物叫
	void startBow() const {
		cout << "\n=== 動物們開始叫 ===" << endl;
		for (const auto& animal : animals) {
			animal->bow();
		}
	}

	// 顯示所有動物資訊
	void showAnimals() const {
		cout << "\n=== 動物園動物列表 ===" << endl;
		for (size_t i = 0; i < animals.size(); ++i) {
			cout << i + 1 << ". " << animals[i]->getName()
				<< " (年齡: " << animals[i]->getAge() << ")" << endl;
		}
	}

	// 獲取動物數量
	size_t getAnimalCount() const {
		return animals.size();
	}

	~Zoo() {
		cout << "\n=== Zoo 析構開始 ===" << endl;
		// vector 和 unique_ptr 會自動清理
	}
};

// ========================================
// 使用示例
// ========================================
void test_optimized() {
	cout << "========================================" << endl;
	cout << "  優化版本測試" << endl;
	cout << "========================================" << endl;

	// 創建動物園
	Zoo zoo;

	// 添加動物 - 使用 make_unique
	zoo.addAnimal(make_unique<Dog>("旺財", 2));
	zoo.addAnimal(make_unique<Cat>("貓貓", 3));
	zoo.addAnimal(make_unique<Chicken>("雞雞", 1));
	zoo.addAnimal(make_unique<Horse>("馬兒", 4));
	zoo.addAnimal(make_unique<Tiger>("老虎", 5));
	zoo.addAnimal(make_unique<Bird>("小鳥", 1));

	// 顯示動物
	zoo.showAnimals();

	cout << "\n動物總數: " << zoo.getAnimalCount() << endl;

	// 所有動物叫
	zoo.startBow();

	// 離開作用域，自動清理
}

int main() {
	test_optimized();
}