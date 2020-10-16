#include <malloc.h>
#include <stdio.h>

struct Node {
    int          val;
    struct Node* left;
    struct Node* right;
};

// 创建二叉树
void createTree(struct Node** node, char* str, int* n) {
    if (str[*n] != '\0') {    // 如果不等于结束符就继续创建，否则就结束
        if (str[*n] == '#') { // 以 # 号代表 NULL
            *node = NULL;
        } else {
            *node        = (struct Node*)malloc(sizeof(struct Node)); // 新建一个二叉链
            (*node)->val = str[*n] - '0';                             // 把字符存入二叉链
            (*n)++;                                                   // 指针里的数值 +1
            createTree(&((*node)->left), str, n);                     // 左递归创建
            (*n)++;                                                   // 指针里的数值 +1
            createTree(&((*node)->right), str, n);                    // 右递归创建
        }
    }
}

// 先序遍历
void preOrder(struct Node* node) {
    if (node != NULL) {           //判断不为空
        printf("%d ", node->val); //访问根节点
        preOrder(node->left);     //递归，遍历左子树
        preOrder(node->right);    //递归，遍历右子树
    }
}
// 中序遍历
void inOrder(struct Node* node) {
    if (node != NULL) {
        inOrder(node->left);
        printf("%d ", node->val);
        inOrder(node->right);
    }
}

int main() {
    /**
     * 请输入字符串（先序遍历创建）
     * 例如: 1#32###
     * 中序遍历: 123
     */
    struct Node** root = (struct Node**)malloc(sizeof(struct Node*));
    char*         str  = (char*)"1#32###";
    int           n    = 0;
    createTree(root, str, &n);
    printf("先序遍历结果: ");
    preOrder(*root);
    printf("\n中序遍历结果: ");
    inOrder(*root);

    return 0;
}