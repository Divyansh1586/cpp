#include <iostream>
#include <climits>
using namespace std;

class node {
public:
    node *next;
    int data;
    node(int val) {
        data = val;
        next = nullptr;
    }
};

class stck {
public:
    node *top1;
    int siz;

    stck() {
        top1 = nullptr;
        siz = 0;
    }

    bool isEmpty() {
        return top1 == nullptr;
    }

    void push(int x) {
        node *n = new node(x);
        siz++;
        if (top1 == nullptr) {
            top1 = n;
            return;
        }
        n->next = top1;
        top1 = n;
    }

    int top() {
        if (isEmpty()) {
            cout << "\nStack is empty\n";
            return -1;
        }
        return top1->data;
    }

    void pop() {
        if (isEmpty()) {
            cout << "\nStack is empty\n";
            return;
        }
        node *temp = top1;
        top1 = top1->next;
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

    int sz() {
        return siz;
    }
};

class maxstack {
public:
    stck s1, s2;

    maxstack() {}

    bool isEmpty() {
        return s1.sz() == 0;
    }

    void push(int x) {
        s1.push(x);
        if (s2.isEmpty() || x >= s2.top()) {
            s2.push(x);
        } else {
            s2.push(s2.top());  // Maintain the previous max
        }
    }

    void pop() {
        if (!isEmpty()) {
            s1.pop();
            s2.pop();
        }
    }

    int top() {
        return s1.top();
    }

    int getMax() {
        if (isEmpty()) {
            cout << "\nStack is empty\n";
            return INT_MIN;
        }
        return s2.top();
    }

    void display() {
        s1.display();
    }
};

class minstack {
public:
    stck s1, s2;

    minstack() {}

    bool isEmpty() {
        return s1.sz() == 0;
    }

    void push(int x) {
        s1.push(x);
        if (s2.isEmpty() || x <= s2.top()) {
            s2.push(x);
        } else {
            s2.push(s2.top());  // Maintain the previous min
        }
    }

    void pop() {
        if (!isEmpty()) {
            s1.pop();
            s2.pop();
        }
    }

    int top() {
        return s1.top();
    }

    int getMin() {
        if (isEmpty()) {
            cout << "\nStack is empty\n";
            return INT_MAX;
        }
        return s2.top();
    }

    void display() {
        s1.display();
    }
};

int main() {
    minstack s;

    s.push(10);
    s.push(20);
    s.push(5);
    s.push(30);

    cout << "Stack min: " << s.getMin() << '\n';

    cout << "Top element: " << s.top() << '\n';

    s.pop();
    cout << "After popping, top element: " << s.top() << '\n';
    cout << "Stack min after pop: " << s.getMin() << '\n';

    return 0;
}
