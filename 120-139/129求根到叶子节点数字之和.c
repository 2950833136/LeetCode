#include <malloc.h>
#include <stdio.h>
#include <string.h>

typedef enum {
    false = 0,
    true  = 1
} bool;

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

// 画树
void draw_level(struct Node* root, bool left, char* str) {
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
void draw(struct Node* root) {
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
 * 
 * 
 */
int sumNumbers(struct TreeNode* root) {
}

int main() {
    /**
     * 请输入字符串（先序遍历创建）
     * 例如: 495##1##0##
     */
    struct Node** root       = (struct Node**)malloc(sizeof(struct Node*));
    int*          returnSize = (int*)malloc(sizeof(int));
    char*         str        = (char*)"495##1##0##";

    *returnSize = 0;
    createTree(root, str, returnSize);
    draw(*root);

    return 0;
}