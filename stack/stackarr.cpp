#include <iostream>
#include <utility>


using namespace std;

class stck{
    public:
    int topidx, size = 5000;
    int arr[5000];

    stck(){
        topidx = -1;
    }

    bool isEmpty(){
        if(topidx==-1) return true;
        return false;
    }

    void push(int x){
        ++topidx;
        if(topidx >= size){
            cout << "\n stack is full \n";
            return;
        }
        arr[topidx] = x;
    }

    int top(){
        if(isEmpty()){
            cout << "\n stack is empty \n";
            return topidx;
        }
        return arr[topidx];
    }
    void pop(){
        if(isEmpty()){
            cout << "\n stack is empty \n";
            return;
        }
        --topidx;
    }
    void display(){
        int temp = topidx;
        while(temp!=-1){
            cout << arr[temp] << " ";
            temp--;
        }
    }
};

int main(){
    stck s;
    s.pop();
    s.top();
    s.push(1);
    cout << s.top();
    s.pop();
    cout << '\n' << s.top();
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.display();

}