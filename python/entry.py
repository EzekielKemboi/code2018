from tkinter import *

root=Tk()
Label(root,text="账号：").grid(row=0)
Label(root,text="密码：").grid(row=1)
e1=Entry(root)
e2=Entry(root,show="*")
e1.grid(row=0,column=1,padx=10,pady=5)
e2.grid(row=1,column=1,padx=10,pady=5)

def show():
    print("账号：%s"%e1.get())
    print("密码：%s"%e2.get())
    e1.delete(0,END)
    e2.delete(0,END)

Button(root,text="获取信息",width=10,command=show)\
                                                .grid(row=2,column=0,sticky=W,padx=10,pady=5)
Button(root,text="退出",width=10,command=root.quit)\
                                                .grid(row=2,column=1,sticky=E,padx=10,pady=5)

mainloop()
