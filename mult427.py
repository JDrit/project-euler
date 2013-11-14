from time import time
import multiprocessing
import sys
from basic427 import series, findL

def task(n):
    dic = dict()
    s = 0
    start = time()
    for lst in series(n):
        length = findL(lst)
        s += length
        if length in dic:
            dic[length] = dic[length] + 1
        else:
            dic[length] = 1
    f = open("output.txt", "a")
    f.write(str(n) + ", " + str(s) + ", " + str(dic) + ", time: " + str(time() - start) + "\n")
    f.close()
    print str(n) + ", " + str(s) + ", " + str(dic) + ", time: " + str(time() - start)
    return

if __name__ == '__main__':
    num = multiprocessing.cpu_count() * 2
    pool = multiprocessing.Pool(processes = num)

    inputs = [i for i in xrange(1, int(sys.argv[1]))]

    res = pool.map_async(task, inputs)

    for r in res.get():
        pass
