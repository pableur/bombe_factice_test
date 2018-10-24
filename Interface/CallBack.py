# coding: utf-8

class CallBack:

	def __init__(self):
		pass
		
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