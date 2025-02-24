#include <stdio.h>
#define MOD 1000000007

typedef long long ll;

/**
 * @brief This function is specifically for matrix multiplication
 *
 * Full form description
 *
 * @param A 2D matrix
 * @param B
 * @param C
 * @return void
 */
void multiplyMatrix(ll A[3][3], ll B[3][3], ll C[3][3])
{
    int i, j, k;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            C[i][j] = 0;
            for (k = 0; k < 3; k++)
            {
                C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
            }
        }
    }
}

/**
 * Copy a 3x3 matrix from source to dest.
 * @param source 2D array..asm
 * @param dest 2D array..balkdjapsdklfjg
 * @return void
 */
void copyMatrix(ll source[3][3], ll dest[3][3])
{
    int i, j;
    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
            dest[i][j] = source[i][j];
}

/**
 * Fast exponentiation for a 3x3 matrix: result = T^exp.
 * @param
 * @param
 * @param
 * @return
 */
void powerMatrix(ll T[3][3], ll exp, ll result[3][3])
{
    int i, j;
    ll identity[3][3] = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
    copyMatrix(identity, result);

    ll T_copy[3][3];
    copyMatrix(T, T_copy);

    ll temp[3][3];
    while (exp > 0)
    {
        if (exp & 1)
        {
            multiplyMatrix(result, T_copy, temp);
            copyMatrix(temp, result);
        }
        multiplyMatrix(T_copy, T_copy, temp);
        copyMatrix(temp, T_copy);
        exp >>= 1;
    }
}

/**
 * Multiply a 3x3 matrix with a 3x1 vector: res = M * vec.
 */
void multiplyMatrixVector(ll M[3][3], ll vec[3], ll res[3])
{
    int i, j;
    for (i = 0; i < 3; i++)
    {
        res[i] = 0;
        for (j = 0; j < 3; j++)
        {
            res[i] = (res[i] + M[i][j] * vec[j]) % MOD;
        }
    }
}

int main()
{
    ll n;
    printf("Enter a number up to 10^12: ");
    scanf("%lld", &n);

    // Base cases.
    if (n == 1)
    {
        printf("1\n");
        return 0;
    }
    else if (n == 2)
    {
        printf("5\n");
        return 0;
    }
    else if (n == 3)
    {
        printf("6\n");
        return 0;
    }

    // Transition matrix T corresponding to: g(n) = 2*g(n-1) + g(n-2) - 2*g(n-3)
    // T = [ [2, 1, -2], [1, 0, 0], [0, 1, 0] ]
    // Replace -2 with MOD-2.
    ll T[3][3] = {{2, 1, MOD - 2}, {1, 0, 0}, {0, 1, 0}};

    // Compute T^(n-3)
    ll Texp[3][3];
    powerMatrix(T, n - 3, Texp);

    // Initial vector [g(3), g(2), g(1)] = [6, 5, 1]
    ll init[3] = {6, 5, 1};
    ll res[3];
    multiplyMatrixVector(Texp, init, res);

    // The first element of the resulting vector is g(n) mod MOD.
    printf("%lld\n", res[0]);
}