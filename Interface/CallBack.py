# coding: utf-8
from screen import *

class CallBack:

	def __init__(self, fenetre):
		self.connect=False
		self.fenetre=fenetre
		
	def ledRed(self):
		print "ledRed"
		
	def ledGreen(self):
		print "ledGreen"
		
	def ledOff(self):
		print "ledOff"
		
	def alarmeON(self):
		print "alarmeON"
		
	def alarmeOFF(self):
		print "alarmeOFF"

	def printOnLcd(self, ligne, value):
		print value
		
	def connectSerial(self, name):
		print name
		self.connect=True
		mainScreen(self.fenetre,self)
		
	def deconnectSerial(self):
		self.connect=False
		mainScreen(self.fenetre,self)