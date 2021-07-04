def fun(report_card, order):
    if order == 0:
        new_report_card = sorted(report_card, key=lambda x: x[1], reverse=True)
    else:
        new_report_card = sorted(report_card, key=lambda x: x[1], reverse=False)
    return new_report_card


while True:
    try:
        n = int(input())
        order = int(input())
        report_card = []
        for _ in range(n):
            line = input().split(' ')
            report_card.append((line[0], int(line[1])))
        ordered_report_card = fun(report_card, order)
        for each in ordered_report_card:
            print(f"{each[0]} {each[1]}")
    except:
        break

