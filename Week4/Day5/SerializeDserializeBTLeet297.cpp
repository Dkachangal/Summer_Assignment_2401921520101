#include <iostream>
#include <string>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:

    void trav(TreeNode* root, string &str) {
        if (root == NULL) {
            str += "N|";
            return;
        }
        string value = to_string(root -> val);
        str += value;
        str += "|";

        trav(root -> left, str);
        trav(root -> right, str);
    }
    string serialize(TreeNode* root) {
        string str = "|";
        trav(root, str);
        return str;
    }

    TreeNode* makeTree(string data, int &idx) {

        if (idx >= data.length()) {
            return NULL;
        }
        if (data[idx] == '|') idx++;
        if (idx >= data.length()) {
            return NULL;
        }
        if (data[idx] == 'N') {
            idx+=2;
            return NULL;
        }

        string str = "";
        while (idx < data.length() && data[idx] != '|') {
            str += data[idx];
            idx++;
        }

        int value = stoi(str);
        TreeNode* root = new TreeNode(value);
        root -> left = makeTree(data, idx);
        root -> right = makeTree(data, idx);
        
        return root;
    }
    TreeNode* deserialize(string data) {
        int idx = 0;
        TreeNode* root = makeTree(data, idx);
        return root;
    }
};

void printPreorder(TreeNode* root) {
    if (root == NULL) {
        cout << "N ";
        return;
    }
    cout << root->val << " ";
    printPreorder(root->left);
    printPreorder(root->right);
}

void freeTree(TreeNode* root) {
    if (root == NULL) return;
    freeTree(root->left);
    freeTree(root->right);
    delete root;
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(5);

    Codec ser, deser;
    string serializedStr = ser.serialize(root);
    cout << "Serialized: " << serializedStr << endl;

    TreeNode* ans = deser.deserialize(serializedStr);
    cout << "Deserialized Preorder: ";
    printPreorder(ans);
    cout << endl;

    freeTree(root);
    freeTree(ans);

    return 0;
}

