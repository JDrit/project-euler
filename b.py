def g(i, a, b, c, d, e, f):
    return  a * i ** b + c * i ** d + e * i ** f

mn = -10
mx = 10
total = 0
for a in xrange(mn, mx):
    for b in xrange(mn, mx):
        for c in xrange(mn, mx):
            for d in xrange(mn, mx):
                for e in xrange(mn, mx):
                    for f in xrange(mn, mx):
                        if (g(5, a, b, c, d, e, f) == 280 and
                                g(6, a, b, c, d, e, f) == 510 and
                                g(7, a, b, c, d, e, f) == 840 and
                                g(8, a, b, c, d, e, f) == 1288 and
                                g(9, a, b, c, d, e, f) == 1872 and
                                g(10, a, b, c, d, e, f) == 2610):
                                print a, b, c, d, e, f
                                total += 1

print total

