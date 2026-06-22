#include <iostream>

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

    bool isIdentical(TreeNode *r1, TreeNode* r2) {
        if (r1 == NULL || r2 == NULL) {
            return r1 == r2;
        }

        bool isLeftIdentical = isIdentical(r1 -> left, r2 -> left);
        bool isRightIdentical = isIdentical(r1 -> right, r2 -> right);

        if (r1 -> val == r2 -> val && isLeftIdentical && isRightIdentical) return true;
        return false;
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        bool isSame = isIdentical(p, q);
        return isSame;
        
    }
};

int main() {
    TreeNode* p = new TreeNode(1);
    p->left = new TreeNode(2);
    p->right = new TreeNode(3);

    TreeNode* q = new TreeNode(1);
    q->left = new TreeNode(2);
    q->right = new TreeNode(3);

    Solution solution;
    bool result = solution.isSameTree(p, q);

    cout << boolalpha << "Are trees the same? " << result << endl;

    delete p->left;
    delete p->right;
    delete p;

    delete q->left;
    delete q->right;
    delete q;

    return 0;
}