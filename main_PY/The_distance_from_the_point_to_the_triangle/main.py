# 计算二维平面上点到三角形的距离
import math


def point2line(line, point):
    if (line[1][0] - line[0][0]) == 0:
        return abs(point[0] - line[0][0])

    A = (line[1][1] - line[0][1])/(line[1][0] - line[0][0])
    B = -1
    C = line[0][1] - A * line[0][0]

    return abs(A * point[0] + B * point[1] + C) / math.sqrt(A ** 2 + B ** 2)


def point2point(point1, point2):
    return math.sqrt((point1[0]-point2[0])**2 + (point1[1]-point2[1])**2)


def CrossProduct(v1, v2):
    # 叉乘
    return v1[0]*v2[1] - v1[1]*v2[0]


def pointInTriangle(triangle, point):
    # 判断点是否在三角形内
    PA = [triangle[0][0] - point[0], triangle[0][1] - point[1]]
    PB = [triangle[1][0] - point[0], triangle[1][1] - point[1]]
    PC = [triangle[2][0] - point[0], triangle[2][1] - point[1]]

    t1 = CrossProduct(PA, PB)
    t2 = CrossProduct(PB, PC)
    t3 = CrossProduct(PC, PA)

    if t1 == 0 or t2 == 0 or t3 == 0:
        return True
    if t1 < 0 and t2 < 0 and t3 < 0:
        return True
    if t1 > 0 and t2 > 0 and t3 > 0:
        return True
    return False


def point2triangle(triangle, point):
    if pointInTriangle(triangle, point):
        return 0

    result = []
    for i in range(3):
        result.append(point2point(triangle[i], point))

    result.append(point2line(triangle[0:2], point))
    result.append(point2line(triangle[1:3], point))
    result.append(point2line(triangle[0:3:2], point))

    result.sort()

    print("===================")
    print(result)

    return result[0]


# Press the green button in the gutter to run the script.
if __name__ == '__main__':
    triangle = [[0, 0],
                [0, 1],
                [1, 0]]

    point = [1, 1]

    print(point2triangle(triangle, point))




