#!/usr/bin/python3

"""
 Script: factorization.py
 Description: This script reads integers from a file, performs factorization on each integer,
 and prints the results in the format "number = result * factor".
 It assumes the input file "test00" contains one integer per line.
"""

import math
from sys import argv
import time


"""
 Function: factor
 Description: Factors a given number 'num'.
 Parameters:
   - num (int): The integer to be factored.
 Returns:
   - int: The smallest divisor of 'num'.
"""

def factor(num):
    div = 2
    while div != num:
        if num % div == 0:
            return div
        else:
            div += 1

with open(argv[1], 'r') as file:
    start_time = time.time()
    for line in file:
        number = int(line.strip())

        fac = factor(number)
        result = number // fac

        print("{:d}={:d}*{:d}".format(number, result, fac))
    elapsed_time = time.time() - start_time
    print(f"{argv[0]} took {elapsed_time} seconds to run.")
