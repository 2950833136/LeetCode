# STL

&emsp;在C++标准中，STL被组织为下面的13个头文件：\<algorithm>、\<deque>、\<functional>、\<iterator>、\<vector>、\<list>、\<map>、\<memory.h>、\<numeric>、\<queue>、\<set>、\<stack>、\<utility>。

&emsp;STL可分为容器(containers)、迭代器(iterators)、空间配置器(allocator)、配接器(adapters)、算法(algorithms)、仿函数(functors)六个部分。



## 1. 序列式容器

### 1.1 vector（向量）

简单地说，vector是一个能够存放**任意类型**的**动态数组**，能够增加和压缩数据。

#### （1）头文件

```cpp
#include <vector>
```

#### （2）命名空间

vector 属于 std 命名域的，因此需要通过命名限定：

```cpp
using std::vector;
vector<int> vInts;

或者连在一起，使用全名：
std::vector<int> vInts;

建议在代码量不大，并且使用的命名空间不多的情况下，使用全局的命名域方式
using namespace std;
```

#### （3）vector初始化

**方式1**

```cpp
//定义具有10个整型元素的向量（尖括号为元素类型名，它可以是任何合法的数据类型），不具有初值，其值不确定
vector<int> a(10);
```

**方式2**

```cpp
//定义具有10个整型元素的向量，且给出的每个元素初值为1
vector<int> a(10,1);
```

**方式3**

```cpp
//用向量b给向量a赋值，a的值完全等价于b的值
vector<int> a(b);
```

**方式4**

```cpp
//将向量b中从0-2（共三个）的元素赋值给a，a的类型为int型
vector<int> a(b.begin(),b.begin+3);
```

**方式5**

```cpp
//从数组中获得初值
int b[7]={1,2,3,4,5,6,7};
vector<int> a(b,b+7）;
```

#### （4）vector对象的常用内置函数使用（举例说明）

```cpp
#include<vector>
vector<int> a,b;
//b为向量，将b的0-2个元素赋值给向量a
a.assign(b.begin(),b.begin()+3);
//a含有4个值为2的元素
a.assign(4,2);
//返回a的最后一个元素
a.back();
//返回a的第一个元素
a.front();
//返回a的第i元素,当且仅当a存在
a[i];
//清空a中的元素
a.clear();
//判断a是否为空，空则返回true，非空则返回false
a.empty();
//删除a向量的最后一个元素
a.pop_back();
//删除a中第一个（从第0个算起）到第二个元素，也就是说删除的元素从a.begin()+1算起（包括它）一直到a.begin()+3（不包括它）结束
a.erase(a.begin()+1,a.begin()+3);
//在a的最后一个向量后插入一个元素，其值为5
a.push_back(5);
//在a的第一个元素（从第0个算起）位置插入数值5,
a.insert(a.begin()+1,5);
//在a的第一个元素（从第0个算起）位置插入3个数，其值都为5
a.insert(a.begin()+1,3,5);
//b为数组，在a的第一个元素（从第0个元素算起）的位置插入b的第三个元素到第5个元素（不包括b+6）
a.insert(a.begin()+1,b+3,b+6);
//返回a中元素的个数
a.size();
//返回a在内存中总共可以容纳的元素个数
a.capacity();
//将a的现有元素个数调整至10个，多则删，少则补，其值随机
a.resize(10);
//将a的现有元素个数调整至10个，多则删，少则补，其值为2
a.resize(10,2);
//将a的容量扩充至100，
a.reserve(100);
//b为向量，将a中的元素和b中的元素整体交换
a.swap(b);
//b为向量，向量的比较操作还有 != >= > <= <
a==b;
```

#### （5）几个常用的算法

```cpp
#include<algorithm>
//对a中的从a.begin()（包括它）到a.end()（不包括它）的元素进行从小到大排列
sort(a.begin(),a.end());
//对a中的从a.begin()（包括它）到a.end()（不包括它）的元素倒置，但不排列，如a中元素为1,3,2,4,倒置后为4,2,3,1
reverse(a.begin(),a.end());
//把a中的从a.begin()（包括它）到a.end()（不包括它）的元素复制到b中，从b.begin()+1的位置（包括它）开始复制，覆盖掉原有元素
copy(a.begin(),a.end(),b.begin()+1);
//在a中的从a.begin()（包括它）到a.end()（不包括它）的元素中查找10，若存在返回其在向量中的位置
find(a.begin(),a.end(),10);
```



### 1.2 list （队列）

Lists将元素按顺序储存在链表中与向量(vectors)相比, 它允许快速的插入和删除，但是随机访问却比较慢。

