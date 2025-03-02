#include <iostream>
using namespace std;

typedef long long ll;

const ll MOD = 1000000007;

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

void copyMatrix(ll destination[3][3], ll source[3][3]) {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            destination[i][j] = source[i][j];
}

void powerMatrix(ll companion[3][3], ll exponent, ll result[3][3]) {
    ll identity[3][3] = { {1, 0, 0}, {0, 1, 0}, {0, 0, 1} };
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

void multiplyMatrixByVector(ll matrix[3][3], ll vector[3], ll result[3]) {
    for (int i = 0; i < 3; i++) {
        result[i] = 0;
        for (int j = 0; j < 3; j++) {
            result[i] = (result[i] + matrix[i][j] * vector[j]) % MOD;
        }
    }
}

int main() {
    ll n;
    cout << "Enter a whole number up to 10^12: ";
    cin >> n;

    if (n == 1) {
        cout << "1\n";
        return 0;
    } else if (n == 2) {
        cout << "5\n";
        return 0;
    } else if (n == 3) {
        cout << "6\n";
        return 0;
    }

    ll companion[3][3] = {
        {2, 1, MOD - 2},
        {1, 0, 0},
        {0, 1, 0}
    };

    ll companionExponent[3][3];
    powerMatrix(companion, n - 3, companionExponent);

    ll initial[3] = {6, 5, 1};
    ll result[3];
    multiplyMatrixByVector(companionExponent, initial, result);

    cout << result[0] << "\n";

    return 0;
}
