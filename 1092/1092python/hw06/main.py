if __name__ == '__main__':
    allStr = input().split(',')
    allStr.sort()
    # allStr is a list containing all the input vocabulary words
    while True:
        try:
            target = input()
            first = target[0]
            counter = 0
            found = False
            found2 = False
            try:
                a = allStr.index(target)
            except:
                print("NOT FOUND")
                continue
            for ele in allStr:
                if ele[0] == first:
                    found2 = True
                    counter += 1
                    if ele == target:
                        print(first.upper() + " " + str(counter))
                        break
                elif found2 == True:
                    break
        except:
            exit()