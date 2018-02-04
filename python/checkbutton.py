from tkinter import *

root=Tk()
subjects=["math","physics","chemistry","programming"]
v=[]
for each in subjects:
    v.append(IntVar())
    b=Checkbutton(root,text=each,variable=v)
    b.pack(anchor=W)
l=Label(root,textvariable=v)
l.pack()

mainloop()
