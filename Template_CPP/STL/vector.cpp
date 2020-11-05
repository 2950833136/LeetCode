#include <iostream>
#include <vector>
using namespace std;

/**
 * 遍历方式
 *  1. 通过数组下标遍历
 *  2. 通过迭代器遍历
 *  3. C++11标准，auto关键字遍历
 */
void display1(vector<string> wordDict) {
    for (int i = 0; i < wordDict.size(); i++) {
        cout << wordDict[i] << " ";
    }
    cout << endl;
}

void display2(vector<string> wordDict) {
    vector<string>::iterator item = wordDict.begin();
    for (; item != wordDict.end(); item++) {
        cout << *item << " ";
    }
    cout << endl;
}

void display3(vector<string> wordDict) {
    for (auto i : wordDict) {
        cout << i << " ";
    }
}
/**
 * 序列式容器： 向量(vector) 连续存储的元素 <vector>
 */
int main() {
    vector<string> wordDict = {"cat", "cats", "and", "sand", "dog"};

    display1(wordDict);
    display2(wordDict);
    display3(wordDict);

    return 0;
}