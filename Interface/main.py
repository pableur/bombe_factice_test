# -*- coding: utf-8 -*-
 
from Tkinter import * 
import Tix
from CallBack import *
from screen import *

def update_clock():
    callBack.readSerial();
    fenetre.after(100, update_clock) # run this function again in 1,000 milliseconds


fenetre = Tix.Tk()
callBack=CallBack(fenetre)
fenetre.title("RPcorpo test")
fenetre=mainScreen(fenetre,callBack)
update_clock()
fenetre.mainloop()
