import math

print sum([i for i in range(3, 200000) if sum([math.factorial(int(c)) for c in str(i)]) == i])

