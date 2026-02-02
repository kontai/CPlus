#include <iostream>
#include <mutex>
#include <memory>
#include <thread>

// ========================================
// 方法1: 懶漢式 (Lazy Initialization) - 非線程安全
// ========================================
class Singleton_Lazy_Unsafe {
private:
    static Singleton_Lazy_Unsafe* instance;

    // 私有構造函數,防止外部實例化
    Singleton_Lazy_Unsafe() {
        std::cout << "Singleton_Lazy_Unsafe 構造函數被調用" << std::endl;
    }

    // 刪除拷貝構造和賦值操作
    Singleton_Lazy_Unsafe(const Singleton_Lazy_Unsafe&) = delete;
    Singleton_Lazy_Unsafe& operator=(const Singleton_Lazy_Unsafe&) = delete;

public:
    static Singleton_Lazy_Unsafe* getInstance() {
        if (instance == nullptr) {
            instance = new Singleton_Lazy_Unsafe();
        }
        return instance;
    }

    void showMessage() {
        std::cout << "Lazy Unsafe Singleton 實例地址: " << this << std::endl;
    }

    // 注意: 需要手動釋放記憶體
    static void destroy() {
        if (instance != nullptr) {
            delete instance;
            instance = nullptr;
        }
    }
};

Singleton_Lazy_Unsafe* Singleton_Lazy_Unsafe::instance = nullptr;


// ========================================
// 方法2: 懶漢式 - 雙重檢查鎖定 (線程安全)
// ========================================
class Singleton_DCL {
private:
    static Singleton_DCL* instance;
    static std::mutex mtx;

    Singleton_DCL() {
        std::cout << "Singleton_DCL 構造函數被調用" << std::endl;
    }

    Singleton_DCL(const Singleton_DCL&) = delete;
    Singleton_DCL& operator=(const Singleton_DCL&) = delete;

public:
    static Singleton_DCL* getInstance() {
        if (instance == nullptr) {  // 第一次檢查
            std::lock_guard<std::mutex> lock(mtx);
            if (instance == nullptr) {  // 第二次檢查
                instance = new Singleton_DCL();
            }
        }
        return instance;
    }

    void showMessage() {
        std::cout << "DCL Singleton 實例地址: " << this << std::endl;
    }

    static void destroy() {
        if (instance != nullptr) {
            delete instance;
            instance = nullptr;
        }
    }
};

Singleton_DCL* Singleton_DCL::instance = nullptr;
std::mutex Singleton_DCL::mtx;


// ========================================
// 方法3: 餓漢式 (Eager Initialization) - 線程安全
// ========================================
class Singleton_Eager {
private:
    static Singleton_Eager instance;

    Singleton_Eager() {
        std::cout << "Singleton_Eager 構造函數被調用" << std::endl;
    }

    Singleton_Eager(const Singleton_Eager&) = delete;
    Singleton_Eager& operator=(const Singleton_Eager&) = delete;

public:
    static Singleton_Eager& getInstance() {
        return instance;
    }

    void showMessage() {
        std::cout << "Eager Singleton 實例地址: " << this << std::endl;
    }
};

Singleton_Eager Singleton_Eager::instance;


// ========================================
// 方法4: Meyers' Singleton (C++11推薦) - 最佳實踐
// ========================================
class Singleton_Meyers {
private:
    Singleton_Meyers() {
        std::cout << "Singleton_Meyers 構造函數被調用" << std::endl;
    }

    Singleton_Meyers(const Singleton_Meyers&) = delete;
    Singleton_Meyers& operator=(const Singleton_Meyers&) = delete;

public:
    static Singleton_Meyers& getInstance() {
        // C++11保證局部靜態變量的線程安全初始化
        static Singleton_Meyers instance;
        return instance;
    }

    void showMessage() {
        std::cout << "Meyers Singleton 實例地址: " << this << std::endl;
    }
};


