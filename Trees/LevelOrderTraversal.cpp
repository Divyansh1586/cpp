#include <iostream>
#include <queue>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) {
        val = value;
        left = nullptr;
        right = nullptr;
    }
};

TreeNode* buildTreeFromLevelOrder(vector<int>& values) {
    if (values.empty() || values[0] == -1) return nullptr;
    //[1 2 3 4 5 -1 -1 -1 -1 -1 -1]

    TreeNode* root = new TreeNode(values[0]);
    queue<TreeNode*> q;
    q.push(root);

    int i = 1;
    //4 5  
    while (!q.empty() && i < values.size()) {
        TreeNode* current = q.front();
        q.pop();

        // Left child
        if (values[i] != -1) {
            current->left = new TreeNode(values[i]);
            q.push(current->left);
        }
        i++;

        // Right child
        if (i < values.size() && values[i] != -1) {
            current->right = new TreeNode(values[i]);
            q.push(current->right);
        }
        i++;
    }

    return root;
}

// Optional: Preorder traversal to test the tree
void preorder(TreeNode* root) {
    if (!root) return;
    cout << root->val << " ";
    preorder(root->left);
    preorder(root->right);
}

int main() {
    vector<int> input;
    int x;

    // Reading input until EOF
    while (cin >> x) {
        input.push_back(x);
    }

    TreeNode* root = buildTreeFromLevelOrder(input);

    // Verify with preorder traversal
    cout << "Preorder Traversal: ";
    preorder(root);
    cout << endl;

    return 0;
}
