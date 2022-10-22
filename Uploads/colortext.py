#program to print word in different colours

import sys
from termcolor import cprint,colored
def colortxt():

        string=input("enter a <=7 character word to be printed in different colours.")
        cprint(string,"green",attrs=["bold","underline"])
        s=list(string)
        c=["blue","magenta","green","yellow","red","cyan","grey","white"]
        for i in range(len(s)):
                cprint(s[i],c[i],attrs=["bold","underline"],end="")
        return
colortxt()        