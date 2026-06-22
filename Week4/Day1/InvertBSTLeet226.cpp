#include <iostream>
#include <algorithm>

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
    TreeNode* inverter(TreeNode* root) {
        if (root == NULL) return NULL;
        TreeNode* L = root -> left;
        TreeNode* R = root -> right;
        swap(root -> left, root -> right);
        inverter(root -> left);
        inverter(root -> right);

        return root;
    }
    TreeNode* invertTree(TreeNode* root) {
        inverter(root);
        return root;


    }
};

void printTreeInOrder(TreeNode* root) {
    if (root == NULL) return;
    printTreeInOrder(root->left);
    cout << root->val << " ";
    printTreeInOrder(root->right);
}

int main() {
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(9);

    cout << "Original tree (In-order): ";
    printTreeInOrder(root);
    cout << endl;

    Solution solution;
    solution.invertTree(root);

    cout << "Inverted tree (In-order): ";
    printTreeInOrder(root);
    cout << endl;

    delete root->right->right;
    delete root->right->left;
    delete root->left->right;
    delete root->left->left;
    delete root->right;
    delete root->left;
    delete root;

    return 0;
}