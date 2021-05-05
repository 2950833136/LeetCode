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

/**
 * 前序遍历：迭代
 */
int* preorderTraversal2(struct TreeNode* root, int* returnSize) {
    int* ret    = (int*)malloc(sizeof(int) * 2000);
    *returnSize = 0;
    if (root == NULL) {
        return ret;
    }

    struct TreeNode* node = root;
    struct TreeNode* stack[2000];
    int              stack_top = 0;

    while (stack_top > 0 || node != NULL) {
        while (node != NULL) {
            // 先压入，再 stack_top++
            ret[(*returnSize)++] = node->val;
            stack[stack_top++]   = node;
            node                 = node->left;
        }
        // 先 --stack_top，再取出
        node = stack[--stack_top];
        node = node->right;
    }
    return ret;
}

/**
 * 前序遍历：Morris 遍历
 * Morris 遍历的核心思想是利用树的大量空闲指针，实现空间开销的极限缩减。其前序遍历规则总结如下：
    1、新建临时节点，令该节点为 root；
    2、如果当前节点的左子节点为空，将当前节点加入答案，并遍历当前节点的右子节点；
    3、如果当前节点的左子节点不为空，在当前节点的左子树中找到当前节点在中序遍历下的前驱节点：
       + 如果前驱节点的右子节点为空，将前驱节点的右子节点设置为当前节点。然后将当前节点加入答案，并将前驱节点的右子节点更新为当前节点。
       + 如果前驱节点的右子节点为当前节点，将它的右子节点重新设为空。当前节点更新为当前节点的右子节点。
    4、重复步骤 2 和步骤 3，直到遍历结束。
    总结：以某个根结点开始，找到它左子树的最右侧节点之后与这个根结点进行连接
 */
int* preorderTraversal3(struct TreeNode* root, int* returnSize) {
    int* ret    = (int*)malloc(sizeof(int) * 2000);
    *returnSize = 0;
    if (root == NULL) {
        return ret;
    }

    struct TreeNode* p1 = root; // 当前开始遍历的节点
    struct TreeNode* p2 = NULL; // 记录当前结点的左子树
    while (p1 != NULL) {
        p2 = p1->left;
        // 如果当前节点的左子节点为空，将当前节点加入答案，并遍历当前节点的右子节点
        if (p2 != NULL) {
            // 找到当前左子树的最右侧节点，且这个节点应该在指向根结点之前，否则整个节点又回到了根结点
            while (p2->right != NULL && p2->right != p1) {
                p2 = p2->right;
            }
            // 这个时候如果最右侧这个节点的右指针没有指向根结点，创建连接，然后往下一个左子树的根结点进行连接操作
            if (p2->right == NULL) {
                ret[(*returnSize)++] = p1->val;
                p2->right            = p1;
                p1                   = p1->left;
                continue;
            } else {
                p2->right = NULL;
            }
        } else {
            ret[(*returnSize)++] = p1->val;
        }
        p1 = p1->right;
    }
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

    printf("迭代--前序遍历结果: ");
    int* ret2 = preorderTraversal2(*root, returnSize);
    display(ret2, *returnSize);

    printf("Morris--前序遍历结果: ");
    int* ret3 = preorderTraversal3(*root, returnSize);
    display(ret3, *returnSize);

    return 0;
}