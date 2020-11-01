#include <iostream>
#include <vector>
using namespace std;

/**
 * 序列式容器： 向量(vector) 连续存储的元素 <vector>
 */
int main() {
    vector<string> wordDict = {"cat", "cats", "and", "sand", "dog"};

    /**
     * 遍历方式
     *  1. 通过数组下标遍历
     *  2. 通过迭代器遍历
     *  3. C++11标准，auto关键字遍历
     */
    for (int i = 0; i < wordDict.size(); i++) {
        cout << wordDict[i] << " ";
    }
    cout << endl;

    vector<string>::iterator item = wordDict.begin();
    for (; item != wordDict.end(); item++) {
        cout << *item << " ";
    }
    cout << endl;

    for (auto i : wordDict) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}