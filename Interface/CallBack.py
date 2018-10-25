# coding: utf-8
from screen import *
import serial
import serial.tools.list_ports

class CallBack:

	def __init__(self, fenetre):
		self.connect=False
		self.fenetre=fenetre
		self.ser=None
		self.serialInput=""
		self.keyboardScreen=None
		self.buttonScreen=None
		self.secousseScreen=None
		
		
	def ledRed(self):		
		if self.ser.is_open:
			self.ser.write('led red\n')

	def ledGreen(self):
		if self.ser.is_open:
			self.ser.write('led green\n')

	def ledOff(self):
		if self.ser.is_open:
			self.ser.write('led off\n')

	def alarmeON(self):
		if self.ser.is_open:
			self.ser.write('alarme on\n')

	def alarmeOFF(self):
		if self.ser.is_open:
			self.ser.write('alarme off\n')

	def printOnLcd(self, ligne, value):
		if self.ser.is_open:
			self.ser.write('LCD '+str(ligne)+' '+str(value)+'\n')
			
	def bip(self,):
		if self.ser.is_open:
			self.ser.write('bip\n')
			
	def boum(self,):
		if self.ser.is_open:
			self.ser.write('boum\n')

	def connectSerial(self, name):
		self.ser = serial.Serial(name)
		self.ser.baudrate = 250000
		self.ser.timeout=0.01
		self.connect=True
		mainScreen(self.fenetre,self)

	def deconnectSerial(self):
		self.ser.close()
		self.connect=False
		mainScreen(self.fenetre,self)

	def getAllSerial(self):
		return serial.tools.list_ports.comports(include_links=False)
		
	def readSerial(self):
		if self.ser!= None:
			if self.ser.is_open:
				tmp = self.ser.readline()
				if tmp != "":
					self.serialInput=self.serialInput+tmp
				if self.serialInput.find('\n')!=-1 or self.serialInput.find('\r')!=-1:
					index = self.serialInput.find('\n')
					if index>self.serialInput.find('\r') and self.serialInput.find('\r')>0:
						index=self.serialInput.find('\r')
					if index==0:
						index=self.serialInput.find('\r')
					cmd=self.serialInput[0:index]
					self.serialInput=self.serialInput[index+2:]
	
					#print "cmd "+cmd
					#print "serialInput "+self.serialInput
					
					if len(cmd)==1:
						self.keyboardScreen.set(cmd)
						#valueKeyboard.set(callBack.keyboard)
						#mainScreen(self.fenetre,self)
					else:
						tokens=cmd.split(' ')
						
						if tokens[0]=="bouton":
							if tokens[1]=="appuis":
								self.buttonScreen.set("ON")
							elif tokens[1]=="relache":
								self.buttonScreen.set("OFF")
							else:
								self.buttonScreen.set("###")
						elif tokens[0]=="secousse":
							if tokens[1]=="appuis":
								self.secousseScreen.set(100)
							elif tokens[1]=="relache":
								self.secousseScreen.set(0)
							else:
								self.secousseScreen.set(0)
						

	def fermer(self):
		if self.ser.is_open:
			self.ser.close()
		self.fenetre.quit()
