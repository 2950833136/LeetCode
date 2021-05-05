#include <iostream>
#include <map>
using namespace std;

int main() {
    pair<string, int> p1;
    pair<string, int> p2;
    pair<string, int> p3;

    // 创建方式第一种
    p1.first  = "young";
    p1.second = 3;
    // 第二种
    p2 = make_pair("simple", 0);
    // 第三种
    p3 = pair<string, int>("naive", 1);

    cout << p1.first << " " << p1.second << endl;
    cout << p2.first << " " << p2.second << endl;
    cout << p3.first << " " << p3.second << endl;

    // 比较
    pair<int, int> p11(5, 10);
    pair<int, int> p22(5, 15);
    pair<int, int> p33(10, 5);

    if (p11 < p22) {
        cout << "p11 < p22" << endl;
    }
    if (p11 < p33) {
        cout << "p11 < p33" << endl;
    }

    return 0;
}
