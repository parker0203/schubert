
man = []
other = []

try:
    data = open('sketch.txt')

    for each_line in data:
        try:
            (role, line_spoken) = each_line.split(':', 1)
            line_spoken = line_spoken.strip()
            if role == 'Man':
                man.append(line_spoken)
            elif role == 'Other Man':
                other.append(line_spoken)
        except ValueError:
            pass

    data.close()

except IOError:
    print('The datafile is missing!')

try:
    man_file = open('man_data.txt', 'w')
    other_file = open('other_data.txt', 'w')

    print(man, file = man_file)
    print(other, file = other_file)

except IOError:
    print('File error')

finally:
    man_file.close()
    other_file.close()

"""
below is using with
"""

try:
    with open('man_with.txt', 'w') as man_with, open('other_with.txt', 'w') as other_with:
        print(man, file = man_with)
        print(other, file = other_with)

except IOError as err:
    print('File error: ' + str(err))

