#include <iostream>
using namespace std;

int main(){
    int a = 5, b = 3;
    cout << (a&b) << endl;
    cout << (a|b) << endl;
    cout << (a^b) << endl;
    cout << (~a) << endl;
    cout << (a<<1) << endl;
    cout << (b>>1) << endl;
}