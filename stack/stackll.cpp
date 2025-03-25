#include <iostream>
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

    stck()
    {
        top1 = nullptr;
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

    void sort(stck &s1)
    {
        stck s2;  
        while (!s1.isEmpty())
        {
            int temp = s1.top();
            s1.pop();

            while (!s2.isEmpty() && s2.top() > temp)
            {
                s1.push(s2.top());
                s2.pop();
            }

            s2.push(temp);
        }

        while (!s2.isEmpty())
        {
            s1.push(s2.top());
            s2.pop();
        }
    }
};

int main()
{
    stck s;

    s.push(10);
    s.push(20);
    s.push(5);
    s.push(30);

    cout << "Stack: ";
    s.display();

    cout << "\nTop element: " << s.top() << '\n';


    s.sort(s);
    s.display();

    return 0;
}