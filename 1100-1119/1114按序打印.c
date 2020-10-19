#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * 打印函数
 */
void printFirst() {
    printf("first\n");
}
void printSecond() {
    printf("second\n");
}
void printThird() {
    printf("third\n");
}

/**
 * 确保 second() 方法在 first() 方法之后被执行，third() 方法在 second() 方法之后被执行
 * 互斥锁机制执行
 *  + 两个互斥锁
 *      - 初始化为锁定状态
 *      + 为了能顺序执行，需要 mutex_1 限制 second，mutex_2 限制 third
 *          - 只有执行了 first 才解锁 mutex_1
 *          - 只有执行了 second 才解锁 mutex_2
 */
typedef struct {
    pthread_mutex_t mutex_1;
    pthread_mutex_t mutex_2;
} Foo;

Foo* fooCreate() {
    Foo* obj = (Foo*)malloc(sizeof(Foo));

    pthread_mutex_init(&obj->mutex_1, NULL);
    pthread_mutex_init(&obj->mutex_2, NULL);

    pthread_mutex_lock(&obj->mutex_1);
    pthread_mutex_lock(&obj->mutex_2);
    return obj;
}

void first(Foo* obj) {
    printFirst();
    pthread_mutex_unlock(&obj->mutex_1);
}

void second(Foo* obj) {
    pthread_mutex_lock(&obj->mutex_1);
    printSecond();
    pthread_mutex_unlock(&obj->mutex_1);
    pthread_mutex_unlock(&obj->mutex_2);
}

void third(Foo* obj) {
    pthread_mutex_lock(&obj->mutex_2);
    printThird();
    pthread_mutex_unlock(&obj->mutex_2);
}

void fooFree(Foo* obj) {
    pthread_mutex_destroy(&obj->mutex_1);
    pthread_mutex_destroy(&obj->mutex_2);
    free(obj);
}

int main() {
    Foo*           obj   = fooCreate();
    int            num[] = {1, 3, 2};
    
    pthread_t      myPthread[3];
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE); // 设置为合并属性，即可以使用 pthread_join()，执行完后自动释放

    for (int i = 0; i < 3; i++) {
        switch (num[i]) {
        case 1:
            pthread_create(&myPthread[i], NULL, (void*)&first, (void*)obj);
            break;
        case 2:
            pthread_create(&myPthread[i], NULL, (void*)&second, (void*)obj);
            break;
        case 3:
            pthread_create(&myPthread[i], NULL, (void*)&third, (void*)obj);
            break;
        }
    }

    for (int i = 0; i < 3; i++) {
        pthread_join(myPthread[i], NULL);
    }
    fooFree(obj);

    return 0;
}
