#include <algorithm>
#include <iostream>
#include <queue>
#include <sstream>
#include <vector>
using namespace std;

struct TreeNode {
    int       val;
    TreeNode* left;
    TreeNode* right;
    TreeNode()
        : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x)
        : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right)
        : val(x), left(left), right(right) {}
};

void trimLeftTrailingSpaces(string& input) {
    input.erase(input.begin(),
                find_if(input.begin(), input.end(), [](int ch) {
                    return !isspace(ch);
                }));
}

void trimRightTrailingSpaces(string& input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
                    return !isspace(ch);
                }).base(),
                input.end());
}

TreeNode* stringToTreeNode(string input) {
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
    TreeNode*        root = new TreeNode(stoi(item));
    queue<TreeNode*> nodeQueue;
    nodeQueue.push(root);

    while (true) {
        TreeNode* node = nodeQueue.front();
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
 * 我们可以使用深度优先搜索的方法得到一棵树的「叶值序列」。
 * 具体地，在深度优先搜索的过程中，我们总是先搜索当前节点的左子节点，再搜索当前节点的右子节点。如果我们搜索到一个叶节点，就将它的值放入序列中。
 * 在得到了两棵树分别的「叶值序列」后，我们比较它们是否相等即可。
 */
class Solution {
public:
    void dfs(TreeNode* node, vector<int>& seq) {
        if (node->left == nullptr && node->right == nullptr) {
            seq.push_back(node->val);
        } else {
            if (node->left != nullptr) {
                dfs(node->left, seq);
            }
            if (node->right != nullptr) {
                dfs(node->right, seq);
            }
        }
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> seq1;
        if (root1 != nullptr) {
            dfs(root1, seq1);
        }
        vector<int> seq2;
        if (root2 != nullptr) {
            dfs(root2, seq2);
        }
        return seq1 == seq2;
    }
};

int main() {
    string    line1 = "[1]";
    string    line2 = "[2]";
    TreeNode* root1 = stringToTreeNode(line1);
    TreeNode* root2 = stringToTreeNode(line2);

    bool   ret = Solution().leafSimilar(root1, root2);
    string out = boolToString(ret);
    cout << out << endl;

    return 0;
}