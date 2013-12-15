from time import time
from math import sqrt

def gen_primes(n):
    s = set()
    for i in xrange(2, n):
        bad = False
        for j in s:
            if i % j == 0:
                bad = True
                break
        if not bad:
            s.add(i)
    return s
start = time()
primes = sorted(gen_primes(10000))
count = 9
while True:
    bad = False
    for prime in primes:
        if prime <= count:
            if sqrt((count - prime) / 2.0) % 1 == 0:
                bad = True
                break
        else:
            break
    if not bad:
        print 'answer: ', count
        break
        
    count += 2
print 'time: ', time() - start
