#include <iostream>
using namespace std;

class node{
    public:
    node* next;
    int data;
    node(int val){
        data=val;
    }
};

class Q{
    public:
    node* head;
    node* tail;
    Q(): head(nullptr), tail(nullptr){}
    void push(int val){
        node* n = new node(val);
        if(head==nullptr){
            head=n;
            tail=n;
            return;
        }
        n->next = tail;
        tail = n;
    }
    void pop(){
        if(tail==nullptr) return;
        node* temp = tail;
        tail = tail -> next;
        temp->next=nullptr;
        delete temp;
    }
    int front(){
        if(head==nullptr) return -1;
        return head->data;
    }
    int back(){
        if(tail==nullptr) return -1;
        return tail->data;
    }
    void display(){
        node* temp = tail;
        while(tail!=nullptr){
            cout << tail->data << " ";
            tail = tail->next;
        }
    }
};

int main(){
    Q q;
    q.push(1);
    q.push(2);
    q.pop();
    q.push(3);
    q.push(4);
    q.display();
    
}