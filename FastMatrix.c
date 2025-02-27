/**
 * Mark Futato
 * COT 3100C - Section 2 (401)
 * H4 - Problem 3 Companion Code
 */

#include <stdio.h>

#define MOD 1000000007 // mod 10^9+7

typedef long long
    ll; // truncate long long so i don't have to type it so many times

/**
 * @brief Multiplies two 3x3 matrices modulo MOD.
 *
 * Performs matrix multiplication on two 3x3 matrices, `A[][]` and `B[][]`,
 * modulo MOD, defined above. The result is stored in `C[][]`.
 *
 * @param A The first input matrix (3x3).
 * @param B The second input matrix (3x3).
 * @param C The output matrix (3x3) where the result is stored.
 *
 * @return none
 *
 * @todo done
 */
void multiplyMatrix(ll A[3][3], ll B[3][3], ll C[3][3]) {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      C[i][j] = 0;
      for (int k = 0; k < 3; k++) {
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
void copyMatrix(ll destination[3][3], ll source[3][3]) {
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++)
      destination[i][j] = source[i][j];
}

/**
 * Fast exponentiation for a 3x3 matrix: result = T^exp.
 * @param
 * @param
 * @param
 * @return
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
 * @brief Simple matrix multiplication of a 3x3 matrix with a 3x1 vector:
 * res = m * vec.
 *
 * @param matrix A 3x3 matrix
 */
void multiplyMatrixByVector(ll matrix[3][3], ll vector[3], ll result[3]) {
  int i, j;
  for (i = 0; i < 3; i++) {
    result[i] = 0;
    for (j = 0; j < 3; j++) {
      result[i] = (result[i] + matrix[i][j] * vector[j]) % MOD;
    }
  }
}

int main() {
  ll n;
  printf("Enter a number up to 10^12: ");
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
   * Companion matrix corresponding to the second "given":
   * g(n) = 2*g(n-1) + g(n-2) - 2*g(n-3)
   * companion = [ [2, 1, -2], [1, 0, 0], [0, 1, 0] ]
   * Replace -2 with MOD-2.
   */
  ll companion[3][3] = {{2, 1, MOD - 2}, {1, 0, 0}, {0, 1, 0}};

  // Compute T^(n-3)
  ll compExponent[3][3];
  powerMatrix(companion, n - 3, compExponent);

  // Initial vector for the first given: g(3), g(2), g(1)
  ll initial[3] = {6, 5, 1};
  ll result[3];
  multiplyMatrixByVector(compExponent, initial, result);

  // The first element of the resulting vector is g(n) mod MOD.
  printf("%lld\n", result[0]);

  return 0;
}
