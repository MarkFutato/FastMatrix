/**
 * Mark Futato
 * COT 3100C - Section 2 (401)
 * H4 - Problem 3 Companion Code
 */

#include <iostream>
using namespace std;

#define MOD 1000000007

int main() {
    long long g[1001];
    g[1] = 1; // base case 1
    g[2] = 5; // base case 2
    g[3] = 6; // base case 3
    // begindex at case 4 to 1000
    for (int i = 4; i <= 1000; i++) {
        // given in problem 3
        g[i] = (2 * g[i - 1] + g[i - 2] - 2 * g[i - 3]) % MOD;
        if (g[i] < 0) g[i] += MOD;
    }
    for (int i = 1; i <= 1000; i++) {
         std::cout << "g(" << i << ") = " << g[i] << std::endl;
    }
    return 0;
}