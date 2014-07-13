#!/usr/bin/python3
# Filename: class_init.py

class Person:
  def __init__(self, name):
    self.name = name
  def sayHi(self):
    print('Hello, my name is', self.name)

p = Person('parker0203')
print(p.sayHi())
