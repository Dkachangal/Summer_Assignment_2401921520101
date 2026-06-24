#include <iostream>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// --- Your Exact LeetCode Class ---
class Solution {
public:
    TreeNode* ansistor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL) return NULL;
        if (root == p || root == q) return root; 

        TreeNode* L = lowestCommonAncestor(root->left, p, q);
        TreeNode* R = lowestCommonAncestor(root->right, p, q);
        

        if (L && R) return root;
        if (L && !R) return L;
        if (R && !L) return R;
        if (!R && !L) return NULL;

        return root;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
       
        TreeNode* ansis = ansistor(root, p, q);
        return ansis;
    }
};

// --- Helper function to run the solution locally ---
int main() {
    Solution solver;

    // Creating a sample binary tree:
    //       3
    //      / \
    //     5   1
    //    / \
    //   6   2
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);

    // Target nodes to find the LCA for (Nodes 5 and 1)
    TreeNode* p = root->left;        // Node 5
    TreeNode* q = root->right;       // Node 1

    // Call your function
    TreeNode* lca = solver.lowestCommonAncestor(root, p, q);

    // Print output
    if (lca != NULL) {
        std::cout << "Lowest Common Ancestor of " << p->val << " and " << q->val << " is: " << lca->val << std::endl;
    } else {
        std::cout << "LCA not found." << std::endl;
    }

    // Clean up memory
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}