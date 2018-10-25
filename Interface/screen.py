# -*- coding: utf-8 -*-
 
from Tkinter import * 
import Tix

def mainScreen(fenetre, callBack):

	#fenetre.maxsize(500, 300)
	
	list = fenetre.pack_slaves()
	for l in list:
		l.destroy()
	
	p = PanedWindow(fenetre, orient=VERTICAL)
	p.pack(side=TOP, expand=Y, fill=BOTH, pady=2, padx=2)

	frame_serial = Frame(fenetre, borderwidth=2, relief=GROOVE)
	frame_led = Frame(fenetre, borderwidth=2, relief=GROOVE)
	frame_alarme = Frame(fenetre, borderwidth=2, relief=GROOVE)
	frame_LCD1 = Frame(fenetre, borderwidth=2, relief=GROOVE)
	frame_LCD2 = Frame(fenetre, borderwidth=2, relief=GROOVE)
	frame_singleAction = Frame(fenetre, borderwidth=2, relief=GROOVE)
	frame_input = Frame(fenetre, borderwidth=2, relief=GROOVE)
	
	if callBack.connect==False:
		Label(frame_serial, text="port COM :").pack(side=LEFT,padx=10, pady=10)
		varcombo = Tix.StringVar() 
		listbox = Tix.ComboBox(frame_serial, variable=varcombo)
		allPort=callBack.getAllSerial()		
		for ser in allPort:
			listbox.insert(END, str(ser.device))
		if len(allPort)>0:
			varcombo.set(allPort[0].device)
		listbox.pack(side=LEFT)
		Button(frame_serial, text="CONNECT", command=lambda: callBack.connectSerial(varcombo.get())).pack(side=RIGHT,padx=10, pady=10)
	else:
		Button(frame_serial, text="DECONNECT", command=lambda: callBack.deconnectSerial()).pack(side=RIGHT,padx=10, pady=10)
	p.add(frame_serial)
		
	if callBack.connect:
		led_label = Label(frame_led, text="LED").pack(side=LEFT,padx=10, pady=10)
		led_bouton_red=Button(frame_led, text="RED", command=callBack.ledRed).pack(side=LEFT,padx=10, pady=10)
		led_bouton_green=Button(frame_led, text="GREEN", command=callBack.ledGreen).pack(side=LEFT,padx=10, pady=10)
		led_bouton_off=Button(frame_led, text="OFF", command=callBack.ledOff).pack(side=LEFT,padx=10, pady=10)

		Label(frame_alarme, text="ALARME").pack(side=LEFT,padx=10, pady=10)
		Button(frame_alarme, text="ON", command=callBack.alarmeON).pack(side=LEFT,padx=10, pady=10)
		Button(frame_alarme, text="OFF", command=callBack.alarmeOFF).pack(side=LEFT,padx=10, pady=10)
		
		valueLigne1 = StringVar() 
		valueLigne1.set("txt_LCD_L1")
		entreeLigne1 = Entry(frame_LCD1, textvariable= valueLigne1 , width=30)
		entreeLigne1.pack(side=LEFT)
		Button(frame_LCD1, text="Print on LCD L1", command=lambda: callBack.printOnLcd(1,entreeLigne1.get())).pack(side=RIGHT,padx=10, pady=10)
		
		valueLigne2 = StringVar() 
		valueLigne2.set("txt_LCD_L2")
		entreeLigne2 = Entry(frame_LCD2, textvariable= valueLigne2 , width=30)
		entreeLigne2.pack(side=LEFT)
		Button(frame_LCD2, text="Print on LCD L2", command=lambda: callBack.printOnLcd(2,entreeLigne2.get())).pack(side=RIGHT,padx=10, pady=10)
		
		Button(frame_singleAction, text="BIP", command=callBack.bip).pack(side=LEFT,padx=10, pady=10)
		Button(frame_singleAction, text="BOUM", command=callBack.boum).pack(side=LEFT,padx=10, pady=10)
		
		Label(frame_input, text="Keyboard :").pack(side=LEFT,padx=10, pady=10)
		valueKeyboard = StringVar()
		valueKeyboard.set('')
		callBack.keyboardScreen=valueKeyboard
		Entry(frame_input, textvariable=valueKeyboard, width=10).pack(side=LEFT,padx=10, pady=10)
		
		Label(frame_input, text="Button :").pack(side=LEFT,padx=10, pady=10)
		valueButton = StringVar()
		valueButton.set('')
		callBack.buttonScreen=valueButton
		Entry(frame_input, textvariable=valueButton, width=10).pack(side=LEFT,padx=10, pady=10)
		
		Label(frame_input, text="Capteur :").pack(side=LEFT,padx=10, pady=10)
		secousseValue = DoubleVar()
		callBack.secousseScreen=secousseValue
		scale = Scale(frame_input, variable=secousseValue)
		scale.pack(side=LEFT,padx=10, pady=10)
		
		Button(fenetre, text="Fermer", command=callBack.fermer).pack(side=LEFT,padx=10, pady=10)

		p.add(frame_led)
		p.add(frame_alarme)
		p.add(frame_LCD1)
		p.add(frame_LCD2)
		p.add(frame_singleAction)
		p.add(frame_input)
	
	p.pack()

	return fenetre