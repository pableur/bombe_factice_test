# -*- coding: utf-8 -*-
 
from Tkinter import * 

def mainScreen(callBack):
	fenetre = Tk()
	fenetre.title("RPcorpo test")
	fenetre.maxsize(500, 300)
	
	p = PanedWindow(fenetre, orient=VERTICAL)
	p.pack(side=TOP, expand=Y, fill=BOTH, pady=2, padx=2)

	frame_led = Frame(fenetre, borderwidth=2, relief=GROOVE)
	frame_alarme = Frame(fenetre, borderwidth=2, relief=GROOVE)
	frame_LCD1 = Frame(fenetre, borderwidth=2, relief=GROOVE)
	frame_LCD2 = Frame(fenetre, borderwidth=2, relief=GROOVE)
		
	led_label = Label(frame_led, text="LED").pack(side=LEFT,padx=10, pady=10)
	led_bouton_red=Button(frame_led, text="RED", command=callBack.ledRed).pack(side=LEFT,padx=10, pady=10)
	led_bouton_green=Button(frame_led, text="GREEN", command=callBack.ledGreen).pack(side=LEFT,padx=10, pady=10)
	led_bouton_off=Button(frame_led, text="OFF", command=callBack.ledOff).pack(side=LEFT,padx=10, pady=10)

	Label(frame_alarme, text="ALARME").pack(side=LEFT,padx=10, pady=10)
	Button(frame_alarme, text="ON", command=callBack.alarmeON).pack(side=LEFT,padx=10, pady=10)
	Button(frame_alarme, text="OFF", command=callBack.alarmeOFF).pack(side=LEFT,padx=10, pady=10)
	
	valueLigne1 = StringVar() 
	valueLigne1.set("txt LCD L1")
	entreeLigne1 = Entry(frame_LCD1, textvariable= valueLigne1 , width=30)
	entreeLigne1.pack(side=LEFT)
	Button(frame_LCD1, text="Print on LCD L1", command=lambda: callBack.printOnLcd(0,entreeLigne1.get())).pack(side=RIGHT,padx=10, pady=10)
	
	valueLigne2 = StringVar() 
	valueLigne2.set("txt LCD L2")
	entreeLigne2 = Entry(frame_LCD2, textvariable= valueLigne2 , width=30)
	entreeLigne2.pack(side=LEFT)
	Button(frame_LCD2, text="Print on LCD L2", command=lambda: callBack.printOnLcd(0,entreeLigne2.get())).pack(side=RIGHT,padx=10, pady=10)
	 
	Button(fenetre, text="Fermer", command=fenetre.quit).pack(side=LEFT,padx=10, pady=10)

	p.add(frame_led)
	p.add(frame_alarme)
	p.add(frame_LCD1)
	p.add(frame_LCD2)
	
	p.pack()

	return fenetre