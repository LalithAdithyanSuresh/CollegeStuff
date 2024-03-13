import pyautogui
import pyperclip
import time

from sympy import Rem
# Get the screen resolution
screen_width, screen_height = pyautogui.size()
print(f"Screen resolution: {screen_width}x{screen_height}")
pyautogui.hotkey('win', '3')

def LastChat():
    pyautogui.hotkey('win', 'shift','T')
    time.sleep(0.5)
    pyautogui.moveTo(2200,1200)
    time.sleep(0.1)
    pyautogui.leftClick()
    time.sleep(0.1)
    pyautogui.moveTo(165,230)
    time.sleep(0.7)
    pyautogui.mouseDown()
    time.sleep(0.1)
    pyautogui.moveTo(330,260)
    time.sleep(0.1)
    pyautogui.mouseUp()
    time.sleep(0.1)
    return pyperclip.paste()

def Remove(r = False):
    pyautogui.moveTo(830,80)
    pyautogui.click()
    time.sleep(0.3)
    pyautogui.moveTo(790,140)
    pyautogui.click()
    time.sleep(0.3)
    pyautogui.moveTo(1050,170)
    pyautogui.click()
    time.sleep(0.3)
    pyautogui.typewrite(pyperclip.paste())
    time.sleep(0.2)
    pyautogui.typewrite(' ')
    time.sleep(0.2)
    pyautogui.moveTo(1100,380)
    time.sleep(0.2)
    pyautogui.rightClick()
    time.sleep(0.3)
    pyautogui.moveTo(1160,450)
    time.sleep(0.5)
    pyautogui.click()
    time.sleep(0.1)
    pyautogui.click()
    time.sleep(1)
    pyautogui.moveTo(1400,820)
    if(r):
        pyautogui.moveTo(1150,820)
    time.sleep(1)
    pyautogui.click()
    time.sleep(3)



    pyautogui.moveTo(830,80)
    pyautogui.click()
    time.sleep(0.1)
    pyautogui.moveTo(790,140)
    pyautogui.click()
    time.sleep(0.1)
    pyautogui.moveTo(990,250)
    pyautogui.click()
    time.sleep(0.3)
    pyautogui.typewrite(pyperclip.paste())
    time.sleep(0.4)
    pyautogui.moveTo(1320,300)
    pyautogui.click()
    time.sleep(0.4)
    pyautogui.moveTo(1120,240)
    pyautogui.click()
    time.sleep(0.4)
    pyautogui.moveTo(1150,835)
    pyautogui.click()

while True:
    LastChat()
    time.sleep(0.5)
    if(pyperclip.paste()=='Selva Akash SNU'):
        Remove(r=True)
    time.sleep(5)


