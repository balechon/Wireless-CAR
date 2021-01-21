"""
Prints the scan code of all currently pressed keys.
Updates on every keyboard event.
"""
import sys
sys.path.append('..')
import keyboard
import time

def print_pressed_keys(e):
	line =  pressed_keys
	print(line)
	
          
            
keyboard.hook(print_pressed_keys)
keyboard.wait()

time.sleep(0.01)
