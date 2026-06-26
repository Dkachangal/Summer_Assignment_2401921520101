#include <iostream>
#include <algorithm>
#include <climits>

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
    int ans = INT_MIN;
    int currVal = 0;
    int maxSum (TreeNode* root) {

        if (root == NULL) return 0;

        int leftSum = std::max(0, maxSum(root -> left));
        int rightSum = std::max(0, maxSum(root -> right));
        ans = std::max(ans, root -> val + leftSum + rightSum);

        return root -> val + (std::max(leftSum, rightSum));
    }
    int maxPathSum(TreeNode* root) {
        maxSum(root);
        return ans;
    }
};

int main() {
    TreeNode* root = new TreeNode(-10);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution solution;
    int result = solution.maxPathSum(root);

    std::cout << "Max Path Sum: " << result << std::endl;

    delete root->right->left;
    delete root->right->right;
    delete root->right;
    delete root->left;
    delete root;

    return 0;
}