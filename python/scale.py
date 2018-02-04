from tkinter import *

root=Tk()
s1=Scale(root,from_=300,to=0,tickinterval=20,length=500,orient=VERTICAL)
s1.pack(anchor=W)
s2=Scale(root,from_=0,to=300,orient=HORIZONTAL,tickinterval=20,length=1000)
s2.pack()

def show():
    print(s2.get(),s1.get())

Button(root,text="获得位置",command=show).pack()

mainloop()
