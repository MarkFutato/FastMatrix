"""
Mark Futato
COT 3100C - Section 2 (401)
H4 - Problem 3 Companion Code
"""
MOD = 10**9+7

def multiply_matrix(A,B):
    C = [[0] * 3 for _ in range(3)]
    for i in range(3):
        for j in range(3):
            for k in range(3):
                C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD
    return C

def power_matrix(companion, exponent):
    result = [
        [ 1, 0, 0 ],
        [ 0, 1, 0 ],
        [ 0, 0, 1 ]
    ]
    companion_copy = [row[:] for row in companion]
    
    while exponent > 0:
        if exponent & 1:
            result = multiply_matrix(result, companion_copy)
        companion_copy = multiply_matrix(companion_copy, companion_copy)
        exponent //= 2
    return result

def multiply_matrix_by_vector(matrix, vector):
    result = [0, 0, 0]
    for i in range(3):
        for j in range(3):
            result[i] = (result[i] + matrix[i][j] * vector[j]) % MOD
    return result

def main():
    n = int(input("Enter a whole number up to 10^12: "))

    if n == 1:
        print("1")
        return
    if n == 2:
        print("5")
        return
    if n == 3:
        print("6")
        return
    
    companion = [
        [ 2, 1, MOD -2 ],
        [ 1, 0, 0 ],
        [ 0, 1, 0 ]
    ]
    
    companion_exponent = power_matrix(companion, n - 3)
    
    initial = [6, 5, 1]
    
    result = multiply_matrix_by_vector(companion_exponent, initial)
    
    print(result[0])
    
if __name__ == "__main__":
    main()
