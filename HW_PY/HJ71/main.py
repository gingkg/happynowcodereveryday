def match(pattern, string):
    if len(pattern) == 0 and len(string) == 0:
        return True
    if len(pattern) == 0 or len(string) == 0:
        return False
    if pattern[0] == '?':
        return match(pattern[1:], string[1:])
    elif pattern[0] == '*':
        i = 1
        while i < len(pattern) and pattern[i] == '*':
            i = i + 1
        i = i - 1
        pattern = pattern[i:]
        return match(pattern[1:], string) or match(pattern[1:], string[1:]) or match(pattern, string[1:])
    elif pattern[0].upper() == string[0].upper():
        return match(pattern[1:], string[1:])
    return False


pattern = "h*h*ah*ha*h*h*hha"
string = "hhhhhhhahhaahhahhhhaaahhahhahaaahhahahhhahhhahaaahaah"
if match(pattern, string):
    print("true")
else:
    print("false")

# while True:
#     try:
#         # pattern = input()
#         # string = input()
#         pattern = "p*p*qp**pq*p**p***ppq"
#         string = "pppppppqppqqppqppppqqqppqppqpqqqppqpqpppqpppqpqqqpqqp"
#         if match(pattern, string):
#             print("true")
#         else:
#             print("false")
#     except:
#         break
