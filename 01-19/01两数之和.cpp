#include <malloc.h>
#include <stdio.h>
#include <string.h>

#define MAX_SIZE 2048

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int* res = (int*)malloc(sizeof(int) * 2);
    int hash[MAX_SIZE];
    memset(hash, -1, sizeof(hash));
    for (int i = 0; i < numsSize; i++) {
        if (hash[(target - nums[i] + MAX_SIZE) % MAX_SIZE] != -1) {
            res[0] = hash[(target - nums[i] + MAX_SIZE) % MAX_SIZE];
            res[1] = i;
            *returnSize = 2;
            return res;
        }
        hash[(nums[i] + MAX_SIZE) % MAX_SIZE] = i;
    }
    return res;
}

// int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
//     int* array = (int*)malloc(sizeof(int) * 2);
//     for (int i = 0; i < numsSize - 1; i++) {
//         for (int j = i + 1; j < numsSize; j++) {
//             if (nums[i] + nums[j] == target) {
//                 array[0] = i;
//                 array[1] = j;
//                 *returnSize = 2;
//                 return array;
//             }
//         }
//     }
//     return array;
// }

int main() {
    int nums[] = {2, 2, 3, 15};
    int numsSize = sizeof(nums) / sizeof(int);
    int target = 5;
    int* returnSize = (int*)malloc(sizeof(int));
    int* array = twoSum(nums, numsSize, target, returnSize);

    printf("%d ", array[0]);
    printf("%d ", array[1]);
    return 0;
}

// #include <iostream>
// #include <map>
// #include <string>
// #include <vector>
// using namespace std;

// class Solution {
//    public:
//     vector<int> twoSum(vector<int>& nums, int target) {
//         map<int, int> a;       //提供一对一的hash
//         vector<int> b(2, -1);  //用来承载结果，初始化一个大小为2，值为-1的容器b
//         for (int i = 0; i < nums.size(); i++) {
//             if (a.count(target - nums[i]) > 0) {
//                 b[0] = a[target - nums[i]];
//                 b[1] = i;
//                 break;
//             }
//             a[nums[i]] = i;  //反过来放入map中，用来获取结果下标
//         }
//         return b;
//     };
// };

// int main(void) {
//     Solution s;
//     vector<int> nums{2, 7, 9, 11};
//     int target = 9;
//     vector<int> out = s.twoSum(nums, target);
//     for (auto i = 0; i < out.size(); i++) {
//         cout << out[i] << " ";
//     }
// }
