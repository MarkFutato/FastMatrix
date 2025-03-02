/**
 * Mark Futato
 * COT 3100C - Section 2 (401)
 * H4 - Problem 3 Companion Code
 */

#include <stdio.h>

#define MOD 1000000007  // mod 10^9+7

typedef long long ll;  // abbreviate `long long` so I don't have to type it out

/**
 * @brief Multiplies two 3x3 matrices modulo MOD.
 *
 * Performs matrix multiplication on two 3x3 matrices, `A[][]` and `B[][]`,
 * modulo MOD, defined above. Result is stored in 3x3 `C[][]`.
 *
 * @param A Input matrix. `companionCopy` or `result` from `powerMatrix()`
 * @param B Input matrix. 'companionCopy` from `powerMatrix()`
 * @param C The output matrix, null `temp` from `powerMatrix()`
 *
 * @return void
 *
 * @todo done
 */
void multiplyMatrix(ll A[3][3], ll B[3][3], ll C[3][3]) {
    for (int i = 0; i < 3; i++) {      // for 3 rows
        for (int j = 0; j < 3; j++) {  // for 3 cols
            C[i][j] = 0;               // initialize to 0, since passed as null
            for (int k = 0; k < 3; k++) {  // for sum index
                C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
            }
        }
    }
}

/**
 * @brief Copies 3x3 matrix from source to dest to initialize
 *
 * @param source Source array from `powerMatrix()`
 * @param destination Destination array from `powerMatrix()`
 *
 * @return void
 *
 * @todo done
 */
void copyMatrix(ll destination[3][3], ll source[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            destination[i][j] = source[i][j];
        }
    }
}

/**
 * @brief Fast exponentiation for 3x3 matrix: result = companion^exponent.
 *
 * 1. initialize `result` to `identity` with `copyMatrix` since any matrix
 * raised to power 0 is identity
 *
 * 2. create 'companionCopy` to update without affecting `companion`
 *
 * 3. while exponent is greater than 0:
 *
 * 3.a. if exponent is odd
 *
 * 3.a.i. multiply `companionCopy` with `result` and store in
 * `temp`
 *
 * 3.a.ii. update `result` with `temp`
 *
 * 3.b. square `companionCopy` (sending it as both args to `multiplyMatrix()`)
 * and store result back in `companionCopy`
 *
 * 3.c. divide exp by 2 with right shift to halve
 *
 * 4. when complete `result` stores companion^exponent
 *
 * @param companion Companion matrix, refer to `main()` for def
 * @param exponent User input n - 3 passed from `main()`
 * @param result Null matrix to store result
 *
 * @return void
 *
 * @todo run test, comment out, finish header
 */
void powerMatrix(ll companion[3][3], ll exponent, ll result[3][3]) {
    ll identity[3][3] = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
    copyMatrix(result, identity);

    ll companionCopy[3][3];
    copyMatrix(companionCopy, companion);

    ll temp[3][3];
    while (exponent > 0) {
        if (exponent & 1) {
            multiplyMatrix(result, companionCopy, temp);
            copyMatrix(result, temp);
        }
        multiplyMatrix(companionCopy, companionCopy, temp);
        copyMatrix(companionCopy, temp);
        exponent >>= 1;
    }
}

/**
 * @brief Multiplication for a 3x3 matrix with a 3x1 vector:
 * result = result + matrix * vec  % (10^9 + 7)
 *
 * @param matrix 3x3 matrix, passed as `companionExponent` from `main()` storing
 * 3x3 `result` from `powerMatrix()`
 * @param vector 3x1 initial vector = {6, 5, 1} from `main()`
 * @param result 3x1 null vector to store result (NOT 3x3 RESULT)
 *
 * @return void
 *
 * @todo done
 */
void multiplyMatrixByVector(ll matrix[3][3], ll vector[3], ll result[3]) {
    for (int i = 0; i < 3; i++) {
        result[i] = 0;  // initialize null indices to 0
        for (int j = 0; j < 3; j++) {
            result[i] = (result[i] + matrix[i][j] * vector[j]) % MOD;
        }
    }
}

int main() {
    ll n;
    printf("Enter a whole number up to 10^12: ");
    scanf("%lld", &n);

    // Base cases for P(1), P(2), P(3)
    if (n == 1) {
        printf("1\n");
        return 0;
    } else if (n == 2) {
        printf("5\n");
        return 0;
    } else if (n == 3) {
        printf("6\n");
        return 0;
    }

    /**
     * Companion matrix corresponding to second "given" from assignment:
     * g(n) = 2*g(n-1) + g(n-2) - 2*g(n-3)
     * companion = [ [2, 1, -2], [1, 0, 0], [0, 1, 0] ]
     * Replace -2 with MOD-2.
     */
    ll companion[3][3] = {{2, 1, MOD - 2}, {1, 0, 0}, {0, 1, 0}};

    // Compute companion^(n-3)
    ll companionExponent[3][3];
    powerMatrix(companion, n - 3, companionExponent);

    // Initial vector for first "given" in assignemtn: g(3), g(2), g(1)
    ll initial[3] = {6, 5, 1};
    ll result[3];
    multiplyMatrixByVector(companionExponent, initial, result);

    // First element of the resulting vector is g(n) mod MOD.
    printf("%lld\n", result[0]);

    return 0;
}
