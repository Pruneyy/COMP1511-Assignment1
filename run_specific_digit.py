

import sys
import subprocess
import os

digit = int(sys.argv[1])

for i in range(100):
    os.system("./crack_digit digit/" + str(digit) + "_" + str(i) + ".pbm")

