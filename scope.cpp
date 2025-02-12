#include <iostream>
using namespace std;

int m = 10;

int main(){
    int m = 5;
    cout << "local value of m: "<< m << endl;
    cout << "global value of m:" << ::m;
}