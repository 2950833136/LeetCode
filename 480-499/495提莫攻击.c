#include <stdio.h>

/**
 * 数组遍历
 *      - 如果小于持续时间，加上间隔时间
 *      - 否则（大于等于持续时间），加上持续时间
 */
int findPoisonedDuration(int* timeSeries, int timeSeriesSize, int duration) {
    int ans = 0;
    if (timeSeriesSize == 0) {
        return 0;
    }

    for (int i = 0; i < timeSeriesSize - 1; i++) {
        if (timeSeries[i] + duration > timeSeries[i + 1]) {
            ans += timeSeries[i + 1] - timeSeries[i];
        } else {
            ans += duration;
        }
    }
    ans += duration;
    return ans;
}

int main() {
    int timeSeries[]   = {1, 2, 3, 4, 5};
    int timeSeriesSize = sizeof(timeSeries) / sizeof(timeSeries[0]);
    int duration       = 5;

    int ans = findPoisonedDuration(timeSeries, timeSeriesSize, duration);
    printf("%d", ans);

    return 0;
}