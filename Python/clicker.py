import pyautogui as pg
import time
import os


pixel = pg.pixel(140,55)

while (True):   
    chkPixel = pg.pixel(140,55)

    if (pixel != chkPixel):
        os.system('say "your program has finished"')

