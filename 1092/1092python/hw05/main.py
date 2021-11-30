def check_once():
    length = int(input())
    matrix = []
    row = []
    column = [0 for i in range(length)] 
    for b in range(length):
        line = input().split()
        row.append(0)
        for c in range(length):
            line[c] = int(line[c])
            row[b] += line[c]
            column[c] += line[c]
        matrix.append(line)
    #print(row)
    #print(column)
    #print("")
    test_row = 0
    where_row = -1
    test_column = 0
    where_column = -1
    for i in range(len(row)):
        if row[i] % 2 != 0:
            test_row += 1
            where_row = i+1
    for i in range(len(column)):
        if column[i] % 2 != 0:
            test_column += 1
            where_column = i+1
    if test_column == 0 and test_row == 0:
        print("OK")
    elif test_column == 1 and test_row == 1:
        print("Change bit (" + str(where_row) + "," + str(where_column) + ")")
    else:
        print("Corrupt")

if __name__ == '__main__':
    i = int(input())
    for a in range(i):
        check_once()
    
