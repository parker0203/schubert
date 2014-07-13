#!/usr/bin/python3
# Filename: func_key.py

def func(a, b = 5, c = 10):
  print(a, b, c)

func(3, 7)
func(25, c = 24)
func(c = 50, a = 100)
func('hello')
