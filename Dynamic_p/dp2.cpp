#include <iostream>
#include <vector>
#include <climits> // For INT_MAX
#include <unordered_map>
using namespace std;


unordered_map <int, int> memo;



const int INF = 1e9; // Large value representing infinity

vector<int> coins = {1, 4, 5};

int solve(int x, const vector<int>& coins) {
    if(memo.find(x)!=memo.end()) return memo[x];
    if (x < 0) return INF; // No valid solution
    if (x == 0) return 0;  // Base case: No coins needed

    int best = INF;
    for (int c : coins) {
        int res = solve(x - c, coins);
        if (res != INF) {  // Only add 1 if res is not INF
            best = min(best, res + 1);
        }
    }
    memo[x] = best;

    return best;
}

int solve1(int x, const vector<int>& coins) {
    if (x < 0) return INF; // No valid solution
    if (x == 0) return 0;  // Base case: No coins needed

    int best = INF;
    for (int c : coins) {
        int res = solve(x - c, coins);
        if (res != INF) {  // Only add 1 if res is not INF
            best = min(best, res + 1);
        }
    }

    return best;
}

int main() {
    int result = solve1(1000, coins);
    cout << (result == INF ? -1 : result) << endl; // Print result (-1 if no solution)
    return 0;
}
