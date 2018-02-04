#一个小游戏
import random

while(1):
    secret=random.randint(1,100)
    temp=input("guess:")
    guess=int(temp)
    while guess!=secret:
        if(guess>secret):
            print("dale")
        else:
            print("xiaole")
        temp=input("again:")
        guess=int(temp)
    print("yes!")
