#!/usr/bin/python

import re

lines = open('newin', 'r').readlines()
cnt = 0
i = 0
while i < len(lines):
    cnt += 1
    n, m = lines[i].split()
    n = int(n)
    m = int(m)
    if n+m == 0: break
    arr = lines[i:i+n+m+1]
    i += n+m+1
    f = open("in"+str(cnt), 'w')
    f.write(''.join(arr))
    f.write('0 0\n')
    f.close()