// ========================================
// 方法5: 使用智能指針的單例 (RAII)
// ========================================
class Singleton_SmartPtr {
private:
    static std::unique_ptr<Singleton_SmartPtr> instance;
    static std::once_flag initFlag;

    Singleton_SmartPtr() {
        std::cout << "Singleton_SmartPtr 構造函數被調用" << std::endl;
    }

    Singleton_SmartPtr(const Singleton_SmartPtr&) = delete;
    Singleton_SmartPtr& operator=(const Singleton_SmartPtr&) = delete;

public:
    static Singleton_SmartPtr& getInstance() {
        std::call_once(initFlag, []() {
            instance.reset(new Singleton_SmartPtr());
        });
        return *instance;
    }

    void showMessage() {
        std::cout << "SmartPtr Singleton 實例地址: " << this << std::endl;
    }
};

std::unique_ptr<Singleton_SmartPtr> Singleton_SmartPtr::instance = nullptr;
std::once_flag Singleton_SmartPtr::initFlag;


// ========================================
// 測試函數
// ========================================
void testThreadSafety() {
    auto func = []() {
        Singleton_Meyers& s = Singleton_Meyers::getInstance();
        s.showMessage();
    };

    std::thread t1(func);
    std::thread t2(func);
    std::thread t3(func);

    t1.join();
    t2.join();
    t3.join();
}


int main() {
    std::cout << "=== C++ 單例模式演示 ===" << std::endl << std::endl;

    // 測試懶漢式 (非線程安全)
    std::cout << "1. 懶漢式 (非線程安全):" << std::endl;
    Singleton_Lazy_Unsafe* s1 = Singleton_Lazy_Unsafe::getInstance();
    Singleton_Lazy_Unsafe* s2 = Singleton_Lazy_Unsafe::getInstance();
    s1->showMessage();
    s2->showMessage();
    std::cout << "是否為同一實例: " << (s1 == s2 ? "是" : "否") << std::endl << std::endl;

    // 測試雙重檢查鎖定
    std::cout << "2. 雙重檢查鎖定 (線程安全):" << std::endl;
    Singleton_DCL* s3 = Singleton_DCL::getInstance();
    Singleton_DCL* s4 = Singleton_DCL::getInstance();
    s3->showMessage();
    s4->showMessage();
    std::cout << "是否為同一實例: " << (s3 == s4 ? "是" : "否") << std::endl << std::endl;

    // 測試餓漢式
    std::cout << "3. 餓漢式 (線程安全):" << std::endl;
    Singleton_Eager& s5 = Singleton_Eager::getInstance();
    Singleton_Eager& s6 = Singleton_Eager::getInstance();
    s5.showMessage();
    s6.showMessage();
    std::cout << "是否為同一實例: " << (&s5 == &s6 ? "是" : "否") << std::endl << std::endl;

    // 測試Meyers單例
    std::cout << "4. Meyers' Singleton (推薦):" << std::endl;
    Singleton_Meyers& s7 = Singleton_Meyers::getInstance();
    Singleton_Meyers& s8 = Singleton_Meyers::getInstance();
    s7.showMessage();
    s8.showMessage();
    std::cout << "是否為同一實例: " << (&s7 == &s8 ? "是" : "否") << std::endl << std::endl;

    // 測試智能指針單例
    std::cout << "5. 智能指針單例:" << std::endl;
    Singleton_SmartPtr& s9 = Singleton_SmartPtr::getInstance();
    Singleton_SmartPtr& s10 = Singleton_SmartPtr::getInstance();
    s9.showMessage();
    s10.showMessage();
    std::cout << "是否為同一實例: " << (&s9 == &s10 ? "是" : "否") << std::endl << std::endl;

    // 測試多線程安全性
    std::cout << "6. 多線程安全性測試 (Meyers):" << std::endl;
    testThreadSafety();

    // 清理資源
    Singleton_Lazy_Unsafe::destroy();
    Singleton_DCL::destroy();

    return 0;
}