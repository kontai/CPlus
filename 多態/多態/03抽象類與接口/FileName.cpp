#include <iostream>
#include <string>
using namespace std;

// ========================================
// 1. 接口 (Interface) - 純契約
// ========================================
class ICar {
public:
    // ❌ 沒有成員變數
    // ❌ 沒有實現
    
    // ✅ 只有純虛函數
    virtual void show() = 0;
    virtual void start() = 0;
    virtual void stop() = 0;
    virtual int getSpeed() = 0;
    
    // ✅ 虛析構函數
    virtual ~ICar() {}
};

// ========================================
// 2. 抽象類 (Abstract Class) - 有共用實現
// ========================================
class AbstractCar {
protected:
    // ✅ 可以有成員變數
    string brand;
    string model;
    int speed;
    bool engineRunning;

public:
    // ✅ 可以有構造函數
    AbstractCar(const string& b, const string& m) 
        : brand(b), model(m), speed(0), engineRunning(false) {
        cout << "[AbstractCar] 構造: " << brand << " " << model << endl;
    }

    // ✅ 可以有普通成員函數（有實現）
    void displayInfo() {
        cout << "品牌: " << brand << ", 型號: " << model << endl;
        cout << "速度: " << speed << " km/h" << endl;
        cout << "引擎狀態: " << (engineRunning ? "運行中 " : "熄火 ") << endl;
    }

    // ✅ 可以有虛函數（子類可選覆寫）
    virtual void accelerate() {
        if (engineRunning) {
            speed += 10;
            cout << "加速到 " << speed << " km/h" << endl;
        } else {
            cout << "請先啟動引擎！ " << endl;
        }
    }

    virtual void brake() {
        if (speed > 0) {
            speed -= 10;
            if (speed < 0) speed = 0;
            cout << "減速到 " << speed << " km/h" << endl;
        }
    }

    // ✅ 純虛函數（子類必須實現）
    virtual void show() = 0;
    virtual void start() = 0;
    virtual void stop() = 0;

    // ✅ 虛析構函數
    virtual ~AbstractCar() {
        cout << "[AbstractCar] 析構: " << brand << " " << model << endl;
    }
};

// ========================================
// 3. 實現接口的類
// ========================================
class ToyotaInterface : public ICar {
private:
    string model;
    int speed;

public:
    ToyotaInterface(const string& m) : model(m), speed(0) {
        cout << "[ToyotaInterface] 構造: " << model << endl;
    }

    // 必須實現所有接口方法
    void show() override {
        cout << "Toyota " << model << " (Interface 實現)" << endl;
    }

    void start() override {
        cout << "Toyota 啟動引擎" << endl;
    }

    void stop() override {
        cout << "Toyota 熄火" << endl;
    }

    int getSpeed() override {
        return speed;
    }

    ~ToyotaInterface() {
        cout << "[ToyotaInterface] 析構: " << model << endl;
    }
};

// ========================================
// 4. 繼承抽象類的類
// ========================================
class ToyotaAbstract : public AbstractCar {
public:
    ToyotaAbstract(const string& model) 
        : AbstractCar("Toyota", model) {
        cout << "[ToyotaAbstract] 構造完成 " << endl;
    }

    // 必須實現純虛函數
    void show() override {
        cout << "\n=== Toyota " << model << " ===" << endl;
        displayInfo();  // 使用繼承的普通函數
    }

    void start() override {
        if (!engineRunning) {
            engineRunning = true;
            cout << "Toyota 引擎啟動成功！ " << endl;
        } else {
            cout << "引擎已經在運行中" << endl;
        }
    }

    void stop() override {
        if (engineRunning) {
            speed = 0;
            engineRunning = false;
            cout << "Toyota 引擎熄火" << endl;
        }
    }

    // 可選：覆寫虛函數
    void accelerate() override {
        AbstractCar::accelerate();  // 調用父類實現
        if (speed > 100) {
            cout << "⚠️ Toyota 提示: 速度過快，請注意安全！ " << endl;
        }
    }

    ~ToyotaAbstract() {
        cout << "[ToyotaAbstract] 析構" << endl;
    }
};

// ========================================
// 5. 多重接口實現
// ========================================
class IElectric {
public:
    virtual void charge() = 0;
    virtual int getBatteryLevel() = 0;
    virtual ~IElectric() {}
};

class IAutonomous {
public:
    virtual void enableAutoDrive() = 0;
    virtual void disableAutoDrive() = 0;
    virtual ~IAutonomous() {}
};

