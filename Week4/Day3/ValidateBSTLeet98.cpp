#include <iostream>
#include <vector>

using namespace std;

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
    bool noExtraSpace(TreeNode* root, TreeNode* min, TreeNode* max) {
        if (root == NULL) return true;

        if (min != NULL && root -> val <= min -> val) return false;
        if (max != NULL && root -> val >= max -> val) return false;

        return noExtraSpace(root -> left, min, root) && noExtraSpace(root -> right, root, max); 
    }
    void inorderArray(TreeNode* root, vector<int> &ans) {
        // left root right
        if (root == NULL) return;
        inorderArray(root -> left, ans);
        ans.push_back(root -> val);
        inorderArray(root -> right, ans);
    }
    bool isValidBST(TreeNode* root) {
        // if inorder is sorted array, then 
        // it is a vlaid BST else not
        // inorder root -> left, root, root -> right
        // vector<int> ans;
        // inorderArray(root, ans);
        // if (ans.size() == 1) return true;
        // for (int i=0; i<=ans.size()-2; i++) {
           
        //     if (ans[i] >= ans[i+1]) {
        //         return false;
        //     }
        // } 
        // TreeNode* min = 
        bool ans = noExtraSpace(root, NULL, NULL);
        return ans;
        // return true;
    }
};

// --- Helper function to run the solution locally ---
int main() {
    Solution solver;

    // Constructing a valid BST manually for testing:
    //      5
    //     / \
    //    1   7
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(1);
    root->right = new TreeNode(7);

    // Call your function
    bool result = solver.isValidBST(root);

    // Print output
    cout << boolalpha; // Prints true/false instead of 1/0
    cout << "Is the tree a valid BST? " << result << endl;

    // Clean up memory
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}