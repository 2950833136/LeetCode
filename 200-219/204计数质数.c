#include <stdbool.h>
#include <stdio.h>
#include <string.h>

/**
 * 方法一：开根号枚举
 * 
 * 时间复杂度：O(n sqrt(n)) 
 * 空间复杂度：O(1)
 */
// bool isPrime(int x) {
//     for (int i = 2; i * i <= x; ++i) {
//         if (x % i == 0) {
//             return false;
//         }
//     }
//     return true;
// }

// int countPrimes(int n) {
//     int ans = 0;
//     for (int i = 2; i < n; ++i) {
//         ans += isPrime(i);
//     }
//     return ans;
// }

/**
 * 方法二：埃氏筛
 *  - 如果 x 是质数，那么大于 x 的 x 的倍数 2x,3x,… 一定不是质数
 *      - 我们设 isPrime[i] 表示数 i 是不是质数，如果是质数则为 1，否则为 0
 *      - 从小到大遍历每个数，如果这个数为质数，则将其所有的倍数都标记为合数（除了该质数本身），即 0
 *      - 这样在运行结束的时候我们即能知道质数的个数。
 * 
 * 时间复杂度：O(nlogn)
 * 空间复杂度：O(n)
 */
// int countPrimes(int n) {
//     if (n < 2) {
//         return 0;
//     }
//     int isPrime[n];
//     memset(isPrime, 0, sizeof(isPrime));
//     int ans = 0;
//     for (int i = 2; i < n; ++i) {
//         if (!isPrime[i]) {
//             ans += 1;
//             if ((long long)i * i < n) {
//                 for (int j = i * i; j < n; j += i) {
//                     isPrime[j] = 1;
//                 }
//             }
//         }
//     }
//     return ans;
// }

/**
 * 方法三：线性筛
 *  - 相较于埃氏筛，我们多维护一个 primes 数组表示当前得到的质数集合。我们从小到大遍历，如果当前的数 x 是质数，就将其加入 primes 数组
 *  - 标记质数集合中的数与 x 相乘的数
 *  - 在 埃氏筛 基础上，保证了每个合数只会被其「最小的质因数」筛去，即每个合数被标记一次。
 * 
 * 时间复杂度：O(n)
 * 空间复杂度：O(n)
 */
int countPrimes(int n) {
    if (n < 2) {
        return 0;
    }
    int isPrime[n];
    int primes[n], primesSize = 0;
    memset(isPrime, 0, sizeof(isPrime));
    for (int i = 2; i < n; ++i) {
        if (!isPrime[i]) {
            primes[primesSize++] = i;
        }
        for (int j = 0; j < primesSize && i * primes[j] < n; ++j) {
            isPrime[i * primes[j]] = 1;
            if (i % primes[j] == 0) {
                break;
            }
        }
    }
    return primesSize;
}

int main(int argc, char* argv[]) {
    int n = 10;

    int ret = countPrimes(n);
    printf("%d", ret);

    return 0;
}