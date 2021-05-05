#include <iostream>
#include <map>
#include <string.h>
using namespace std;

void display(map<int, string> Map) {
    if (Map.empty()) {
        cout << "map is empty" << endl;
        return;
    }

    for (auto i : Map) {
        cout << i.first << ": " << i.second << endl;
    }
    cout << endl;
}

int main() {
    map<int, string> Employees;
    // 使用数组索引符号进行赋值
    Employees[101] = "Nikita";
    Employees[105] = "John";
    Employees[103] = "Dolly";
    Employees[102] = "Aman";
    Employees[104] = "Deep";
    // 插入
    Employees.insert(make_pair(99, "Marry"));

    // begin 遍历
    cout << "自然顺序:" << endl;
    for (map<int, string>::iterator ii = Employees.begin(); ii != Employees.end(); ++ii) {
        cout << (*ii).first << ": " << (*ii).second << endl;
    }
    cout << endl;

    // rbegin 遍历
    cout << "相反顺序:" << endl;
    for (map<int, string>::reverse_iterator ii = Employees.rbegin(); ii != Employees.rend(); ++ii) {
        cout << (*ii).first << ": " << (*ii).second << endl;
    }
    cout << endl;

    // 查找
    cout << Employees.count(99) << endl;
    cout << Employees.at(99) << endl;

    // 删除
    cout << Employees.erase(99) << endl;
    display(Employees);

    // 清空
    Employees.clear();
    display(Employees);

    return 0;
}