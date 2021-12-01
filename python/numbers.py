FirstNum = input("Введите первое число:")
SecondNum = input("Введите второе число:")
ThirdNum = input("Введите третье число:")
FourthNum = input("Введите четвертое число:")

FirstDoubleSum = float(FirstNum + SecondNum)
SecondDoubleSum = float(ThirdNum + FourthNum)
Div = float(FirstDoubleSum / SecondDoubleSum)

print("Ответ: %.2f" % Div)
