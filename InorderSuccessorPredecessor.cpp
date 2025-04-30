#include<iostream>

using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;

    Node(int value) {
        val = value;
        left = nullptr;
        right = nullptr;
    }
    int getVal(){
        return val;
    }
};

Node* InorderSuccessor(Node* root, Node* &suc, int target){
    if(root==NULL){
        return suc;
    }
    if(root->getVal()>target){
        suc = root;
        return InorderSuccessor(root->left, suc, target);
    }
    else{
        return InorderSuccessor(root->right, suc, target);
    }
    return suc;
} 
Node* InorderPredecessor(Node* root, Node* &suc, int target){
    if(root==NULL){
        return suc;
    }
    if(root->getVal()<target){
        suc = root;
        return InorderPredecessor(root->right, suc, target);
    }
    else{
        return InorderPredecessor(root->left, suc, target);
    }
    return suc;
} 

Node* findEl(Node* root, int target,Node* &parEl){
    if(root==NULL){
        return NULL;
    }
    if(root->right->getVal()==target || root->left->getVal()==target ){
        if(root<parEl && root->getVal()>target){
            parEl = root;
        }
    }
    if(target==root->getVal()){
        return root;
    }
    return findEl(root->left, target, parEl);
    return findEl(root->right, target, parEl);
}

Node* findMin(Node* root){
    if(root->left==NULL){
        return root;
    }
    return findMin(root->left);
}

Node* InorderSuccessor2(Node* root, int target, Node* &suc){
    cout<<"entered inorder successor\n";
    Node* parEl;
    root = findEl(root, target, parEl);
    if(root==NULL){
        cout<<"Element not in tree!\n";
        return root;
    }
    else if(root->right==NULL){
        return parEl;
    }
    return findMin(root->right);
}

void InOrderTraversal(Node* root){
    if(root==NULL) return ;
    InOrderTraversal(root->left);
    cout<<root->getVal()<<" ";
    InOrderTraversal(root->right);
    return ;
}

int main(){
    Node* root = new Node(5);
    root->left = new Node(3);
    root->right=new Node(7);
    root->left->left = new Node(2);
    root->left->right = new Node(4);
    root->left->left->left = new Node(1);
    root->right->left = new Node(6);
    root->right->right = new  Node(9);
    root->right->right->left = new Node(8);
    root->right->right->right = new Node(10);
    InOrderTraversal(root);
    Node* suc = NULL;
    int target = 3;
    Node* ans = InorderSuccessor(root, suc, target);
    if(ans==NULL){
        cout<<"\nelement: "<<target<<" is largest in tree!\n";
        return 0;
    }
    cout<<"\nSuccessor of "<<target<< " is "<<ans->getVal()<<endl;
    // for(target =0;target< 11;target++){
    //     cout<<target<<" "<<InorderSuccessor2(root, target, suc)->getVal()<<endl;
    // }
    ans = InorderPredecessor(root, suc, target);
    if(ans==NULL){
        cout<<"element: "<<target<<" is smallest in tree!\n";
        return 0;
    }
    cout<<"Predecessor of "<<target<< " is "<<ans->getVal()<<endl;
    return 0;
}
