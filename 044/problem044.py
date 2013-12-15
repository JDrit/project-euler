lst = [n * (3 * n - 1) / 2 for n in xrange(1, 10000)]
st = set(lst)
mn = 10000000

for i in xrange(len(lst)):
    for j in xrange(i, len(lst)):
        
        if (lst[i] + lst[j] in st and
            lst[j] - lst[i] in st and
            abs(lst[j] - lst[i]) < mn):
            mn = abs(lst[j] - lst[i])

print 'min: ', mn
