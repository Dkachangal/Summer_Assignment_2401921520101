#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool travDFS(TreeNode* root, int target) {
        if (root == nullptr) return false;
        target -= root->val;
        if (target == 0 && (root->left == nullptr && root->right == nullptr)) {
            return true;
        }

        bool left = travDFS(root->left, target);
        bool right = travDFS(root->right, target);

        return left || right;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        bool ans = travDFS(root, targetSum);
        return ans;
    }
};

int main() {
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(11);
    root->left->left->left = new TreeNode(7);
    root->left->left->right = new TreeNode(2);

    Solution solution;
    bool result = solution.hasPathSum(root, 22);

    std::cout << std::boolalpha << "Result: " << result << std::endl;

    delete root->left->left->left;
    delete root->left->left->right;
    delete root->left->left;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}