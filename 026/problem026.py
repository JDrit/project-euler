def length(dem):
    known = set()
    length = 0
    rem = 1
    while True:
        rem = rem % dem
        if rem in known:
            return length
        else:
            length += 1
            known.add(rem)
            rem *=10
        
best = 0
for i in xrange(1, 1000):
    tmp = length(i)
    if tmp > best:
        best = i
print 'best: ', best
