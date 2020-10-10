#include <stdio.h>

// /**
//  * 1、暴力遍历
//  */
// int numJewelsInStones(char* J, char* S) {
//     int ans = 0;
//     for (int i = 0; J[i] != '\0'; i++) {
//         for (int j = 0; S[j] != '\0'; j++) {
//             if (J[i] == S[j]) {
//                 ans++;
//             }
//         }
//     }
//     return ans;
// }

/**
 * 2、数组模拟哈希
 */
int numJewelsInStones(char* J, char* S) {
    int ans = 0;
    char hash[58] = {0};  // 'z' - 'A' + 1
    for (int i = 0; J[i] != '\0'; ++i) {
        hash[J[i] - 'A'] = J[i];
    }
    for (int j = 0; S[j] != '\0'; ++j) {
        if (hash[S[j] - 'A'] == S[j]) {
            ans++;
        }
    }
    return ans;
}

int main() {
    char* J = (char*)"aA";
    char* S = (char*)"aAAbbbb";
    int ans = numJewelsInStones(J, S);
    printf("%d", ans);

    return 0;
}