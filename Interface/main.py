# -*- coding: utf-8 -*-
 
from Tkinter import * 
import Tix
from CallBack import *
from screen import *


fenetre = Tix.Tk()
callBack=CallBack(fenetre)
fenetre.title("RPcorpo test")
fenetre=mainScreen(fenetre,callBack)
fenetre.mainloop()
