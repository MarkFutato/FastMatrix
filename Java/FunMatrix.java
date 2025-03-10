
package Java;

import java.util.Scanner;

public class FunMatrix {
    public static final int MOD = 1000000007;

    public static void main(String[] args) {
        long n;
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter a whole number up to 10^12: ");
        n = scanner.nextLong();

        if (n == 1) {
            System.out.println("1");
            scanner.close();
            return;
        }
        if (n == 2) {
            System.out.println("5");
            scanner.close();
            return;
        }
        if (n == 3) {
            System.out.println("6");
            scanner.close();
            return;
        }

        long[][] companion = {
                { 2, 1, MOD - 2 },
                { 1, 0, 0 },
                { 0, 1, 0 }
        };
        long[][] companionExponent = new long[3][3];
        powerMatrix(companion, n - 3, companionExponent);

        long[] initial = { 6, 5, 1 };
        long[] result = new long[3];
        multiplyMatrixByVector(companionExponent, initial, result);

        System.out.println(result[0]);

        scanner.close();
    }

    public static void powerMatrix(long companion[][], long exponent, long result[][]) {
        long[][] indentity = {
                { 1, 0, 0 },
                { 0, 1, 0 },
                { 0, 0, 1 }
        };
        copyMatrix(result, indentity);
        long[][] companionCopy = new long[3][3];
        copyMatrix(companionCopy, companion);
        long[][] temp = new long[3][3];
        while (exponent > 0) {
            if ((exponent & 1) == 1) {
                multiplyMatrix(result, companionCopy, temp);
                copyMatrix(result, temp);
            }
            multiplyMatrix(companionCopy, companionCopy, temp);
            copyMatrix(companionCopy, temp);
            exponent >>= 1;
        }
    }

    public static void multiplyMatrix(long A[][], long B[][], long C[][]) {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                C[i][j] = 0;
                for (int k = 0; k < 3; k++) {
                    C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
                }
            }
        }
    }

    public static void multiplyMatrixByVector(long matrix[][], long vector[], long result[]) {
        for (int i = 0; i < 3; i++) {
            result[i] = 0;
            for (int j = 0; j < 3; j++) {
                result[i] = (result[i] + (matrix[i][j] * vector[j]) % MOD) % MOD;
            }
        }
    }

    public static void copyMatrix(long destination[][], long source[][]) {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                destination[i][j] = source[i][j];
            }
        }
    }

}
