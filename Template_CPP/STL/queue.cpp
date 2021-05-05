#include <iostream>
#include <queue>

using namespace std;

int main() {
    queue<int> que_int;

    // 在队列末尾依次插入11，12，13
    que_int.push(11);
    que_int.push(12);
    que_int.push(13);

    // 获取队列中的最后一个元素
    int nValue1 = que_int.back();
    cout << "The last value of queue is: " << nValue1 << endl;

    // 获取队列中的第一个元素
    int nValue2 = que_int.front();
    cout << "The first value of queue is: " << nValue2 << endl;

    // 弹出队列中的第一个元素，之后再获取队列中的第一个元素
    que_int.pop();
    nValue2 = que_int.front();
    cout << "After pop, the first value of queue is: " << nValue2 << endl;

    // 返回队列中的元素个数
    int nSize = que_int.size();
    cout << "The size of queue is: " << nSize << endl;

    // 判断队列是否为空
    bool bFlag = que_int.empty();
    if (bFlag) {
        cout << "queue is empty." << endl;
    } else {
        cout << "queue is not empty." << endl;
    }

    // 清空队列
    que_int = queue<int>();

    // 判断队列是否为空
    bFlag = que_int.empty();
    if (bFlag) {
        cout << "After clear, queue is empty." << endl;
    } else {
        cout << "After clear, queue is not empty." << endl;
    }

    return 0;
}