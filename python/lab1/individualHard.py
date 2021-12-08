Hour = input("Введите час:")
Minute = input("Введите минуту:")
Second = input("Введите секунды")

Hour = int(Hour)
Minute = int(Minute)
Second = int(Second)

Hour %=12
Minute %=60
Second %=60
Result = float(30*Hour + 0.5*Minute + 30.0/3600*Second)

print("Угол равен: ", Result, " градусов")
