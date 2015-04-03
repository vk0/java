from tkinter import *
from tkinter.messagebox import showinfo

def replay():
    showinfo(title='popup', message='Button pressed')

window = Tk()
button = Button(window, text='press', command=replay())
button.pack()
window.mainloop()