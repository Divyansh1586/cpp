#include <iostream>
using namespace std;

class node{
    public:
    node* next;
    node* prev;
    int data;

    node(int val): next(nullptr), prev(nullptr), data(val){}
};

class dll{
    public:
    node* head;
    dll(){
        head = nullptr;
    }

    void add(int val){
        node* n = new node(val);
        if(head==nullptr){
            head = n;
            return;
        }
        node* temp = head;
        while(temp->next!=nullptr){
            temp = temp->next;
        }
        n = temp -> next;
        temp = n -> prev;
    }
};

int main(){

}