from itertools import permutations
primes = [2,3,5,7,11,13,17]

def divisible(n):
    for i in range(len(primes)):
        if int(n[1 + i:4 + i])%primes[i] != 0:
            return False
    return True

print sum(map(int, filter(divisible, map(''.join, permutations("1234568790")))))
