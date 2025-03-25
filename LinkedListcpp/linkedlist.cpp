#include <iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;
    node(int val){
       data = val;
       next = NULL;
    }
    ~node(){
        cout << "\n destructor was called \n";
    }
};

class sll{
    public:
    node* head;

    sll(){
        head = NULL;
    }
    void addBeforeHead(int val){
        node* n = new node(val);
        if(head==NULL){
            head = n;
            return;
        }
        n->next = head;
        head = n;
    }
        
};