#### （1）函数

```cpp
assign() 	给list赋值 
back() 		返回最后一个元素 
begin() 	返回指向第一个元素的迭代器 
clear() 	删除所有元素 
empty() 	如果list是空的则返回true 
end() 		返回末尾的迭代器 
erase() 	删除一个元素 
front() 	返回第一个元素 
get_allocator() 返回list的配置器 
insert() 	插入一个元素到list中 
max_size() 	返回list能容纳的最大元素数量 
merge() 	合并两个list 
pop_back() 	删除最后一个元素 
pop_front() 删除第一个元素 
push_back() 在list的末尾添加一个元素 
push_front() 在list的头部添加一个元素 
rbegin() 	返回指向第一个元素的逆向迭代器 
remove() 	从list删除元素 
remove_if() 按指定条件删除元素 
rend() 		指向list末尾的逆向迭代器 
resize() 	改变list的大小 
reverse() 	把list的元素倒转 
size() 		返回list中的元素个数 
sort() 		给list排序 
splice() 	合并两个list 
swap() 		交换两个list 
unique() 	删除list中重复的元素
```

#### （2）实例

```cpp
#include <iostream>
#include <list>
#include <vector>
using namespace std;

//从前向后显示list队列的全部元素
void put_list(list<int> List, char* name) {
    list<int>::iterator plist;

    cout << "The contents of " << name << " : ";
    for (plist = List.begin(); plist != List.end(); plist++) {
        cout << *plist << " ";
    }
    cout << endl;
}

//测试list容器的功能
int main() {
    //list1对象初始为空
    list<int> list1;
    char*     list1_name = (char*)"list1";
    //list2对象最初有10个值为6的元素
    list<int> list2(10, 6);
    char*     list2_name = (char*)"list2";
    //list3对象最初有3个元素
    vector<int> nums = {1, 2, 3, 4, 5, 6};
    list<int>   list3(nums.begin(), nums.begin() + 3);
    char*       list3_name = (char*)"list3";

    //声明一个名为i的双向迭代器
    list<int>::iterator i;

    //从前向后显示各list对象的元素
    put_list(list1, list1_name);
    put_list(list2, list2_name);
    put_list(list3, list3_name);

    //从list1序列后面添加两个元素
    list1.push_back(2);
    list1.push_back(4);
    cout << "list1.push_back(2) and list1.push_back(4):" << endl;
    put_list(list1, list1_name);

    //从list1序列前面添加两个元素
    list1.push_front(5);
    list1.push_front(7);
    cout << "list1.push_front(5) and list1.push_front(7):" << endl;
    put_list(list1, list1_name);

    //在list1序列中间插入数据
    list1.insert(++list1.begin(), 3, 9);
    cout << "list1.insert(list1.begin()+1,3,9):" << endl;
    put_list(list1, list1_name);

    //测试引用类函数
    cout << "list1.front()=" << list1.front() << endl;
    cout << "list1.back()=" << list1.back() << endl;

    //从list1序列的前后各移去一个元素
    list1.pop_front();
    list1.pop_back();
    cout << "list1.pop_front() and list1.pop_back():" << endl;
    put_list(list1, list1_name);

    //清除list1中的第2个元素
    list1.erase(++list1.begin());
    cout << "list1.erase(++list1.begin()):" << endl;
    put_list(list1, list1_name);

    //对list2赋值并显示
    list2.assign(8, 1);
    cout << "list2.assign(8,1):" << endl;
    put_list(list2, list2_name);

    //显示序列的状态信息
    cout << "list1.max_size(): " << list1.max_size() << endl;
    cout << "list1.size(): " << list1.size() << endl;
    cout << "list1.empty(): " << list1.empty() << endl;

    //list序列容器的运算
    put_list(list1, list1_name);
    put_list(list3, list3_name);
    cout << "list1>list3: " << (list1 > list3) << endl;
    cout << "list1<list3: " << (list1 < list3) << endl;

    //对list1容器排序
    list1.sort();
    put_list(list1, list1_name);

    //结合处理
    list1.splice(++list1.begin(), list3);
    put_list(list1, list1_name);
    put_list(list3, list3_name);

    return 0;
}
```



### 1.3 deque（**双端队列**） 

#### （1） 与 vector 比较

deque 容器和 vecotr 容器相同处：

- deque 容器也擅长在序列尾部添加或删除元素（时间复杂度为`O(1)`），而不擅长在序列中间添加或删除元素。
- deque 容器也可以根据需要修改自身的容量和大小。

