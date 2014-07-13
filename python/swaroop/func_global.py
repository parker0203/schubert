#!/usr/bin/python3
# Filename: func_global.py

x = 50

def func():
  global x

  print('x is', x)
  x = 2
  print('changed global x to', x)


func()
print('now x is', x)
