#include <stdio.h>
#define MOD 1000000007

int main()
{
    int i;
    long long g[1001];
    g[1] = 1;
    g[2] = 5;
    g[3] = 6;
    for (i = 4; i <= 1000; i++)
    {
        g[i] = (2 * g[i - 1] + g[i - 2] - 2 * g[i - 3]) % MOD;
        if (g[i] < 0)
            g[i] += MOD; // ensure non-negative result
    }
    for (i = 1; i <= 1000; i++)
    {
        printf("g(%d) = %lld\n", i, g[i]);
    }
    return 0;
}
