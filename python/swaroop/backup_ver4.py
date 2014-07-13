#!/usr/bin/python3
# Filename: backup_ver4.py

import os
import time

source = ['/home/pk/git/python/swaroop', '/home/pk/sec']
target_dir = '/home/pk/git/python/swaroop'

today = target_dir + os.sep + time.strftime('%Y%m%d')
now = time.strftime('%H%M%s')

comment = input('Enter a comment:')
if len(comment) == 0:
  target = today + os.sep + now + '.zip'
else:
  target = today + os.sep + now + '_' + \
           comment.replace(' ', '_') + '.zip'
  
if not os.path.exists(today):
  os.mkdir(today)
  print('Successfully created directory', today)

zip_command = "zip -qr {0} {1}".format(target, ' '.join(source))

if os.system(zip_command) == 0:
  print('Successful back up to', target)
else:
  print('Backup FAILED')
