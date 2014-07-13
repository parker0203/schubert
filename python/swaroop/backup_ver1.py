#!/usr/bin/python3
# Filename: backup_ver2.py

import os
import time

source = ['/home/pk/git/python/swaroop', '/home/pk/sec']
target_dir = '/home/pk/git/python/swaroop'

target = target_dir + os.sep + time.strftime('%Y%m%d%H%M%S') + '.zip'

zip_command = "zip -qr {0} {1}".format(target, ' '.join(source))

if os.system(zip_command) == 0:
  print('Successful back up to', target)
else:
  print('Backup FAILED')
