#include <limits.h>
#include <malloc.h>
#include <math.h>
#include <stdio.h>

struct TreeNode {
    int              val;
    struct TreeNode* left;
    struct TreeNode* right;
};

// 创建二叉树
void createTree(struct TreeNode** TN, char* str, int* n) {
    if (str[*n] != '\0') {    // 如果不等于结束符就继续创建，否则就结束
        if (str[*n] == '#') { // 以 # 号代表 NULL
            *TN = NULL;
        } else {
            *TN        = (struct TreeNode*)malloc(sizeof(struct TreeNode)); // 新建一个二叉链
            (*TN)->val = str[*n] - '0';                                     // 把字符存入二叉链
            (*n)++;                                                         // 指针里的数值 +1
            createTree(&((*TN)->left), str, n);                             // 左递归创建
            (*n)++;                                                         // 指针里的数值 +1
            createTree(&((*TN)->right), str, n);                            // 右递归创建
        }
    }
}
// 中序遍历
void inOrder(struct TreeNode* TN) {
    if (TN != NULL) {          //判断不为空
        inOrder(TN->left);     //递归，遍历左子树
        printf("%d", TN->val); //访问根节点
        inOrder(TN->right);
    }
}

/**
 * 提交题解
 * 原理：二叉搜索树中序遍历得到的值序列是递增有序的
 *      - 利用中序遍历得到有序增长数之间的差值
 *      - 判断最小值即可
 */
void dfs(struct TreeNode* root, int* pre, int* ans) {
    if (root == NULL) {
        return;
    }
    dfs(root->left, pre, ans);
    if (*pre == -1) {
        *pre = root->val;
    } else {
        *ans = fmin(*ans, root->val - (*pre));
        *pre = root->val;
    }
    dfs(root->right, pre, ans);
}

int getMinimumDifference(struct TreeNode* root) {
    int pre = -1, ans = INT_MAX;
    dfs(root, &pre, &ans);
    return ans;
}

int main() {
    struct TreeNode** TN = (struct TreeNode**)malloc(sizeof(struct TreeNode*));
    /**
     * 请输入字符串
     * 例如: 1#32###
     * 中序遍历: 123
     */
    char* str = (char*)"1#32###";
    int   n   = 0;
    createTree(TN, str, &n);
    printf("中序遍历结果: ");
    inOrder(*TN);

    int ret = getMinimumDifference(*TN);
    printf("\n最小绝对差值: %d", ret);

    return 0;
}