#include <iostream>
using namespace std;

class TreeNode{
    public:
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val){
        data = val;
        left = nullptr;
        right = nullptr;
    }
};


class Tree{
    public:
    TreeNode* root;
    Tree(){
        root = nullptr;
    }
    void buildTree(){
        if(root==nullptr){
            cout << "Enter Data for Root: ";
            int n;
            cin >> n;
            root = new TreeNode(n);

            cout << "Enter Data for Left of " << root->data << ": ";
            int l;
            cin >> l;
            if(l!=-1){
                TreeNode* left = new TreeNode(l);
                buildTree(left);
            }

            cout << "Enter Data for Right: ";
            int r;
            cin >> r;
            if(r==-1) return;
            TreeNode* right = new TreeNode(r);
            buildTree(right);
        }
    }
    private:
    void buildTree(TreeNode* root){
        
            cout << "Enter Data for Left of " << root->data << ": ";
            int l;
            cin >> l;
            if(l==-1) return;
            TreeNode* left = new TreeNode(l);
            buildTree(left);

            cout << "Enter Data for Right: "<< root->data << ": ";
            int r;
            cin >> r;
            if(r==-1) return;
            TreeNode* right = new TreeNode(r);
            buildTree(right);
    }
};