#include <deque>
#include <iostream>
using namespace std;

int main() {
    deque<int> d;
    d.push_back(10);
    d.push_back(20);
    d.push_back(30);
    cout << "原始双端队列：" << endl;
    for (int i = 0; i < d.size(); i++) {
        cout << d.at(i) << "\t";
    }
    cout << endl;
    d.push_front(5);
    d.push_front(3);
    d.push_front(1);

    cout << "after push_front(5.3.1):" << endl;
    for (int i = 0; i < d.size(); i++) {
        cout << d.at(i) << "\t";
    }
    cout << endl;
    d.pop_front();
    d.pop_front();
    cout << "after pop_front() two times:" << endl;
    for (int i = 0; i < d.size(); i++) {
        cout << d.at(i) << "\t";
    }
    cout << endl;
    return 0;
}