#include <math.h>
#include <stdio.h>
#include <string.h>

/**
 * dp[i] = dp[i - 2] + 2
 * dp[i] = dp[i - 1] + dp[i - dp[i - 1] - 2] + 2
 */
int longestValidParentheses(char* s) {
    int max_ans = 0;
    int n = strlen(s);
    if (n == 0) {
        return 0;
    }
    int dp[n];
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i < n; i++) {
        if (s[i] == ')') {
            if (s[i - 1] == '(') {
                // 防止数组边界溢出
                dp[i] = (i - 2 >= 0 ? dp[i - 2] : 0) + 2;
            } else if ((i - dp[i - 1] - 1) >= 0 && s[i - dp[i - 1] - 1] == '(') {
                // 防止数组边界溢出
                dp[i] = dp[i - 1] + ((i - dp[i - 1] - 2) >= 0 ? dp[i - dp[i - 1] - 2] : 0) + 2;
            }
            max_ans = fmax(max_ans, dp[i]);
        }
    }
    return max_ans;
}

int main() {
    char* s = (char*)")()())";
    int max_ans = longestValidParentheses(s);
    printf("%d", max_ans);
    return 0;
}