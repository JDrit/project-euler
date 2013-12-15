import time

def isPanigital(i, j):
    lst = [0] * 10

    for c in str(i):
        if lst[int(c)] == 1:
            return False
        lst[int(c)] = 1
    for c in str(j):
        if lst[int(c)] == 1:
            return False
        lst[int(c)] = 1

    for c in str(i * j):
        if lst[int(c)] == 1:
            return False
        lst[int(c)] = 1

    for index in range(1, 10):
        if lst[index] == 0:
                return False
    return True

s = set()
start_time = time.time()
for i in range(2, 100):
    if i > 9:
        start = 123
    else:
        start = 1234
    for j in range(start, 10000 / i + 1):
        if isPanigital(i, j):
            s.add(i * j)
print 'answer', sum(s)
print time.time() - start_time, "seconds"
