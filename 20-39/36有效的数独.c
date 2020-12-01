#include <malloc.h>
#include <stdio.h>

/**
 * 1、暴力法
 */
bool find(char* array, int arraySize) {
    for (int i = 0; i < arraySize - 1; i++) {
        for (int j = i + 1; j < arraySize; j++) {
            if (array[i] == '.' || array[j] == '.') {
                continue;
            } else if (array[i] == array[j]) {
                return false;
            }
        }
    }
    return true;
}

bool isValidSudoku(char** board, int boardSize, int* boardColSize) {
    char array[9];
    // 横向比较
    for (int i = 0; i < boardSize; i++) {
        for (int j = 0; j < *boardColSize; j++) {
            array[j] = *((*(board + i)) + j);
        }
        if (!find(array, boardSize)) {
            return false;
        }
    }

    // 纵向比较
    for (int i = 0; i < boardSize; i++) {
        for (int j = 0; j < *boardColSize; j++) {
            array[j] = *((*(board + j)) + i);
        }
        if (!find(array, *boardColSize)) {
            return false;
        }
    }

    // 九宫格比较
    for (int m = 0; m < 3; m++) {
        for (int n = 0; n < 3; n++) {
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    array[i * 3 + j] = *(*(board + 3 * m + i) + 3 * n + j);
                }
            }
            if (!find(array, boardSize)) {
                return false;
            }
        }
    }
    return true;
}

/**
 * 2、查看是否存在，以 '0' 做相对位移下标
 * 关键是在行列的计算
 */
// bool isValidSudoku(char** board, int boardSize, int* boardColSize) {
//     int i, j;
//     int x, temp;
//     int row[9][9] = {0};
//     int col[9][9] = {0};
//     int box[9][9] = {0};
//     for (i = 0; i < 9; i++) {
//         for (j = 0; j < 9; j++) {
//             if (board[i][j] == '.') continue;
//             temp = board[i][j] - '1';
//             if (row[i][temp] == 1) return false;  // 查找行
//             if (col[j][temp] == 1) return false;  // 查找列
//             x = j / 3 + 3 * (i / 3);
//             if (box[x][temp] == 1) return false;  // 查找box

//             row[i][temp] = 1;
//             col[j][temp] = 1;
//             box[x][temp] = 1;
//         }
//     }
//     return true;
// }

int main() {
    char** board = (char**)malloc(sizeof(char*) * 9);
    char arr[][9] = {
        {'.', '.', '4', '.', '.', '.', '6', '3', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'5', '.', '.', '.', '.', '.', '.', '9', '.'},
        {'.', '.', '.', '5', '6', '.', '.', '.', '.'},
        {'4', '.', '3', '.', '.', '.', '.', '.', '1'},
        {'.', '.', '.', '7', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '5', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.', '.'},
    };
    for (int i = 0; i < 9; i++) {
        *(board + i) = &arr[i][0];
    }

    // 二级指针表示二维数组     *(*(board + i) + j)
    // for (int i = 0; i < 9; i++) {
    //     for (int j = 0; j < 9; j++) {
    //         printf("%c ", *(*(board + i) + j));
    //     }
    //     printf("\n");
    // }

    int boardSize = 9;
    int* boardColSize = (int*)malloc(sizeof(int));
    *boardColSize = 9;

    if (isValidSudoku(board, boardSize, boardColSize)) {
        printf("true");
    } else {
        printf("false");
    }

    return 0;
}