# -*- coding: utf-8 -*-
import hashlib
f = open("CPPY_hw04_input.txt","r")
line = f.readline()
while line:
    line += "109703040"
    m = hashlib.md5()
    m.update(line.encode("utf-8"))
    h = m.hexdigest()
    print(h)
    line = f.readline()