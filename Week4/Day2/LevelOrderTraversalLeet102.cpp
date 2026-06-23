#include <iostream>
#include <vector>
#include <queue>

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
    void trav(TreeNode* root, vector<vector<int>> &ans) {
        queue<TreeNode*> q;

        if (root != NULL) {
            q.push(root);
            q.push(NULL);
        }
        vector<int> temp;

        while(!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();

            if (curr == NULL) {
                ans.push_back(temp);
                temp.clear();
                if (!q.empty()) {
                    q.push(NULL);
                    continue;
                } else break;
            } else {
                temp.push_back(curr -> val);
                if (curr -> left != NULL) q.push(curr -> left);
                if (curr -> right != NULL) q.push(curr -> right);
            }
        }
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == NULL) return {};
        vector<vector<int>> ans;
        trav(root, ans);
        return ans;
    }
};

int main() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution solution;
    vector<vector<int>> result = solution.levelOrder(root);

    for (const auto& level : result) {
        for (int val : level) {
            cout << val << " ";
        }
        cout << endl;
    }

    delete root->right->right;
    delete root->right->left;
    delete root->right;
    delete root->left;
    delete root;

    return 0;
}