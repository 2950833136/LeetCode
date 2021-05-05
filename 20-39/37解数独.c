#include <malloc.h>
#include <stdio.h>
#include <string.h>

// 遍历输出
void displayChar(char** board) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            printf("%c ", *(*(board + i) + j));
        }
        printf("\n");
    }
    printf("\n");
}

// 16 进制转 2进制
char* HextoTwo(int num, char* byte) {
    if (num == 0) {
        return byte;
    }
    char buf[2][1] = {'0', '1'};
    int  remainder = num % 2;
    byte           = HextoTwo((num >> 1), byte);
    strncat(byte, buf[remainder], 1);
    return byte;
}

/**
 *   使用回溯方法解题：
 *   1、设置三个变量数组row、col、metrix，分别使用1bit表示当前行、列、3*3小矩形内的数字出现情况（0~9bit分别表示0到9）
 *   2、从(0,0)开始遍历到(8,8),依次从小到大放置可能的数字，放置数字后，刷新row、col、metrix;
 *   3、如果某个位置无可能放置的数字，则回溯，回溯前需要恢复现场，把row、col、metrix对应位置状态还原
 *
 *   什么是可能放置的数字，输入：行标i,列标j,矩阵索引k，得出还未出现的数字，即ans = row | col |
 * metrix，取ans中bit为0对应的 数字。
 *
 *   如何恢复现场？ 输入数字n，i,j,k，把row col metrix对应数字n的bit清0即可
 *
 *   备注此题的写法可作为多维数组回溯写法的模板
 *       先遍历单元格的取值，再遍历一行中所有列对应单元格的取值，再遍历行数
 *
 */
#define NUM 9

char** g_board;
int    g_rowNum, g_colNum;
int    g_rowState[NUM], g_colState[NUM], g_metrixState[NUM];

void Init(void) {
    memset(g_rowState, 0, NUM * sizeof(int));
    memset(g_colState, 0, NUM * sizeof(int));
    memset(g_metrixState, 0, NUM * sizeof(int));
}

// 计算九宫格下标，从左到右，从上到下，依次为012，345，678
int GetMetrixIndex(int row, int col) {
    return row / 3 + 3 * (col / 3);
}

// 移位得到当前数值转换为 9 字节的位置，置为 1
inline void SetState(int* state, int num) {
    *state |= (0x1 << num);
}

// 恢复现场，1取反相与为 0
inline void ClearState(int* state, int num) {
    *state &= (~(0x1 << num));
}

/**
生成 行、列、九宮格 的 bit 型数据，与 '0' 相比偏移，0 位默认 0
    pre:    5 3 . . 7 . . . .
            6 . . 1 9 5 . . .
            . 9 8 . . . . 6 .
            8 . . . 6 . . . 3
            4 . . 8 . 3 . . 1
            7 . . . 2 . . . 6
            . 6 . . . . 2 8 .
            . . . 4 1 9 . . 5
            . . . . 8 . . 7 9
    row[0]: 0 0 1 0 1 0 1 0 0  => 0x54
    col[0]: 0 1 1 1 1 1 0 0 0  => 0xf8
    met[0]: 1 1 0 1 1 0 1 0 0  => 0x1b4
 */
void SetAllState(int value, int rowIndex, int colIndex) {
    int index = GetMetrixIndex(rowIndex, colIndex);
    SetState(&g_rowState[rowIndex], value);
    SetState(&g_colState[colIndex], value);
    SetState(&g_metrixState[index], value);
}

void ClearAllState(int value, int rowIndex, int colIndex) {
    int index = GetMetrixIndex(rowIndex, colIndex);
    ClearState(&g_rowState[rowIndex], value);
    ClearState(&g_colState[colIndex], value);
    ClearState(&g_metrixState[index], value);
}

/**
 * 得到填入数据状态 1-存在，0-不存在
 */
bool GetState(int value, int rowIndex, int colIndex) {
    int index = GetMetrixIndex(rowIndex, colIndex);
    int state = g_rowState[rowIndex] | g_colState[colIndex] | g_metrixState[index];
    return (bool)(state & (0x1 << value));
}

// 生成所有 行、列、九宮格 的 bit 型数据
void GenerateState(char** board, int rowNum, int colNum) {
    int i, j, value;
    for (i = 0; i < rowNum; i++) {
        for (j = 0; j < colNum; j++) {
            if (board[i][j] != '.') {
                value = (int)(board[i][j] - '1');
                SetAllState(value, i, j);
            }
        }
    }
}

int BackTrace(int row, int col) {
    if (col == g_colNum) {
        col = 0;
        row++;
        if (row == g_rowNum) {
            return 1;
        }
    }
    if (g_board[row][col] == '.') {
        for (int num = 0; num < 9; num++) {
            if (GetState(num, row, col) == 1) {
                continue;
            }
            g_board[row][col] = (char)(num + '1');
            // 填充相关值
            SetAllState(num, row, col);
            // 这一行很关键，决定是否做恢复现场的处理，只有失败时才恢复现场，做回溯处理，成功时继续往下走
            if (BackTrace(row, col + 1) == 1) {
                return 1;
            }
            // 恢复现场的处理
            g_board[row][col] = '.';
            ClearAllState(num, row, col);
        }
    } else {
        return BackTrace(row, col + 1);
    }
    return 0;
}

void solveSudoku(char** board, int boardSize, int* boardColSize) {
    g_board  = board;
    g_rowNum = boardSize;
    g_colNum = *boardColSize;
    Init();
    GenerateState(board, g_rowNum, g_colNum);

    char byte[NUM + 1];
    for (int i = 0; i < 9; i++) {
        memset(byte, 0, sizeof(byte));
        printf("rowState[%d] = %09s\t\t", i, HextoTwo(g_rowState[i], byte));
        memset(byte, 0, sizeof(byte));
        printf("colState[%d] = %09s\t\t", i, HextoTwo(g_colState[i], byte));
        memset(byte, 0, sizeof(byte));
        printf("metrixState[%d] = %09s\n", i, HextoTwo(g_metrixState[i], byte));
        // printf("rowState[%d] = 0x%-10x", i, g_rowState[i]);
        // printf("colState[%d] = 0x%-10x", i, g_colState[i]);
        // printf("metrixState[%d] = 0x%-10x\n", i, g_metrixState[i]);
    }

    BackTrace(0, 0);
}

int main() {
    char arr[][9] = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'},
    };
    char** board = (char**)malloc(sizeof(char*) * 9);
    for (int i = 0; i < 9; i++) {
        *(board + i) = arr[i];
    }
    int  boardSize    = 9;
    int* boardColSize = (int*)malloc(sizeof(int));
    *boardColSize     = 9;

    // displayChar(board);
    solveSudoku(board, boardSize, boardColSize);
    displayChar(board);

    return 0;
}