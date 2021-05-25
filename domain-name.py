#!/bin/python3

import math
import os
import random
import re
import sys



#
# Complete the 'getPotentialDomains' function below.
#
# The function is expected to return a STRING.
# The function accepts STRING_ARRAY lines as parameter.
#

def getPotentialDomains(lines):
    # Write your code here
    for _e in lines:
        whut=_e.split(" ")
        httplist = filter(lambda x: re.search('http',x),whut)
        for i in httplist:
            print('-----')
            print(i)
    return 'test'

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    lines_count = int(input().strip())

    lines = []

    for _ in range(lines_count):
        lines_item = input()
        lines.append(lines_item)

    result = getPotentialDomains(lines)

    fptr.write(result + '\n')

    fptr.close()
