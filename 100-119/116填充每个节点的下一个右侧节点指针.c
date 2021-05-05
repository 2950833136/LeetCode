#include <malloc.h>
#include <stdio.h>

struct Node {
    int          val;
    struct Node* left;
    struct Node* right;
    struct Node* next;
};

// 创建二叉树
void createTree(struct Node** node, char* str, int* n) {
    if (str[*n] != '\0') {    // 如果不等于结束符就继续创建，否则就结束
        if (str[*n] == '#') { // 以 # 号代表 NULL
            *node = NULL;
        } else {
            *node         = (struct Node*)malloc(sizeof(struct Node)); // 新建一个二叉链
            (*node)->val  = str[*n] - '0';                             // 把字符存入二叉链
            (*node)->next = NULL;                                      // 置空
            (*n)++;                                                    // 指针里的数值 +1
            createTree(&((*node)->left), str, n);                      // 左递归创建
            (*n)++;                                                    // 指针里的数值 +1
            createTree(&((*node)->right), str, n);                     // 右递归创建
        }
    }
}
// 先序遍历
void preOrder(struct Node* node) {
    if (node != NULL) {
        printf("%d", node->val);
        preOrder(node->left);
        preOrder(node->right);
    }
}
// 遍历
void levelOrder(struct Node* node) {
    struct Node* temp = node;
    if (temp != NULL) {
        while (temp != NULL) {
            printf("%d", temp->val);
            temp = temp->next;
        }
        levelOrder(node->left);
    }
}

/**
 * 方法一：层次遍历
 * 利用队列，存储每一层的节点，在进行连接
 */
// struct Node* connect(struct Node* root) {
//     if (root == NULL) {
//         return root;
//     }

//     struct Node* queue[5000];
//     int          low   = 0;
//     int          hight = 0;

//     // 放入头结点，并 hight+1
//     queue[hight++] = root;
//     while (low < hight) {
//         // 计算一层的队列大小
//         int size = hight - low;
//         // 遍历这一层节点
//         for (int i = 0; i < size; i++) {
//             // 取出节点，并 low+1
//             struct Node* temp = queue[low++];
//             // 连接后面节点
//             if (i < size - 1) {
//                 temp->next = queue[low];
//             }
//             // 存入下一层节点
//             if (temp->left != NULL) {
//                 queue[hight++] = temp->left;
//             }
//             if (temp->right != NULL) {
//                 queue[hight++] = temp->right;
//             }
//         }
//     }
//     return root;
// }

/**
 * 方法二：利用 next 判定节点信息
 * 利用父节点
 *      - 父节点的两个儿子节点相连
 *      - 父节点的左儿子节点与兄弟节点右儿子节点相连
 */
// struct Node* connect(struct Node* root) {
//     if (root == NULL) {
//         return root;
//     }

//     // 得到根节点，用来遍历左边的头结点
//     struct Node* leftHead = root;
//     while (leftHead->left != NULL) {
//         // 遍历这一层节点组织成的链表，为下一层的节点更新 next 指针
//         struct Node* node = leftHead;
//         while (node != NULL) {
//             // CONNECTION 1: 节点两个儿子节点相连
//             node->left->next = node->right;
//             // CONNECTION 2: 兄弟节点左儿子与右儿子相连
//             if (node->next != NULL) {
//                 node->right->next = node->next->left;
//             }
//             // 这一层下一个节点
//             node = node->next;
//         }
//         // 下一层头结点
//         leftHead = leftHead->left;
//     }
//     return root;
// }

/**
 * 方法三：递归遍历
 * 原理同 2 一样
 */
struct Node* connect(struct Node* root) {
    if (root == NULL) {
        return root;
    }
    if (root->left) {
        root->left->next = root->right;
        if (root->next) {
            root->right->next = root->next->left;
        }
        connect(root->left);
        connect(root->right);
    }
    return root;
}

int main() {
    /**
     * 请输入字符串（先序遍历创建）
     * 例如: 124##5##36##7##
     */
    struct Node** root = (struct Node**)malloc(sizeof(struct Node*));
    char*         str  = (char*)"124##5##36##7##";
    int           n    = 0;
    createTree(root, str, &n);
    printf("先序遍历结果: ");
    preOrder(*root);

    connect(*root);
    printf("\n层次遍历结果: ");
    levelOrder(*root);

    return 0;
}