#include <iostream>
#include <vector>

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
    void traveres(TreeNode* root, vector<int> &trav) {
        if (root == NULL) return;
        
        traveres(root -> left, trav);
        trav.push_back(root -> val);
        traveres(root -> right, trav);
        
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> trav; 

        if (root == NULL) return {};
        traveres(root, trav);
        return trav; 
    }
};

int main() {
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    Solution solution;
    vector<int> result = solution.inorderTraversal(root);

    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    delete root->right->left;
    delete root->right;
    delete root;

    return 0;
}