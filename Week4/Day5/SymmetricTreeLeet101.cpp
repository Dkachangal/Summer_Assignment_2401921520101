#include <iostream>

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
    bool isSame = true;
    void search(TreeNode* r, TreeNode* l) {
        if (r == NULL && l != NULL || r != NULL && l == NULL) {
            isSame = false;
            return;
        }
        if (r == NULL && l == NULL) return;
        if (r -> val != l -> val) {
            isSame = false;
            return;
        }
        search(r-> left, l-> right);
        search(r -> right, l -> left);

    }
    bool isSymmetric(TreeNode* root) {
        search(root -> left, root ->right);
        if(isSame) return true;
        return false;
    }
};

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(3);

    Solution solution;
    bool result = solution.isSymmetric(root);

    std::cout << std::boolalpha << "Is Symmetric: " << result << std::endl;

    delete root->left->left;
    delete root->left->right;
    delete root->right->left;
    delete root->right->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}