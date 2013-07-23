#!/usr/bin/python
print sum([i for i in range(2, 400000) if i == sum([pow(int(c), 5) for c in str(i)])])
