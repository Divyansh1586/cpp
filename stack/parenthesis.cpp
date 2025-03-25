#include <iostream>
#include <unordered_map>
#include <string>
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

bool isValid(string s){
    stck st;
    unordered_map <char, char> mpp;
    mpp[']'] = '[';
    mpp[')'] = '(';
    mpp['}'] = '{';
    
    
    for(auto c : s){
        if(c=='[' || c=='('|| c=='{') st.push(c);
        else{
            if(st.isEmpty() || st.top() != mpp[c]) return false;
            st.pop();
        }
    }
    
    return st.isEmpty();
}

int main(){
    string s = "{[()]}";
    cout << isValid(s);
    

}

