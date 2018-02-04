from tkinter import *

root=Tk()
group=LabelFrame(root,text="which is best?",padx=5,pady=5)
group.pack(padx=10,pady=10)
langs=[
    ("python",1),
    ("perl",2),
    ("ruby",3),
    ("lua",4),
    ]
v=IntVar()
v.set=(1)
for lang,num in langs:
    b=Radiobutton(group,text=lang,variable=v,value=num)
    b.pack(anchor=W)

mainloop()
