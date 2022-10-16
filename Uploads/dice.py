import random
from tkinter import Y
while(True):
    num = random.randint(1,6)
    op = input("Press y to roll: ")    
    if(op!="y"):
        break
    else:
        if(num==1):
            print("|------------|")
            print("|            |")
            print("|     0      |")
            print("|            |")
            print("|------------|")
        
        elif(num==2):
            print("|------------|")
            print("|            |")
            print("|  0      0  |")
            print("|            |")
            print("|------------|")

        elif(num==3):
            print("|------------|")
            print("|     0      |")
            print("|     0      |")
            print("|     0      |")
            print("|------------|")

        elif(num==4):
            print("|------------|")
            print("| 0        0 |")
            print("|            |")
            print("| 0        0 |")
            print("|------------|")

        elif(num==5):
            print("|------------|")
            print("| 0        0 |")
            print("|     0      |")
            print("| 0        0 |")
            print("|------------|")
        
        else:
            print("|------------|")
            print("| 0        0 |")
            print("| 0        0 |")
            print("| 0        0 |")
            print("|------------|")
    