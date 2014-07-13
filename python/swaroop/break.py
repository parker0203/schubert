#!/usr/bin/python3
# Filename: break.py

while True:
  s = (input('Enter something(break if quit): '))
  if s == 'quit':
    break
  print('Length of the string is', len(s))

print('done')
