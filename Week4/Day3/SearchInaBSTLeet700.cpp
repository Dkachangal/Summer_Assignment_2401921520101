#include <iostream>
#include <queue>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// --- Your Exact LeetCode Class ---
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        while (root != NULL) {
            if (root -> val == val) return root;

            if (val < root -> val) {
                // go left
                root = root -> left;

            } else {
                // go right
                root = root -> right;
            }
        }
        if (root) if (root ->val == val) return root;
        return NULL;
    }
};

// --- Helper Functions to Run and Test ---

// Helper function to insert nodes into a BST
TreeNode* insert(TreeNode* root, int val) {
    if (!root) return new TreeNode(val);
    if (val < root->val) {
        root->left = insert(root->left, val);
    } else {
        root->right = insert(root->right, val);
    }
    return root;
}

// Helper function to print the tree in-order (for verification)
void printInOrder(TreeNode* root) {
    if (!root) return;
    printInOrder(root->left);
    std::cout << root->val << " ";
    printInOrder(root->right);
}

int main() {
    Solution solver;
    
    // 1. Construct a sample BST: [4, 2, 7, 1, 3]
    TreeNode* root = nullptr;
    root = insert(root, 4);
    root = insert(root, 2);
    root = insert(root, 7);
    root = insert(root, 1);
    root = insert(root, 3);

    std::cout << "Created BST (In-order traversal): ";
    printInOrder(root);
    std::cout << "\n\n";

    // 2. Define the target value to search for
    int target = 2;
    std::cout << "Searching for value: " << target << "\n";

    // 3. Call your exact function
    TreeNode* result = solver.searchBST(root, target);

    // 4. Output the result
    if (result != nullptr) {
        std::cout << "Node found! Subtree rooted at target: ";
        printInOrder(result);
        std::cout << "\n";
    } else {
        std::cout << "Value not found in the BST.\n";
    }

    return 0;
}