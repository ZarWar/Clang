#!/usr/bin/env python3.8
import keyboard, pyperclip, time

count = 0	# Счётчик для ctrl_v
count2 = 0	# Счётчик для ctrl_c
buff = ''	# переменная для значения буфера, до очистки.

def after2():
	'''
	call_later запускат отдельным потоком указанную функцию.
	зачем - быстро отрабатывает, уловит двойное нажатие отлавливаемого сочетания клавиш.
	'''
	keyboard.call_later(ctrl_c_pressed_action)

def ctrl_c_pressed_action():
	'''
	копирует буфер обмена в переменную buff (кроме пустых буферов)
	Если counter достигает 2х (вызван ctrl+с 2раза за 0.3 сек) - она также
	копирует буфер в buff переменную, но и очищает сам буффер после этого.
	'''
	global buff
	global count2
	count2 += 1
	time.sleep(0.3)
	x = pyperclip.paste()
	if count2 >= 2:
		count2 = 0
		buff = x
		pyperclip.copy('')
	if count2 == 1:
		buff = x
	if count2 == 0:
		pass
	count2 = 0

def after():
	'''
	call_later запускат отдельным потоком указанную функцию.
	зачем - быстро отрабатывает, уловит двойное нажатие отлавливаемого сочетания клавиш.
	'''
	keyboard.call_later(crtl_v_pressed_action)

def crtl_v_pressed_action():
	'''
	прибавляет счётчик на +1, когда вызвана, и если счётчик достигает 2 (за 0.3сек
	если была вызвана дважды), то она сама делает вставку ctrl+v со 
	значением последнего Непустого буфера обмена.
	После - очищает буффер и -1 к счётчику.
	'''
	global count
	global buff
	count += 1
	y = pyperclip.paste()
	if count >= 2 and len(y) < 1:
		pyperclip.copy(buff)
		keyboard.send('ctrl+v')
		pyperclip.copy('')
	time.sleep(0.3)
	count -= 1

keyboard.add_hotkey('ctrl+c', after2)
keyboard.add_hotkey('ctrl+v', after)

keyboard.wait('Esc+1')	# Stop service shortcut.