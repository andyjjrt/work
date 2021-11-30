while True:
    try:
        height, weight = input().split()
        height = float(float(height)/100)
        weight = float(weight)
        BMI = float(weight / (height * height))
        if(BMI <= 18.5):
            print("underweight")
        elif(BMI > 18.5 and BMI <= 25):
            print("normal weight")
        elif(BMI > 25 and BMI <= 30):
            print("overweight")
        else:
            print("obese")
    except:
        exit()
