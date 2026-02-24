C++ 的 `std::string` 是我們告別 C 語言 `char*` 噩夢（手動管理記憶體、越界崩潰、忘記結尾 `\0`）的最強武器。

身為工程師，我們不能只把它當作一個「裝文字的黑盒子」，而是要了解它提供了哪些精密的工具來操作記憶體中的字元。

為了方便快速檢索與理解，我將 `std::string` 最常用的函數按照**功能場景**拆解成六大模組：

---

### 1. 建構與初始化 (Initialization)

除了最基本的賦值，`string` 提供了多種建構方式來應付不同需求。

```cpp
#include <iostream>
#include <string>

using namespace std;

void init_demo() {
    string s1;                  // 預設建構：空字串 ""
    string s2 = "Hello";        // 從 C-style 字串建構
    string s3("C++");           // 另一種常見寫法
    string s4(5, 'A');          // 填充建構："AAAAA" (常用於初始化特定長度的緩衝區)
    string s5 = s2;             // 拷貝建構 (深拷貝)
}

```

### 2. 容量與記憶體管理 (Capacity & Memory)

這是資深開發者最在意的部分。`string` 底層會動態調整記憶體，了解這些函數能幫你寫出效能更好的程式碼。

* **`size()` / `length()**`：回傳目前字串的字元數量（兩者功能完全一樣）。
* **`empty()`**：檢查字串是否為空（比 `s.size() == 0` 更快、語意更清晰）。
* **`capacity()`**：回傳目前底層配置了多少記憶體空間（通常大於等於 `size()`）。
* **`reserve(n)`**：**【效能優化利器】** 預先向系統要 `n` 個字元的空間。如果你知道接下來會頻繁拼接字串（例如迴圈中），先 `reserve` 可以避免底層不斷觸發「重新配置與搬移記憶體」的昂貴開銷。
* **`clear()`**：清空所有字元（`size` 變 0），但**不會**釋放已經佔用的記憶體（`capacity` 不變）。

```cpp
string s;
s.reserve(1000); // 預先開好 1000 bytes，後續 appending 會非常快

```

### 3. 存取字元 (Element Access)

* **`operator[]`**：最常用的陣列式存取（如 `s[0]`）。**注意：它沒有邊界檢查！** 如果越界，會引發未定義行為 (UB)。效能極高。
* **`at(index)`**：安全的存取方式。如果越界，會拋出 `std::out_of_range` 例外（會觸發我們之前聊過的「棧解旋」）。
* **`front()`** / **`back()`**：直接拿取第一個或最後一個字元（C++11 起支援）。

```cpp
string s = "C++";
char c1 = s[0];       // 'C'
char c2 = s.at(1);    // '+'
s.back() = '#';       // 變成 "C+#" (回傳的是參照，可以直接修改)

```

### 4. 修改與拼接 (Modification)

* **`operator+=`**：最直覺的拼接方式，可以接字串、C-style 字串、單一字元。
* **`append()`**：功能比 `+=` 更強大，例如可以只拼接另一個字串的一部分。
* **`push_back(char)`** / **`pop_back()`**：在尾端加入/移除「單一字元」（把 string 當作 vector 來用）。
* **`insert(pos, str)`**：在指定位置 `pos` 插入字串（注意：插入操作會導致後面的字元全部向後平移，效能開銷較大）。
* **`erase(pos, len)`**：從 `pos` 開始，刪除 `len` 個字元。

```cpp
string s = "Hello";
s += " World";         // "Hello World"
s.insert(5, " C++");   // "Hello C++ World"
s.erase(0, 6);         // "C++ World" (從 index 0 刪除 6 個字元)

```

### 5. 搜尋與子字串 (Search & Substring)

這是處理文字解析 (Text Parsing) 時最常使用的功能。

* **`find(str)`**：由左至右尋找 `str` 第一次出現的位置。
* **`rfind(str)`**：由右至左尋找（Reverse find）。
* **`substr(pos, len)`**：切出子字串。從 `pos` 開始，切下長度為 `len` 的新字串並回傳。

**🚨 工程師避坑指南：`find` 的失敗判定**
如果 `find` 找不到東西，它**不會**回傳 `-1`，而是回傳一個特殊的常數 **`std::string::npos`**。

```cpp
string str = "user@domain.com";
size_t pos = str.find("@");

if (pos != string::npos) {
    // 找到了！切出使用者名稱
    string user = str.substr(0, pos); 
}

```

### 6. 與 C 語言的橋樑 (C-String Interoperability)

當你必須呼叫舊版的 C API（例如 Win32 API 或 Linux 系統呼叫，它們只認 `const char*`）時，這把鑰匙非常重要。

* **`c_str()`**：回傳一個指向唯讀的 `const char*` 指標，並且保證字串尾巴一定有一個 `\0` (Null-terminator)。
* **`data()`**：在 C++11 之前沒有保證 `\0`，但 C++11 之後它的行為已經跟 `c_str()` 完全一樣了。C++17 更允許 `data()` 回傳可修改的 `char*`（如果 string 不是 const 的話）。

```cpp
string filename = "config.txt";
// fopen 是一個 C 函數，不接受 std::string
// FILE* file = fopen(filename, "r"); // ❌ 編譯錯誤
FILE* file = fopen(filename.c_str(), "r"); // ✅ 正確寫法

```

---

### 總結速查表

| 分類           | 常用函數                             | 核心用途                    |
| ------------ | -------------------------------- | ----------------------- |
| **容量資訊**     | `size()`, `empty()`, `reserve()` | 查長度、判斷空、預先配置記憶體防卡頓      |
| **字元讀寫**     | `[]`, `at()`, `back()`           | `[]` 拚效能，`at()` 拚安全防越界  |
| **字串操作**     | `+=`, `insert()`, `erase()`      | 尾端拼接、安插內容、刪除指定段落        |
| **文字解析**     | `find()`, `substr()`             | 找關鍵字位置 (搭配 `npos`)、切割字串 |
| **C API 支援** | `c_str()`                        | 與底層舊代碼或作業系統 API 溝通      |

在現代 C++ (C++17 起) 中，如果你只是需要「讀取、尋找、切割」字串而不需要修改它，C++ 提供了一個效能碾壓 `std::string` 的超輕量級神兵利器叫做 **`std::string_view`**。