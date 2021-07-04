def matmulProduct(A, B):
    x = len(A)
    y = len(A[0])
    z = len(B[0])

    C = [[0 for _ in range(z)] for _ in range(x)]

    for i in range(x):
        for j in range(z):
            temp = 0
            for k in range(y):
                temp = temp + A[i][k] * B[k][j]
            C[i][j] = temp

    return C


while True:
    try:
        x = int(input())
        y = int(input())
        z = int(input())

        print(x)
        print(y)
        print(z)

        A = [[0 for _ in range(y)] for _ in range(x)]
        B = [[0 for _ in range(z)] for _ in range(y)]

        for i in range(x):
            line = input().split()
            for j in range(y):
                A[i][j] = int(line[j])

        for i in range(y):
            line = input().split()
            for j in range(z):
                B[i][j] = int(line[j])

        print(A)
        print(B)

        C = matmulProduct(A, B)

        for line in C:
            for v in line:
                print(v, end=' ')
            print()

    except:
        break