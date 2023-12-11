#!/usr/bin/env python3

import pyperclip
import keyboard


    
while a:
    p = pyperclip.paste()
    f = open('buffer.txt', 'a', encoding='utf-8')
    f.write("%s\n" %(p))
    f.close()
    return again()