deque 容器和 vecotr 容器不同处：

- deque 还擅长在序列头部添加或删除元素，所耗费的时间复杂度也为常数阶`O(1)`。
- deque 容器中存储元素并不能保证所有元素都存储到连续的内存空间中。

**当需要向序列两端频繁的添加或删除元素时，应首选 deque 容器。**

#### （2）函数

| 函数成员         | 函数功能                                                     |
| ---------------- | ------------------------------------------------------------ |
| begin()          | 返回指向容器中第一个元素的迭代器。                           |
| end()            | 返回指向容器最后一个元素所在位置后一个位置的迭代器，通常和 begin() 结合使用。 |
| rbegin()         | 返回指向最后一个元素的迭代器。                               |
| rend()           | 返回指向第一个元素所在位置前一个位置的迭代器。               |
| cbegin()         | 和 begin() 功能相同，只不过在其基础上，增加了 const 属性，不能用于修改元素。 |
| cend()           | 和 end() 功能相同，只不过在其基础上，增加了 const 属性，不能用于修改元素。 |
| crbegin()        | 和 rbegin() 功能相同，只不过在其基础上，增加了 const 属性，不能用于修改元素。 |
| crend()          | 和 rend() 功能相同，只不过在其基础上，增加了 const 属性，不能用于修改元素。 |
| size()           | 返回实际元素个数。                                           |
| max_size()       | 返回容器所能容纳元素个数的最大值。这通常是一个很大的值，一般是 232-1，我们很少会用到这个函数。 |
| resize()         | 改变实际元素的个数。                                         |
| empty()          | 判断容器中是否有元素，若无元素，则返回 true；反之，返回 false。 |
| shrink _to_fit() | 将内存减少到等于当前元素实际所使用的大小。                   |
| at()             | 使用经过边界检查的索引访问元素。                             |
| front()          | 返回第一个元素的引用。                                       |
| back()           | 返回最后一个元素的引用。                                     |
| assign()         | 用新元素替换原有内容。                                       |
| push_back()      | 在序列的尾部添加一个元素。                                   |
| push_front()     | 在序列的头部添加一个元素。                                   |
| pop_back()       | 移除容器尾部的元素。                                         |
| pop_front()      | 移除容器头部的元素。                                         |
| insert()         | 在指定的位置插入一个或多个元素。                             |
| erase()          | 移除一个元素或一段元素。                                     |
| clear()          | 移出所有的元素，容器大小变为 0。                             |
| swap()           | 交换两个容器的所有元素。                                     |
| emplace()        | 在指定的位置直接生成一个元素。                               |
| emplace_front()  | 在容器头部生成一个元素。和 push_front() 的区别是，该函数直接在容器头部构造元素，省去了复制移动元素的过程。 |
| emplace_back()   | 在容器尾部生成一个元素。和 push_back() 的区别是，该函数直接在容器尾部构造元素，省去了复制移动元素的过程。 |



#### （3）实例

```cpp
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
```



### 1.4 对比

 **vector ：** vector和built-in数组类似，拥有一段连续的内存空间，能非常好的支持随即存取，即[]操作符，但由于它的内存空间是连续的，所以在中间进行插入和删除会造成内存块的拷贝。当插入较多的元素后，预留内存空间可能不够，需要重新申请一块足够大的内存并把原来的数据拷贝到新的内存空间。这些影响了vector的效率，但是实际上用的最多的还是vector容器，建议大多数时候使用vector效率一般是不错的。

 **list：** list就是数据结构中的双向链表(根据sgi stl源代码)，因此它的内存空间是不连续的，通过指针来进行数据的访问，这个特点使得它的随即存取变的非常没有效率，因此它没有提供[]操作符的重载。但由于链表的特点，它可以以很好的效率支持任意地方的删除和插入。

 **deque：** deque是一个double-ended  queue，它具有以下两个特点：它支持[]操作符，也就是支持随即存取，并且和vector的效率相差无几，它支持在两端的操作：push_back,push_front,pop_back,pop_front等，并且在两端操作上与list的效率也差不多。



## 参考资料

(1) [C++_vector操作](https://blog.csdn.net/weixin_41743247/article/details/90635931): https://blog.csdn.net/weixin_41743247/article/details/90635931

(2) [C++中list用法详解](https://blog.csdn.net/yas12345678/article/details/52601578/): https://blog.csdn.net/yas12345678/article/details/52601578/

(3) [C++ STL deque容器（详解版）](http://c.biancheng.net/view/6860.html): http://c.biancheng.net/view/6860.html