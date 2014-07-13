#!/usr/bin/python3
# Filename: func_doc.py

def printMax(x, y):
  '''Prints the maximum of two numbers.
  The two values must be intergers.'''
  x = int(x) # convert to intergers, if possible
  y = int(y)

  if x > y:
    print(x, 'is max')
  else:
    print(y, 'is max')


printMax(3, 5)
print(printMax.__doc__)

    
