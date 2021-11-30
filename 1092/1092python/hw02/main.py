while True:
    try:
        number = input()
        number = int(number)
    except:
        exit()
    status = "YES"
    if(number == 0 or number == 1):
        status = "NO"
    else:
        for i in range(1,number):
            if(i != 1 and i != number):
                if(number % i == 0):
                    status = "NO"
                    break
    print(status)


