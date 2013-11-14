
mn = -20
mx = 20
n = 7
m = 6
for a in xrange(mn, mx):
    for b in xrange(mn, mx):
        for c in xrange(mn, mx):
            for d in xrange(mn, mx):
                for e in xrange(mn, mx):
                    try:
                        if (a * n * (n - b) ** (n - c) + d * n ** e == 423360):
                            print a, b, c
                    except:
                        pass
