#include <stdio.h>

int game(int* guess, int guessSize, int* answer, int answerSize) {
    int ans = 0;
    while (answerSize--) {
        ans += *(guess++) == *(answer++);
    }
    return ans;
}

int main() {
    int guess[] = {1, 2, 3};
    int guessSize = sizeof(guess) / sizeof(int);
    int answer[] = {1, 2, 3};
    int answerSize = sizeof(answer) / sizeof(int);

    int ans = game(guess, guessSize, answer, answerSize);
    printf("%d", ans);

    return 0;
}