#include <algorithm>
#include <iostream>
#include <queue>
#include <sstream>
using namespace std;

struct TreeNode {
    int       val;
    TreeNode *left;
    TreeNode *right;
    TreeNode()
        : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x)
        : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) { return !isspace(ch); }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) { return !isspace(ch); }).base(), input.end());
}

TreeNode *stringToTreeNode(string input) {
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    if (!input.size()) {
        return nullptr;
    }

    string       item;
    stringstream ss;
    ss.str(input);

    getline(ss, item, ',');
    TreeNode *        root = new TreeNode(stoi(item));
    queue<TreeNode *> nodeQueue;
    nodeQueue.push(root);

    while (true) {
        TreeNode *node = nodeQueue.front();
        nodeQueue.pop();

        if (!getline(ss, item, ',')) {
            break;
        }

        trimLeftTrailingSpaces(item);
        if (item != "null") {
            int leftNumber = stoi(item);
            node->left     = new TreeNode(leftNumber);
            nodeQueue.push(node->left);
        }

        if (!getline(ss, item, ',')) {
            break;
        }

        trimLeftTrailingSpaces(item);
        if (item != "null") {
            int rightNumber = stoi(item);
            node->right     = new TreeNode(rightNumber);
            nodeQueue.push(node->right);
        }
    }
    return root;
}

string boolToString(bool input) {
    return input ? "True" : "False";
}

/**
 * 深度优先遍历
 */
class Solution {
public:
    vector<int> DFS(TreeNode *root, int target, TreeNode *parent, int depth) {
        if (root == nullptr) {
            return vector<int>{-1, -1};
        }
        if (root->val == target) {
            return vector<int>{parent != nullptr ? parent->val : -1, depth};
        }
        vector<int> left = DFS(root->left, target, root, depth + 1);
        if (left[0] != -1) {
            return left;
        }
        return DFS(root->right, target, root, depth + 1);
    }
    bool isCousins(TreeNode *root, int x, int y) {
        vector<int> vx = DFS(root, x, nullptr, 0);
        vector<int> vy = DFS(root, y, nullptr, 0);
        return (vx[1] == vy[1]) && (vx[0] != vy[0]);
    }
};

int main() {
    string    line = "[1,2,3,null,4,null,5]";
    TreeNode *root = stringToTreeNode(line);

    Solution s;
    int      x = 5;
    int      y = 4;
    cout << boolToString(s.isCousins(root, x, y)) << endl;

    return 0;
}
