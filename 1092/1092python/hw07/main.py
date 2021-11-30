table = dict()

while(1):
    try:
        command = input().split(' ')
        if command[0] == 'i':
            table[command[1]] = int(command[2])
        elif command[0] == 'd':
            try:
                del table[command[1]]
            except:
                print(command[1] + ' does not exist!')
        elif command[0] == 'q':
            try:
                print(table[command[1]])
            except:
                print(command[1] + ' does not exist!')
        elif command[0] == 'p':
            for member in sorted(table.items()) :
                print(str(member[0]) + ' ' + str(member[1]))
    except:
        exit()