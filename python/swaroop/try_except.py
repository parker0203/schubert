#!/usr/bin/python3
# try_except.py

try:
  text = input('Enter something: ')

except EOFError:
  print('EOFError')
except KeyboardInterrupt:
  print('KeyboardInterrupt')
else:
  print(text)
  
