/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
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