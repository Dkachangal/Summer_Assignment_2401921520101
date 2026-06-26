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
    int search(vector<int> &in, int rootVal) {
        for (int i=0; i<in.size(); i++) {
            if (in[i] == rootVal) return i;
        }
        return -1;
    }
    TreeNode* build(vector<int> pre, vector<int> in, int *preIdx, int left, int right) {
        if (*preIdx>= pre.size() || left > right) return NULL;

        TreeNode* root = new TreeNode(pre[*preIdx]);
        (*preIdx)++;


        int inordIdx = search(in, root->val);

        root -> left = build(pre, in, preIdx, left,inordIdx-1);
        root -> right = build(pre, in, preIdx, inordIdx+1, right);

        return root;    
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        TreeNode* root = new TreeNode();
        int preIdx = 0;
        
        root = build(preorder, inorder, &preIdx, 0, inorder.size()-1);
        return root;
    }
};

void printInorder(TreeNode* node) {
    if (node == nullptr) return;
    printInorder(node->left);
    cout << node->val << " ";
    printInorder(node->right);
}

void freeTree(TreeNode* node) {
    if (node == nullptr) return;
    freeTree(node->left);
    freeTree(node->right);
    delete node;
}

int main() {
    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};

    Solution solution;
    TreeNode* root = solution.buildTree(preorder, inorder);

    cout << "Inorder traversal of built tree: ";
    printInorder(root);
    cout << endl;

    freeTree(root);

    return 0;
}