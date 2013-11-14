def g(i, a, b, c, d, e, f):
    return  a * i ** b + c * i ** d + e * i ** f

mn = -20
mx = 20
total = 0
for a in xrange(mn, mx):
    for b in xrange(mn, mx):
        for c in xrange(mn, mx):
            for d in xrange(mn, mx):
                for e in xrange(mn, mx):
                    for f in xrange(mn, mx):
                        if (g(5, a, b, c, d, e, f) == 1520 and
                                g(6, a, b, c, d, e, f) == 23400 and
                                g(7, a, b, c, d, e, f) == 423360):
                                print a, b, c, d, e, f
                                total += 1

print total

