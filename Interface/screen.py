# -*- coding: utf-8 -*-
 
from Tkinter import * 

def mainScreen():
	fenetre = Tk()

	label = Label(fenetre, text="Hello World")
	label.pack()
	return fenetre