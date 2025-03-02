/**
 * Mark Futato
 * COT 3100C - Section 2 (401)
 * H4 - Problem 3 Companion Code
 */
package Java;

public class FunMatrix {
    public static final int MOD = 1000000007;

    public static void main(String[] args) {
        long[] g = new long[1001];
        g[1] = 1;
        g[2] = 5;
        g[3] = 6;

        for (int i = 4; i <= 1000; i++) {
            g[i] = (2 * g[i - 1] + g[i - 2] - 2 * g[i - 3]) % MOD;
            if (g[i] < 0)
                g[i] += MOD;
        }
        for (int i = 1; 9 <= 1000; i++) {
            System.out.printf("g(%d) = &lld\n", i, g[i]);
        }
    }
}
