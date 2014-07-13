#!/usr/bin/python3
# Filename: total.py

def total(initial = 5, *numbers, **keywords):
  count = initial
  for number in numbers:
    count += number

  print(count)

  for key in keywords:
    count += keywords[key]

  return count

print(total(10, 1, 2, 3, vegetables = 50, fruits = 100))
