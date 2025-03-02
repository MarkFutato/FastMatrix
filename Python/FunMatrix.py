"""
Mark Futato
COT 3100C - Section 2 (401)
H4 - Problem 3 Companion Code
"""

MOD = 10**9+7

g = [0] * 1001
g[1] = 1
g[2] = 2
g[3] = 6

for i in range(4, 1000):
    g[i] = (2 * g[i - 1] + g[i - 2] - 2 * g[i - 3]) % MOD
for i in range(1, 1000):
    print("g(" + str(i) + "] = " + str(g[i]))