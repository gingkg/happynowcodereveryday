import sys

def fun(N, cmd):
    pos = 1
    if N <= 4:
        songs = list(range(1, N + 1))
        for c in cmd:
            if c == "U":
                pos = N if pos == 1 else pos - 1
            if c == "D":
                pos = 1 if pos == N else pos + 1
    else:
        songs = list(range(1, 5))
        for c in cmd:
            if c == "U":
                if pos == 1:
                    pos = N
                    songs = list(range(N-3, N+1))
                elif pos == songs[0]:
                    pos = pos - 1
                    songs = list(range(pos, pos+4))
                else:
                    pos = pos - 1
            if c == "D":
                if pos == N:
                    pos = 1
                    songs = list(range(1, 5))
                elif pos == songs[3]:
                    pos = pos + 1
                    songs = list(range(pos-3, pos+1))
                else:
                    pos = pos + 1
    return songs, pos


i = 1
for line in sys.stdin:
    if i % 2 == 1:
        N = int(line)
    else:
        cmd = line
        songs, pos = fun(N, cmd)
        for k in songs:
            print(k, end=" ")
        print()
        print(pos)
    i = i + 1
