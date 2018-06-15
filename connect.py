import serial
import pygame

def sound(p):
	pygame.mixer.init()
	pygame.mixer.music.load(p)
	pygame.mixer.music.play()
	while pygame.mixer.music.get_busy() == True:
		continue
	pygame.mixer.music.stop()
	pygame.mixer.stop()



ser = serial.Serial('COM15', 9600 , timeout=.1)
#ser = serial.Serial('COM15', 9600, parity=serial.PARITY_EVEN, rtscts = 1)
while 1:
	x = input("Enter a number: ")
	s = ser.read(100)
	print(s) 
	#while (s != "1"):
	#	s = ser.readline()
	if (x == 1):
		ser.write('1')
		sound("Aloo.mp3")
	if (x == 2):
		ser.write('2')
		sound("Song_1.wav")
	if (x == 3):
		ser.write('3')
		print(ser.readline)
		rot = ser.read()
		ser.write(rot)
		

ser.close()