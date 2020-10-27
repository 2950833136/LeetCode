#include <malloc.h>
#include <stdio.h>

struct TreeNode {
    int              val;
    struct TreeNode* left;
    struct TreeNode* right;
};

// 遍历一维指针
void display(int* nums, int numsSize) {
    for (int i = 0; i < numsSize; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");
}
// 创建二叉树
void createTree(struct TreeNode** TreeNode, char* str, int* n) {
    if (str[*n] != '\0') {    // 如果不等于结束符就继续创建，否则就结束
        if (str[*n] == '#') { // 以 # 号代表 NULL
            *TreeNode = NULL;
        } else {
            *TreeNode        = (struct TreeNode*)malloc(sizeof(struct TreeNode)); // 新建一个二叉链
            (*TreeNode)->val = str[*n] - '0';                                     // 把字符存入二叉链
            (*n)++;                                                               // 指针里的数值 +1
            createTree(&((*TreeNode)->left), str, n);                             // 左递归创建
            (*n)++;                                                               // 指针里的数值 +1
            createTree(&((*TreeNode)->right), str, n);                            // 右递归创建
        }
    }
}

/**
 * 前序遍历：递归
 */
void preOrder(struct TreeNode* node, int* ret, int* returnSize) {
    if (node == NULL) {
        return;
    }
    ret[(*returnSize)++] = node->val;
    preOrder(node->left, ret, returnSize);
    preOrder(node->right, ret, returnSize);
}

int* preorderTraversal(struct TreeNode* root, int* returnSize) {
    int* ret    = (int*)malloc(sizeof(int) * 2000);
    *returnSize = 0;
    preOrder(root, ret, returnSize);
    return ret;
}

int main() {
    /**
     * 请输入字符串（先序遍历创建）
     * 例如: 1#23###
     */
    struct TreeNode** root       = (struct TreeNode**)malloc(sizeof(struct TreeNode*));
    int*              returnSize = (int*)malloc(sizeof(int));
    char*             str        = (char*)"1#23###";

    *returnSize = 0;
    createTree(root, str, returnSize);
    printf("递归--前序遍历结果: ");
    int* ret = preorderTraversal(*root, returnSize);
    display(ret, *returnSize);

    return 0;
}