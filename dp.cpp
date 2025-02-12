#include <iostream>
using namespace std;
#include <unordered_map>

unordered_map <int, int> memo; 
// TC : o(2^n)
int fib1(int n){
    int res;

    if(n<=2) res = 1;

    else res = fib1(n-1) + fib1(n-2);
    
    return res;
}

int fib2(int n){
    if(memo.find(n)!=memo.end()) return memo[n];
    int res;

    if(n<=2) res = 1;

    else res = fib1(n-1) + fib1(n-2);
    
    memo[n] = res;

    return res;

}

int fib3(int n){
    unordered_map <int, int> memo1;
    int res;
    for(int i = 1; i <= n; i++){
        if(i <= 2){
            res = 1;
        }
        else res = memo1[i-1] + memo1[i-2];
        memo1[i] = res;
    }
    return memo1[n];
}

int main(){
    cout << fib3(30) << " " << fib2(30) << '\n';

}