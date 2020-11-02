#include <iostream>
#include <queue>
using namespace std;

// int main() {
//     priority_queue<int> q;
//     //入队四个元素：3，4，1，5。默认情况下数字越大，优先级越大
//     q.push(5);
//     q.push(4);
//     q.push(1);
//     q.push(3);

//     //出队队首元素：5
//     q.pop();

//     //访问队首元素
//     printf("%d\n", q.top());

//     //判断队列是否为空
//     if (q.empty()) {
//         printf("Empty\n");
//     } else {
//         printf("Not Empty\n");
//     }

//     //获取队列中剩余元素的个数
//     printf("%d", q.size());
// }

struct fruit {
    string name;
    int    price;
} f1, f2, f3;

struct cmp {
    bool operator()(fruit f1, fruit f2) {
        return f1.price < f2.price;
    }
};

int main() {
    priority_queue<fruit, vector<fruit>, cmp> q;
    f1.name  = "桃子";
    f1.price = 3;
    f2.name  = "梨子";
    f2.price = 4;
    f3.name  = "苹果";
    f3.price = 1;
    q.push(f1);
    q.push(f2);
    q.push(f3);
    cout << q.top().name << " " << q.top().price << endl;
    return 0;
}