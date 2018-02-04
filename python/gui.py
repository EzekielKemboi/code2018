import easygui as g
import sys
while 1:
    g.msgbox("welcome")
    msg="make your choice"
    title="games"
    choices=["GTA","far cry5","the evil within2"]
    choice=g.choicebox(msg,title,choices)
    g.msgbox("you choose "+str(choice),"choice")
    msg="choose again?"
    title="ok"
    if g.ccbox(msg,title):
        pass
    else:
        sys.exit(0)
