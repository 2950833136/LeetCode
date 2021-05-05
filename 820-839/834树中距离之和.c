/**
 * 超时版
 * 需要修改 MAXV（最大结点个数）、N（节点个数）
 * 开始看到无向连通的树，想到的是父节点加 n 多子节点，可惜实现不来
 * 然后想到无向图
 *  1、创建矩阵——无向图
 *  2、创建邻接表
 *  3、深度优先遍历
 * 最后发现在 64/69 时超时，白写了。
 */
#include <malloc.h>
#include <stdio.h>
#include <string.h>

#define MAXV 10000

// 节点
typedef struct vertexNode {
    int value;
    struct vertexNode* next;
} VNode;

// 邻接表
typedef struct adjacencyList {
    VNode adjlist[MAXV];
} AdjList;

// 矩阵输出
void display(int** matrix, int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}
// 输出邻接表
void displayAdj(AdjList* L, int N) {
    VNode* p;
    for (int i = 0; i < N; i++) {
        p = L->adjlist[i].next;
        printf("%3d:", i);
        while (p != NULL) {
            printf("%3d->", p->value);
            p = p->next;
        }
        printf("\n");
    }
}

// 初始化矩阵
void initMatrix(int** matrix, int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            matrix[i][j] = 0;
        }
    }
}

// 创建矩阵——无向图
void BuildMatrix(int** edges, int edgesSize, int N, int** matrix) {
    for (int i = 0; i < edgesSize; ++i) {
        // 行、列
        int row = edges[i][0];
        int col = edges[i][1];
        matrix[row][col] = 1;
        matrix[col][row] = 1;
    }
}

// 创建邻接表
AdjList* createAdj(int N, int** matrix) {
    AdjList* L = (AdjList*)malloc(sizeof(AdjList));
    for (int i = 0; i < N; i++) {
        L->adjlist[i].next = NULL;
    }
    for (int i = 0; i < N; i++) {
        for (int j = N - 1; j >= 0; j--) {
            if (matrix[i][j] != 0) {
                VNode* node = (VNode*)malloc(sizeof(VNode));
                node->value = j;
                node->next = L->adjlist[i].next;
                L->adjlist[i].next = node;
            }
        }
    }
    displayAdj(L, N);
    return L;
}

// 深度优先遍历
void DFS(AdjList* L, int* visited, int vertex, int distance, int* distances) {
    VNode* p;
    visited[vertex] = 1;
    distance++;
    // printf("%d ", vertex);
    p = L->adjlist[vertex].next;
    while (p != NULL) {
        if (visited[p->value] == 0) {
            *distances = *distances + distance;
            DFS(L, visited, p->value, distance, distances);
        }
        p = p->next;
    }
}

int* sumOfDistancesInTree(int N, int** edges, int edgesSize, int* edgesColSize, int* returnSize) {
    int** matrix = (int**)malloc(sizeof(int*) * N);
    for (int i = 0; i < N; i++) {
        matrix[i] = (int*)malloc(sizeof(int) * N);
    }
    initMatrix(matrix, N);
    BuildMatrix(edges, edgesSize, N, matrix);

    AdjList* L = (AdjList*)malloc(sizeof(AdjList));
    L = createAdj(N, matrix);

    int* returnNums = (int*)malloc(sizeof(int) * N);
    memset(returnNums, 0, sizeof(returnNums));
    for (int i = 0; i < N; i++) {
        int distance = 0;
        int* distances = (int*)malloc(sizeof(int));
        *distances = 0;
        int visited[MAXV] = {0};
        DFS(L, visited, i, distance, distances);
        // printf("%d ", *distances);
        returnNums[i] = *distances;
    }
    *returnSize = N;
    return returnNums;
}

int main() {
    int arr[][2] = {
        {0, 1},
        {0, 2},
        {2, 3},
        {2, 4},
        {2, 5},
    };
    int N = 6;
    int edgesSize = (sizeof(arr) / sizeof(arr[0]));

    int** edges = (int**)malloc(sizeof(int*) * edgesSize);
    for (int i = 0; i < edgesSize; i++) {
        *(edges + i) = &arr[i][0];
    }

    int* edgesColSize = (int*)malloc(sizeof(int));
    int* returnSize = (int*)malloc(sizeof(int));

    int* ret = (int*)malloc(sizeof(int));
    ret = sumOfDistancesInTree(N, edges, edgesSize, edgesColSize, returnSize);

    for (int i = 0; i < *returnSize; i++) {
        printf("%d ", ret[i]);
    }
    return 0;
}

// /**
//  * 通过测试版
//  */
// #include <malloc.h>
// #include <stdio.h>
// #include <string.h>

// #define MAX_POINTS 10000
// #define MAX_EDGES 20

