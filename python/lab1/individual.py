ParWidth = input("Введите ширину параллелепипеда:")
ParLength = input("Введите длину параллелепипеда:")
ParHeight = input("Введите высоту параллелепипеда:")

ParWidth = int(ParWidth)
ParLength = int(ParLength)
ParHeight = int(ParHeight)

ParSideSquare = (2*ParHeight*(ParWidth+ParLength))
ParVolume = (ParWidth*ParHeight*ParLength)

print("Площадь боковой поверхности параллелепипеда равна:", ParSideSquare)
print("Объем параллелепипеда равен:", ParVolume)
