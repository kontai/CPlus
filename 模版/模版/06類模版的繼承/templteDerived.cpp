#include <iostream>
#include <string>
using namespace std;

// ============================================================
// 類模板：MyClass<nameType, ageType>
//
// 用途：作為父類，提供姓名與年齡的儲存與顯示功能
// 模板參數：
//   nameType - 姓名的類型（例如 string、wstring）
//   ageType  - 年齡的類型（例如 int、double）
// ============================================================
template<typename nameType, typename ageType>
class MyClass {
public:
    // 有參構造函數
    // name 以 const 引用傳入，避免複製大型字串
    // age  以值傳入，int/double 等基本類型直接傳值即可
    MyClass(const nameType& name, ageType age)
        : name(name), age(age) {}

    // 虛函數：顯示資料
    // 聲明為 virtual，讓子類可以覆寫（多態）
    // this->name 明確指向本類成員，避免命名歧義
    virtual void Display() {
        cout << "name: " << this->name
             << ", age: " << this->age << endl;
    }

    // 虛析構函數（建議加上，確保多態下正確析構）
    virtual ~MyClass() {}

protected:
    // protected：本類和子類可以訪問，外部不能直接訪問
    nameType name;  // 姓名，類型由模板參數 nameType 決定
    ageType  age;   // 年齡，類型由模板參數 ageType  決定
};

// ============================================================
// 普通類繼承類模板
//
// 說明：NormalClass 是一般的非模板類
//       繼承時需要明確指定父類的模板參數 <string, int>
//       之後 NormalClass 就是一個具體的、固定類型的類
//
// 特點：
//   - 類型在繼承時被固定為 <string, int>
//   - 使用者不需要指定模板參數，直接 NormalClass nc(...)
//   - 初始化列表中可以省略父類模板參數，
//     因為編譯器已知 MyClass 的具體類型是 MyClass<string, int>
// ============================================================
class NormalClass : public MyClass<string, int> {
public:
    // 構造函數：將參數轉發給父類
    // 初始化列表中 MyClass(name, age) 等同於 MyClass<string,int>(name,age)
    // 因為在 NormalClass 的作用域內，MyClass 已確定為 MyClass<string,int>
    NormalClass(string name, int age)
        : MyClass(name, age) {}

    // Display() 未覆寫 → 直接使用父類的實作
};

// ============================================================
// 模板類繼承類模板
//
// 說明：TemplateClass 本身也是模板，繼承時將模板參數傳遞給父類
//       讓父類的類型由 TemplateClass 的使用者在實例化時決定
//
// 特點：
//   - 保留模板的泛用性，父子類的類型保持一致
//   - 初始化列表必須寫完整的父類類型 MyClass<nameType, ageType>
//     因為 TemplateClass 本身是模板，編譯器無法自動推導父類參數
//   - 若要在子類中訪問父類的 protected 成員，必須用 this->
//     原因：模板繼承中父類是依賴類型，編譯器不會自動查找
// ============================================================
template<typename nameType, typename ageType>
class TemplateClass : public MyClass<nameType, ageType> {
public:
    // 構造函數：將參數轉發給父類
    // 必須寫明 MyClass<nameType, ageType>，不能省略模板參數
    TemplateClass(nameType name, ageType age)
        : MyClass<nameType, ageType>(name, age) {}

    // Display() 未覆寫 → 直接使用父類的實作
    // 若要覆寫且訪問 name/age，必須寫 this->name、this->age
};

// ============================================================
// 測試函數
// ============================================================
void testFunc() {
    // 普通類：直接使用，無需指定模板參數
    NormalClass nc("knotai", 20);
    nc.Display();  // 調用 MyClass<string,int>::Display()

    // 模板類：實例化時需要指定模板參數
    TemplateClass<string, int> tc("Michael", 50);
    tc.Display();  // 調用 MyClass<string,int>::Display()
}

int main() {
    testFunc();
    return 0;
}