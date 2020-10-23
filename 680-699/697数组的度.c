#include <malloc.h>
#include <stdio.h>

/**
 * hash 结构体记录信息
 *  - 利用 hash，即数值充当下标
 *  + 结构体含义
 *      - count:    出现次数
 *      - left:     第一次出现  
 *      - right:    更新，最后一次出现
 *  - 遍历求取频数最大的数即可
 *      - 同样频数，只记录最短长度
 */
struct hash {
    int count;
    int left;
    int right;
};

int findShortestSubArray(int* nums, int numsSize) {
    struct hash max = {0, -1, -1};
    struct hash myHash[50001];
    // left 和 right 会重新赋值，不完全初始化节省时间
    for (int i = 0; i < 50001; i++) {
        myHash[i].count = 0;
        // myHash[i].left  = -1;
        // myHash[i].right = -1;
    }

    for (int i = 0; i < numsSize; i++) {
        if (myHash[nums[i]].count == 0) {
            myHash[nums[i]].left = i;
        }
        myHash[nums[i]].count++;
        myHash[nums[i]].right = i;
        // printf("%d %d\n", nums[i], myHash[nums[i]].count);

        if (max.count <= myHash[nums[i]].count) {
            // 同样频数，只记录最短长度
            if (max.count == myHash[nums[i]].count && (max.right - max.left) < (myHash[nums[i]].right - myHash[nums[i]].left)) {
                continue;
            }
            max.count = myHash[nums[i]].count;
            max.left  = myHash[nums[i]].left;
            max.right = myHash[nums[i]].right;
        }
    }
    // printf("\n%d %d %d\n", max.count, max.left, max.right);
    return (max.right - max.left + 1);
}

/**
 * 精简，节省最后一次出现下标
 */
// #define HASH_LEN 50000
// struct MyHash {
//     int   num;
//     short first;
// };
// int findShortestSubArray(int* nums, int numsSize) {
//     struct MyHash* hash = calloc(HASH_LEN, sizeof(struct MyHash));

//     int space = 0;
//     int count = 0;
//     for (int i = 0; i < numsSize; i++) {
//         int index = nums[i];
//         if (hash[index].num == 0) {
//             hash[index].first = i;
//         }
//         hash[index].num++;
//         if (count < hash[index].num || (count == hash[index].num && space > i - hash[index].first)) {
//             space = i - hash[index].first + 1;
//             count = hash[index].num;
//         }
//     }
//     return space;
// }

int main() {
    int nums[]   = {2, 1, 1, 2, 1, 3, 3, 3, 1, 3, 1, 3, 2};
    int numsSize = sizeof(nums) / sizeof(nums[0]);

    int ans = findShortestSubArray(nums, numsSize);
    printf("%d", ans);

    return 0;
}