#include <iostream>
#include <queue>
#include <vector>
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

vector <vector<int>> res;
int mx = 0;

int paths(TreeNode* root, vector <int> temp){
    if(!root) return 0;
    temp.push_back(root->val);
    if(!root->left && !root->right) res.push_back(temp);
    int left = paths(root->left, temp);
    int right = paths(root->right, temp);

    mx = max(left, right); 

    return 1 + max(left, right);
}



int main() {
    vector<int> input;
    int x;
    int n;
    cin >> n;
    // Reading input until EOF
    while (n--) {
        cin >> x;
        input.push_back(x);
    }

    TreeNode* root = buildTreeFromLevelOrder(input);

    // Verify with preorder traversal
    // cout << "Preorder Traversal: ";
    // preorder(root);
    // cout << endl;
    vector <int> temp;
    paths(root, temp);
    for(int i = 0; i < res.size(); i++){
        
        //if(mx + 1 ==  res[i].size()){
            for(int j = 0; j < res[i].size(); j++){
                cout << res[i][j] << " ";
            }
            cout << '\n';
       // }
        
    }

    return 0;
}
