/**

 */

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

/**
 * @brief 類別 MyClass
 *
 * 類別 MyClass 用於儲存姓名和年齡。
 */
class MyClass
{
    public:
        /**
         * @brief 建構子
         *
         * 建立 MyClass 物件的建構子。
         *
         * @param name 姓名
         * @param age 年齡
         */
        MyClass():age(0){}

        MyClass(string name,int age):name(name),age(age){}

        /**
         * @brief 儲存至檔案
         *
         * 儲存 MyClass 物件至檔案。
         *
         * @param out 檔案輸出流
         * @return 是否成功儲存
         */
        bool saveToFile(ofstream& out){
            out.write((char*)&age,sizeof(age));
            int nameLength=name.size();
            out.write((char*)&nameLength,sizeof(nameLength));
            if(nameLength>0){
                out.write(name.c_str(),nameLength);
            }
            return out.good();
        }

        /**
         * @brief 從檔案載入
         *
         * 從檔案載入 MyClass 物件。
         *
         * @param in 檔案輸入流
         * @return 是否成功載入
         */
        bool loadFromFile(ifstream& in){
            in.read((char*)&age,sizeof(age));
            int namelength=0;
            in.read((char*)&namelength,sizeof(namelength));
            if(namelength>0){
                name.resize(namelength);
                in.read(&name[0],namelength);
            }
            return in.good();
        }

        /**
         * @brief 取得姓名
         *
         * 取得 MyClass 物件的姓名。
         *
         * @return 姓名
         */
        string getName() const { return name; }

        /**
         * @brief 取得年齡
         *
         * 取得 MyClass 物件的年齡。
         *
         * @return 年齡
         */
        int getAge() const { return age; }

    private:
        string name;
        int age;
};
int main()
{
    /**
     * @brief 主函數
     *
     * 主函數負責執行檔案的讀寫操作，並顯示結果。
     *
     * @return 0 表示執行成功
     */
    ofstream outFile("data.bin",ios::binary);
    if(outFile){
        MyClass m1("Alice",30);
        MyClass m2("Bob",25);

        m1.saveToFile(outFile);
        m2.saveToFile(outFile);
    }

    ifstream inFile("data.bin",ios::binary);
    if(inFile){
        MyClass m1,m2;
        m1.loadFromFile(inFile);
        m2.loadFromFile(inFile);

        cout<<"m1 name: "<<m1.getName()<<" age: "<<m1.getAge()<<endl;
        cout<<"m2 name: "<<m2.getName()<<" age: "<<m2.getAge()<<endl;
    }
    return 0;
}