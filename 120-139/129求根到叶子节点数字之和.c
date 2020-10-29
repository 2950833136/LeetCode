#include <malloc.h>
#include <stdio.h>
#include <string.h>

typedef enum {
    false = 0,
    true  = 1
} bool;

struct TreeNode {
    int              val;
    struct TreeNode* left;
    struct TreeNode* right;
};

// 创建二叉树
void createTree(struct TreeNode** node, char* str, int* n) {
    if (str[*n] != '\0') {    // 如果不等于结束符就继续创建，否则就结束
        if (str[*n] == '#') { // 以 # 号代表 NULL
            *node = NULL;
        } else {
            *node        = (struct TreeNode*)malloc(sizeof(struct TreeNode)); // 新建一个二叉链
            (*node)->val = str[*n] - '0';                                     // 把字符存入二叉链
            (*n)++;                                                           // 指针里的数值 +1
            createTree(&((*node)->left), str, n);                             // 左递归创建
            (*n)++;                                                           // 指针里的数值 +1
            createTree(&((*node)->right), str, n);                            // 右递归创建
        }
    }
}

// 画树
void draw_level(struct TreeNode* root, bool left, char* str) {
    if (root->right) {
        draw_level(root->right, false, strcat(str, (left ? "|     " : "      ")));
    }
    printf("%s", str);
    printf("%c", (left ? '\\' : '/'));
    printf("-----");
    printf("%d\n", root->val);
    if (root->left) {
        draw_level(root->left, true, strcat(str, (left ? "      " : "|     ")));
    }
    // "      " 和 "|     " 字符长度为 6
    str[strlen(str) - 6] = '\0';
}
void draw(struct TreeNode* root) {
    char str[1024];
    memset(str, '\0', sizeof(str));
    if (root->right) {
        draw_level(root->right, false, str);
    }
    printf("%d\n", root->val);
    if (root->left) {
        draw_level(root->left, true, str);
    }
}

/**
 * 方法一：深度优先搜索
 *  - 递归得到每个叶子结点的数值，相加可得
 *  + 从根节点开始，遍历每个节点
 *      - 如果遇到叶子节点，则将叶子节点对应的数字加到数字之和。
 *      - 如果当前节点不是叶子节点，则计算其子节点对应的数字，然后对子节点递归遍历。
 */
int dfs(struct TreeNode* root, int prevSum) {
    if (root == NULL) {
        return 0;
    }
    int sum = prevSum * 10 + root->val;
    if (root->left == NULL && root->right == NULL) {
        return sum;
    } else {
        return dfs(root->left, sum) + dfs(root->right, sum);
    }
}
int sumNumbers(struct TreeNode* root) {
    return dfs(root, 0);
}

/**
 * 方法二：广度优先搜索
 * 使用广度优先搜索，需要维护两个队列，分别存储节点和节点对应的数字。
 *  + 初始时，将根节点和根节点的值分别加入两个队列。每次从两个队列分别取出一个节点和一个数字，进行如下操作：
 *      - 如果当前节点是叶子节点，则将该节点对应的数字加到数字之和；
 *      - 如果当前节点不是叶子节点，则获得当前节点的非空子节点，并根据当前节点对应的数字和子节点的值计算子节点对应的数字，然后将子节点和子节点对应的数字分别加入两个队列。
 */
int sumNumbers2(struct TreeNode* root) {
    if (root == NULL) {
        return 0;
    }
    struct TreeNode* nodeQueue[2000]; // 存储节点
    int              numQueue[2000];  // 节点对应的数字
    int              leftQueue  = 0;  // 队列头部
    int              rightQueue = 0;  // 队列尾部
    int              sum        = 0;  // 和

    nodeQueue[rightQueue]  = root;
    numQueue[rightQueue++] = root->val;
    while (leftQueue < rightQueue) {
        struct TreeNode* node  = nodeQueue[leftQueue];
        int              num   = numQueue[leftQueue++];
        struct TreeNode* left  = node->left;
        struct TreeNode* right = node->right;
        if (left == NULL && right == NULL) {
            sum += num;
        } else {
            if (left != NULL) {
                nodeQueue[rightQueue]  = left;
                numQueue[rightQueue++] = num * 10 + left->val;
            }
            if (right != NULL) {
                nodeQueue[rightQueue]  = right;
                numQueue[rightQueue++] = num * 10 + right->val;
            }
        }
    }
    return sum;
}

int main() {
    /**
     * 请输入字符串（先序遍历创建）
     * 例如: 495##1##0##
     */
    struct TreeNode** root       = (struct TreeNode**)malloc(sizeof(struct TreeNode*));
    int*              returnSize = (int*)malloc(sizeof(int));
    char*             str        = (char*)"495##1##0##";

    *returnSize = 0;
    createTree(root, str, returnSize);
    draw(*root);

    int ret = sumNumbers(*root);
    printf("%d\n", ret);
    int ret2 = sumNumbers2(*root);
    printf("%d\n", ret2);

    return 0;
}