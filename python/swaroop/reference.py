#!/usr/bin/python3
# Filename: reference.py

print('Simple Assignment')
shoplist = ['apple', 'mango', 'carrot', 'banana']
mylist = shoplist  # mylist is just antoher name pointing to the same object!
del shoplist[0]

print('shoplist is', shoplist)
print('mylist is', mylist)

print('Copy by making a full slice')
mylist = shoplist[:] # make a copy by doing a full slice
del mylist[0]

print('shoplist is', shoplist)
print('mylist is', mylist)

