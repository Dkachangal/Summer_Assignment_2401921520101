#include <iostream>
#include <algorithm>

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
    int ans = 0;
    int calcDia(TreeNode* root) {
        if (root == nullptr) return 0;
        int lh = calcDia(root->left);
        int rh = calcDia(root->right);

        ans = std::max(ans, lh + rh);
        return std::max(lh, rh) + 1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        calcDia(root);
        return ans;
    }
};

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    Solution solution;
    int result = solution.diameterOfBinaryTree(root);

    std::cout << "Diameter: " << result << std::endl;

    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}