// typedef struct Node {
//     int point;
// } Node;

// typedef struct {
//     int count;
//     Node nodes[MAX_EDGES];
// } Matrix;
// Matrix matrix[MAX_POINTS];

// void BuildMatrix(int** edges, int edgesSize) {
//     for (int i = 0; i < edgesSize; ++i) {
//         int from = edges[i][0];
//         int to = edges[i][1];

//         int count = matrix[from].count;
//         matrix[from].nodes[count].point = to;
//         matrix[from].count++;

//         count = matrix[to].count;
//         matrix[to].nodes[count].point = from;
//         matrix[to].count++;
//     }
// }

// void DFS4SubTree(int n, int childs[], int distance[], int parent, int node) {
//     // 统计父结点为 parent，以 node 为根的孩子结点的个数(childs，包含自身)以及 node 到所有孩子结点的路径和(distance)
//     for (int i = 0; i < matrix[node].count; ++i) {
//         int child = matrix[node].nodes[i].point;
//         if (child != parent) {
//             DFS4SubTree(n, childs, distance, node, child);
//             childs[node] += childs[child];
//             distance[node] += distance[child] + childs[child];
//         }
//     }
// }

// void DFS4Adjacent(int n, int childs[], int distance[], int parent, int node) {
//     // 根据 node 与孩子结点的关系, 更新路径和
//     // 公式: distance[child] = distance[node] - 2 * childs[child] + N
//     /* 推导过程：
//     第一步，以某个结点 node 为根，Tree(node) 表示以 node 为根的子树(包含 node 自身)。
//     通过递归算出 Tree(node) 中结点的个数 childs[node]，并算出 Tree(node) 中所有结点到 node 的距离 distance[node]。
//     其中：childs[node] = sum(childs[child]) + 1 (1 指 node 自身)。
//     distance[node] = sum(distance[child] + childs[child])。
//     第二步：对于两个相邻结点 A 和 B，切断他们的连接关系，就得到两个子树：Tree(A)、Tree(B)，A 到其他所有结点的距离和 result[A] 等于 A 子树中所有结点到
//     A 结点的距离和 distance[A] 加上 B 子树中所有结点到 B 结点的距离和 distance[B] 加上 B 子树的大小 childs[B]： result[A] = distance[A] + distance[B]
//     + childs[B]。 同理，result[B] = distance[B] + distance[A] + childs[A]。其中 N(原始树中结点总数) = childs[A] + childs[B]。
//     那么，两个相邻接点的解之间的关系为：result[A] = result[B] - childs[A] + childs[B] = result[B] - childs[A] + (N - childs[A]);
//     因此，对于根结点 node 的任意子结点 child：distance[child] = distance[root] - 2 * childs[child] + N。
//     */
//     for (int i = 0; i < matrix[node].count; ++i) {
//         int child = matrix[node].nodes[i].point;
//         if (child != parent) {
//             distance[child] = distance[node] - 2 * childs[child] + n;
//             DFS4Adjacent(n, childs, distance, node, child);
//         }
//     }
// }

// /**
//  * Note: The returned array must be malloced, assume caller calls free().
//  */
// int* sumOfDistancesInTree(int N, int** edges, int edgesSize, int* edgesColSize, int* returnSize) {
//     if (N <= 0) {
//         *returnSize = 0;
//         return NULL;
//     }

//     memset(matrix, 0, sizeof(Matrix) * N);
//     BuildMatrix(edges, edgesSize);
//     int childs[N];
//     for (int i = 0; i < N; ++i) {
//         childs[i] = 1;
//     }

//     int* distance = (int*)malloc(sizeof(int) * N);
//     memset(distance, 0, sizeof(int) * N);
//     DFS4SubTree(N, childs, distance, -1, 0);
//     DFS4Adjacent(N, childs, distance, -1, 0);

//     *returnSize = N;
//     return distance;
// }

// int main() {
//     int arr[][2] = {
//         {0, 1},
//         {0, 2},
//         {2, 3},
//         {2, 4},
//         {2, 5},
//     };
//     int N = 6;
//     int edgesSize = (sizeof(arr) / sizeof(arr[0]));

//     int** edges = (int**)malloc(sizeof(int*) * edgesSize);
//     for (int i = 0; i < edgesSize; i++) {
//         *(edges + i) = &arr[i][0];
//     }

//     int* edgesColSize = (int*)malloc(sizeof(int));
//     int* returnSize = (int*)malloc(sizeof(int));

//     int* ret = (int*)malloc(sizeof(int));
//     ret = sumOfDistancesInTree(N, edges, edgesSize, edgesColSize, returnSize);

//     for (int i = 0; i < *returnSize; i++) {
//         printf("%d ", ret[i]);
//     }

//     return 0;
// }