// Tesla 實現多個接口
class Tesla : public ICar, public IElectric, public IAutonomous {
private:
    string model;
    int speed;
    int battery;
    bool autoDrive;

public:
    Tesla(const string& m) : model(m), speed(0), battery(100), autoDrive(false) {
        cout << "[Tesla] 構造: " << model << endl;
    }

    // 實現 ICar 接口
    void show() override {
        cout << "Tesla " << model << " (電動車)" << endl;
        cout << "電池: " << battery << "%, 速度: " << speed << " km/h" << endl;
        cout << "自動駕駛: " << (autoDrive ? "開啟" : "關閉") << endl;
    }

    void start() override {
        cout << "Tesla 啟動（靜音）" << endl;
    }

    void stop() override {
        cout << "Tesla 停止" << endl;
    }

    int getSpeed() override {
        return speed;
    }

    // 實現 IElectric 接口
    void charge() override {
        battery = 100;
        cout << "Tesla 充電完成: 100%" << endl;
    }

    int getBatteryLevel() override {
        return battery;
    }

    // 實現 IAutonomous 接口
    void enableAutoDrive() override {
        autoDrive = true;
        cout << "Tesla Autopilot 已啟動 " << endl;
    }

    void disableAutoDrive() override {
        autoDrive = false;
        cout << "Tesla Autopilot 已關閉 " << endl;
    }

    ~Tesla() {
        cout << "[Tesla] 析構:  " << model << endl;
    }
};

// ========================================
// 主程序
// ========================================
int main() {
    cout << "========================================" << endl;
    cout << "  接口 vs 抽象類實例 " << endl;
    cout << "========================================" << endl;

    // 測試1: 接口實現
    cout << "\n【測試1】接口實現 (ICar) " << endl;
    cout << "----------------------------------------" << endl;
    
    ICar* car1 = new ToyotaInterface("Camry");
    car1->show();
    car1->start();
    car1->stop();
    cout << "速度: " << car1->getSpeed() << " km/h" << endl;
    delete car1;

    // 測試2: 抽象類實現
    cout << "\n【測試2】抽象類實現 (AbstractCar)" << endl;
    cout << "----------------------------------------" << endl;
    
    AbstractCar* car2 = new ToyotaAbstract("Corolla");
    car2->show();
    car2->start();
    car2->accelerate();
    car2->accelerate();
    car2->accelerate();
    car2->brake();
    car2->show();
    car2->stop();
    delete car2;

    // 測試3: 多重接口
    cout << "\n【測試3】多重接口實現 " << endl;
    cout << "----------------------------------------" << endl;
    
    Tesla* tesla = new Tesla("Model S");
    
    // 作為 ICar 使用
    ICar* car3 = tesla;
    car3->show();
    car3->start();
    
    // 作為 IElectric 使用
    IElectric* electric = tesla;
    electric->charge();
    cout << "電池: " << electric->getBatteryLevel() << "%" << endl;
    
    // 作為 IAutonomous 使用
    IAutonomous* auto_drive = tesla;
    auto_drive->enableAutoDrive();
    
    tesla->show();
    
    delete tesla;

    // 對比總結
    cout << "\n========================================" << endl;
    cout << "【總結對比】 " << endl;
    cout << "========================================" << endl;
    
    cout << "\nICar (接口):" << endl;
    cout << "  • 只定義契約，沒有實現" << endl;
    cout << "  • 沒有成員變數" << endl;
    cout << "  • 子類必須實現所有方法 " << endl;
    cout << "  • 適合多重繼承" << endl;
    cout << "  • 表示「能做什麼」 " << endl;
    
    cout << "\nAbstractCar (抽象類):" << endl;
    cout << "  • 提供共用實現（displayInfo, accelerate, brake） " << endl;
    cout << "  • 有成員變數（brand, model, speed, engineRunning） " << endl;
    cout << "  • 部分方法有預設實現，部分是純虛函數 " << endl;
    cout << "  • 子類繼承共用邏輯，只需實現特定方法" << endl;
    cout << "  • 表示「是什麼」 " << endl;

    cout << "\n原始 Car 類是:" << endl;
    cout << "  ✅ 接口（只有純虛函數）" << endl;
    cout << "  ✅ 也是抽象類（有純虛函數）" << endl;
    cout << "  → 嚴格來說是「接口」（慣例） " << endl;

    cout << "========================================" << endl;

    return 0;
}