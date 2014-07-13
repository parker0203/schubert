#!/usr/bin/python3
# Filename: func_param.py

def printMax(a, b):
  if a > b:
    print(a, 'is max')
  elif a == b:
    print(a, 'is equal to', b)
  else:
    print(b, 'is max')

printMax(3, 4)

x = 5
y = 7

printMax(x, y)

