#include <iostream>
#include <vector>
#include <queue>
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
    void levelOrderRev(TreeNode* root, vector<vector<int>> &ans) {
        queue<TreeNode*> q;
        bool isRtoL = false;

        if (root != NULL) {
            q.push(root);
            q.push(NULL);
        }
        vector<int> temp;

        while (!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();

            if (curr == NULL) {
                if (isRtoL) {
                    reverse(temp.begin(), temp.end());
                }
                ans.push_back(temp);
                temp.clear();
                isRtoL = !isRtoL;
                
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
    
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        levelOrderRev(root, ans);
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
    vector<vector<int>> result = solution.zigzagLevelOrder(root);

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