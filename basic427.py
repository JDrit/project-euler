from time import time
import sys

def findL(lst):
    bestLen = 0
    currentLen = 0
    last = lst[0]
    for n in lst:
        if n == last:
            currentLen += 1
            if currentLen > bestLen:
                bestLen = currentLen
        else:
            currentLen = 1
        last = n
    return bestLen

def series(n, depth = -1, lst = []):
    if depth == -1: depth = n
    if depth > 1:
        for a in xrange(1, n + 1):
            tmp = list(lst)
            tmp.append(a)
            for l in series(n, depth - 1, tmp):
                yield l
    else:
        for a in xrange(1, n + 1):
            tmp = list(lst)
            tmp.append(a)
            yield tmp

if __name__ == '__main__':
    if len(sys.argv) < 2:
        f = open("output.txt", "w")
        print 'USAGE: python ', str(sys.argv[0]), ' <n-value> '
        for i in xrange(1, 15):
            dic = dict()
            s = 0
            start = time()
            for l in series(i):
                length = findL(l)
                s += length
                if length in dic:
                    dic[length] = dic[length] + 1
                else:
                    dic[length] = 1
            f.write(str(i) + ", " + str(s) + ", " + str(dic) + ", time: " + str(time() - start) + "\n")
            print i, ', ', s, ', ', dic, time() - start
        f.close()
    else:
        start = time()
        print 'sum: ', sum(findL(l) for l in series(int(sys.argv[1])))
        print sys.argv[1], ' : time: ', time() - start

