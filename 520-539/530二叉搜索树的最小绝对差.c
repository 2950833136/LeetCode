#include <limits.h>
#include <malloc.h>
#include <stdio.h>
#include <math.h>

struct TreeNode {
    int              val;
    struct TreeNode* left;
    struct TreeNode* right;
};

// 创建二叉树
void createTree(struct TreeNode** TN) {
    char ch;
    ch = getchar();
    if (ch == '#') {
        *TN = NULL;
    } else {
        if (!(*TN = (struct TreeNode*)malloc(sizeof(struct TreeNode)))) {
            printf("内存分配失败！");
            return;
        } else {
            (*TN)->val = ch - '0';
            createTree(&((*TN)->left)); //分配成功则接着建立左子树和右子树
            createTree(&((*TN)->right));
        }
    }
}
// 先序遍历
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
     * 例如：1#32###
     * 中序遍历：123
     */
    printf("请输入字符串: ");
    createTree(TN);
    printf("先序遍历结果: ");
    inOrder(*TN);

    int ret = getMinimumDifference(*TN);
    printf("\n最小绝对差值: %d", ret);

    return 0;
}