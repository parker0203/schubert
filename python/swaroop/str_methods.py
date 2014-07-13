#!/usr/bin/python3
# Filename: str_methods.py

name = 'Swaroop'

if name.startswith('Swa'):
  print('Yes, starts with "Swa"')

if 'a' in name:
  print('Yes, "a" in name')

if name.find('war') != 1:
  print('Yes, it contains the string "a"')

delimiter = '_*_'
mylist = ['Brazil', 'Russia', 'India', 'China']
print(delimiter.join(mylist))
