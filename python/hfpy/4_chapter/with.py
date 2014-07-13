
try:
    with open('with.txt', 'w') as data:
        print('it is using with', file = data)

except IOError as err:
    print('File error: ' + str(err))
