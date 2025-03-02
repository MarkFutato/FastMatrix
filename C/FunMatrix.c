/**
 * Mark Futato
 * COT 3100C - Section 2 (401)
 * H4 - Problem 3 Companion Code
 */
#include <stdio.h>

#define MOD 1000000007

int main() {
    long long g[1001];
    g[1] = 1;  // base case 1
    g[2] = 5;  // base case 2
    g[3] = 6;  // base case 3
    // Begindex at base case 4 to 1000
    for (int i = 4; i <= 1000; i++) {
        // Given in problem 3
        g[i] = (2 * g[i - 1] + g[i - 2] - 2 * g[i - 3]) % MOD;
        if (g[i] < 0) g[i] += MOD;  // ensure non-negative result
    }
    for (int i = 1; i <= 1000; i++) {
        printf("g(%d) = %lld\n", i, g[i]);
    }
    return 0;
}
