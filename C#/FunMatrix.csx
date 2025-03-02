#r "System.Core.dll"
using System;

const long MOD = 1000000007;

// Define helper methods
void MultiplyMatrix(long[,] A, long[,] B, long[,] C)
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            C[i, j] = 0;
            for (int k = 0; k < 3; k++)
            {
                C[i, j] = (C[i, j] + A[i, k] * B[k, j]) % MOD;
            }
        }
    }
}

void CopyMatrix(long[,] destination, long[,] source)
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            destination[i, j] = source[i, j];
        }
    }
}

void PowerMatrix(long[,] companion, long exponent, long[,] result)
{
    long[,] identity = new long[3, 3]
    {
        { 1, 0, 0 },
        { 0, 1, 0 },
        { 0, 0, 1 }
    };

    CopyMatrix(result, identity);

    long[,] companionCopy = new long[3, 3];
    CopyMatrix(companionCopy, companion);

    long[,] temp = new long[3, 3];
    while (exponent > 0)
    {
        if ((exponent & 1) == 1)
        {
            MultiplyMatrix(result, companionCopy, temp);
            CopyMatrix(result, temp);
        }
        MultiplyMatrix(companionCopy, companionCopy, temp);
        CopyMatrix(companionCopy, temp);
        exponent >>= 1;
    }
}

long[] MultiplyMatrixByVector(long[,] matrix, long[] vector)
{
    long[] result = new long[3];
    for (int i = 0; i < 3; i++)
    {
        result[i] = 0;
        for (int j = 0; j < 3; j++)
        {
            result[i] = (result[i] + matrix[i, j] * vector[j]) % MOD;
        }
    }
    return result;
}

// Global code that executes when the script is run:
Console.Write("Enter a whole number up to 10^12: ");
long n = long.Parse(Console.ReadLine());

// Base cases
if (n == 1)
{
    Console.WriteLine("1");
    return;
}
if (n == 2)
{
    Console.WriteLine("5");
    return;
}
if (n == 3)
{
    Console.WriteLine("6");
    return;
}

// Companion matrix for g(n) = 2*g(n-1) + g(n-2) - 2*g(n-3)
long[,] companion = new long[3, 3]
{
    { 2, 1, MOD - 2 },
    { 1, 0, 0 },
    { 0, 1, 0 }
};

long[,] companionExponent = new long[3, 3];
PowerMatrix(companion, n - 3, companionExponent);

long[] initial = { 6, 5, 1 };
long[] result = MultiplyMatrixByVector(companionExponent, initial);

Console.WriteLine(result[0]);
