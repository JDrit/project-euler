pen_set = set()
hex_set = set()
for i in xrange(1, 50000):
    pen_set.add(i * (3 * i - 1) / 2)
    hex_set.add(i * (2 * i - 1))
count = 286
while True:
    result = count * (count + 1) / 2
    if result in pen_set and result in hex_set:
        print result
        break
    count += 1
