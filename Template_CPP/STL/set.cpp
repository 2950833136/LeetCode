#include <iostream>
#include <set>
using namespace std;

void display(set<int> st) {
    if (st.empty()) {
        cout << "set is empty" << endl;
        return;
    }

    for (auto i : st) {
        cout << i << " ";
    }
    cout << endl;
}

int main() {
    set<int> st;

    // 添加
    st.insert(1);
    st.insert(3);
    st.insert(4);
    st.insert(5);
    cout << "初始集合为：";
    display(st);

    // 查找，查找不到返回 集合大小
    set<int>::iterator it = st.find(2); // 在set中查找2,返回其迭代器
    cout << *it << endl;

    // 删除一个元素
    st.erase(4);
    cout << "删除元素集合为：";
    display(st);

    // 求集合大小
    cout << st.size() << endl;

    // 清空集合
    st.clear();
    cout << "清空集合为：";
    display(st);

    return 0;
}