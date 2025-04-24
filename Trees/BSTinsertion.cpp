#include <iostream>
using namespace std;

class node{
public:
    int data;
    node* left;
    node* right;

    node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

node* insert(node* root, int val){
    if(root == nullptr){
        node* newNode = new node(val);
        return newNode;
    }
    if(val < root->data){
        root->left = insert(root->left, val);
    } else {
        root->right = insert(root->right, val);
    }
    return root;
}

int main(){


}