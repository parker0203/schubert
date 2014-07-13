#!/usr/bin/python3
# user_input.py

def reverse(text):
  return text[::-1]


def is_palindrome(text):
  return text == reverse(text)


something = input('Enter text: ')
if (is_palindrome(something)):
  print('Palindrome')
else:
  print('not Palindrome')
