from tkinter import *

root=Tk()
photo=PhotoImage(file="picture2.png")
thelabel=Label(root,
               text="GUIGUIGUI",
               image=photo,
               justify=LEFT,
               compound=CENTER,
               font=("微软雅黑",20),
               fg="white"
               )
thelabel.pack()
mainloop()
