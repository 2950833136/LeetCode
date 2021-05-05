#include <iostream>
#include <stack>
using namespace std;

void newstack(stack<int> ss) {
    stack<int> sg = ss;
    while (!sg.empty()) {
        cout << sg.top() << " ";
        sg.pop();
    }
    cout << endl;
}

int main() {
    stack<int> newst;
    newst.push(55);
    newst.push(44);
    newst.push(33);
    newst.push(22);
    newst.push(11);

    cout << "最新的堆栈是 : ";
    newstack(newst);
    cout << "\nnewst.size() : " << newst.size();
    cout << "\nnewst.top()  : " << newst.top();
    cout << "\nnewst.pop()  : ";
    newst.pop();
    newstack(newst);
    return 0;
}