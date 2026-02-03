import time
import os

def clear_screen():
    os.system('cls' if os.name == 'nt' else 'clear')

def pause_for_1_seconds():
    time.sleep(1)