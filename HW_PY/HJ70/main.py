def computation(mat, rule):
    stack = []
    res = 0
    for c in rule:
        if ord('A') <= ord(c) <= ord('Z'):
            stack.append(mat[ord(c)-ord('A')])
        if c == ')':
            B = stack[-1]
            stack.pop()
            A = stack[-1]
            stack.pop()
            res = res + A[0] * B[1] * A[1]
            stack.append([A[0], B[1]])

    return res


while True:
    try:
        n = int(input())
        mat = []
        for _ in range(n):
            line = [int(j) for j in input().split()]
            mat.append(line)
        rule = input()

        print(computation(mat, rule))

    except:
        break



