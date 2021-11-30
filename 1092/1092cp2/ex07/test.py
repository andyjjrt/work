f = open('test.txt','w')
test = "2\n"
for j in range(100):
    for i in range(1,5001):
        test += str(i) + " "
    test +="\n"

f.write(test)