from tkinter import *
from tkinter import messagebox
from PIL import Image, ImageTk
import mysql.connector
import os

z=mysql.connector.connect(
    host='localhost',
    user='root',
    passwd='xxxxxxxxx', #your mysql password
    )
a=z.cursor()
a.execute("use passmanager")
#print("table used")
#---------------------------------------------------------------------------------------------------------------------------
root=Tk()
root.title('Login')
root.geometry('925x500+300+200')
root.configure(bg="#fff")
root.resizable(False,False)
def new_acc():
    root.destroy()
    os.system('python signup.py')
    #import signup.py
def signin():
    username=user.get()
    password=code.get()
    try:
        a.execute("SELECT * FROM users WHERE USERNAME='%s' "%(username))
    except:
        messagebox.showerror("Invalid","User doesn't exist")
        user.delete(0, 'end')
        code.delete(0, 'end')
    re=a.fetchall()
    #print(re)
    try:
        if username==re[0][1] and password==re[0][2]:
                user.delete(0, 'end')
                code.delete(0, 'end')
                '''screen=Toplevel(root)
                screen.title("App")
                screen.geometry('925x500+300+200')
                screen.config(bg="white")
                Label(screen,text='Login successfull',bg='#fff',font=('Calibri(body)',50,'bold')).pack(expand=True)
                screen.mainloop()'''
                root.destroy()
                os.system('python home.py')
        elif username!=re[0][1] and password!=re[0][2]:  
            messagebox.showerror("Invalid","invalid username and password")
               
        elif password!=re[0][2]:
            messagebox.showerror("Invalid","invalid password")

        elif username!=re[0][1]:
            messagebox.showerror("Invalid","invalid username")
    except:
            messagebox.showerror("Invalid","invalid username and password")
            

img =ImageTk.PhotoImage(file='password.png')
Label(root,image=img,bg='white',width=500,height=500).place(x=0,y=0)

frame=Frame(root,width=380,height=350,bg="white")
frame.place(x=500,y=80)
heading=Label(frame,text='PASSWORD MANAGER',fg='#57a1f8',bg='white',font=('Microsoft YaHei UI Light',23,'bold'))
heading.place(x=20,y=5)

#############-----------------------------

def on_enter(e):
    user.delete(0, 'end')

def on_leave(e):
    name=user.get()
    if name=='':
        user.insert(0,'username')
        
user = Entry(frame,width=25,fg='black',border=0,bg="white",font=('microsoft YaHei UI Light',11))
user.place(x=30,y=80)
user.insert(0,'username')
user.bind('<FocusIn>',on_enter)
user.bind('<FocusOut>',on_leave)

Frame(frame,width=295,height=2,bg='black').place(x=25,y=107)

##########-------------------------------
def on_enter(e):
    code.delete(0, 'end')

def on_leave(e):
    name=code.get()
    if name=='':
        code.insert(0,'password')

        
code = Entry(frame,width=25,fg='black',border=0,bg="white",font=('microsoft YaHei UI Light',11),show="*")
code.place(x=30,y=150)
code.insert(0,'Password')
code.bind('<FocusIn>',on_enter)
code.bind('<FocusOut>',on_leave)

Frame(frame,width=295,height=2,bg='black').place(x=25,y=177)

################################

Button(frame,width=39,pady=7,text='Sign in',bg='#57a1f8',fg='white',border=0,command=signin).place(x=35,y=204)
label=Label(frame,text="Don't have an account ? ",fg='black',bg='white',font=('Microsft YaHei UI Light',9))
label.place(x=35,y=270)

signup= Button(frame,width=14,text='Create Account',border=0,bg='white',cursor='hand2',fg='#57a1f8',command=new_acc)
signup.place(x=170,y=270)

root.mainloop()
