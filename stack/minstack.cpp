#include <iostream>
#include <climits>
using namespace std;

class node
{
public:
    node *next;
    int data;
    node(int val)
    {
        data = val;
        next = nullptr;
    }
};

class stck
{
public:
    node *top1;
    int siz;

    stck()
    {
        top1 = nullptr;
        siz = 0;
    }

    bool isEmpty()
    {
        if (top1 == nullptr)
        {
            return true;
        }
        return false;
    }

    void push(int x)
    {
        node *n = new node(x);
        siz++;
        if (top1 == nullptr)
        {
            top1 = n;
            return;
        }
        n->next = top1;
        top1 = n;
    }

    int top()
    {
        if (isEmpty())
        {
            cout << "\nStack is empty\n";
        }
        else
        {
            return top1->data;
        }
        return -1;
    }

    void pop()
    {
        if (isEmpty())
        {
            cout << "\nStack is empty\n";
            return;
        }
        node *temp = top1;
        top1 = top1->next;
        temp->next = nullptr;
        delete temp;
        siz--;
    }

    void display()
    {
        node *temp = top1;
        while (temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
    int sz(){
        return siz;
    }

    
};

class maxstack{
    public:
    stck s1;
    stck s2;
    int max;
    maxstack(){
        max = INT_MIN;
    }

    bool isEmpty(){
        return s1.isEmpty();
    }

    void push(int x){
        s1.push(x);
        if(max < x){
            max = x;
        }
        s2.push(max);
    }
    void pop(){
        if(s1.isEmpty()) return;
        s1.pop();
        s2.pop();
        if(s1.sz()==0) max = INT_MIN;
    }
    int top(){
        return s1.top();
    }
    int getMax(){
        return max;
    }
    void display(){
        s1.display();
    }

};

class minstack{
    public:
    stck s1;
    stck s2;
    int min;
    minstack(){
        min = INT_MAX;
    }

    bool isEmpty(){
        return s1.isEmpty();
    }

    void push(int x){
        s1.push(x);
        if(min > x){
            min = x;
        }
        s2.push(min);
    }
    void pop(){
        if(s1.isEmpty()) return;
        s1.pop();
        s2.pop();
        if(s1.sz()==0) min = INT_MAX;
    }
    int top(){
        return s1.top();
    }
    int getMin(){
        return min;
    }
    void display(){
        s1.display();
    }

};

int main()
{
    minstack s;

    s.push(10);
    s.push(20);
    s.push(30);

    cout << "Stack min: " << s.getMin();
    

    cout << "\nTop element: " << s.top() << '\n';

    s.pop();
    cout << "After popping, top element: " << s.top() << '\n';

    return 0;
}