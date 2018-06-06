#!/usr/bin/python

import random
import RecursiveMultiplication
import sys

#------------------------------------------------------------------------------

g_range = 1000

#------------------------------------------------------------------------------

def main():

    for index in range(999):
        left = random.randrange(0, g_range)
        right = random.randrange(0, g_range)

        calculated = RecursiveMultiplication.recursiveMultiplication(left, right)
        correct = left * right

        if (calculated != correct):
            print("\n[%i] %i * %i" % (index, left, right))
            print("Calculated %i != Correct %i" % (calculated, correct))

#------------------------------------------------------------------------------


if __name__== "__main__":
    print ("Recursion limit %i" % (sys.getrecursionlimit()))
    sys.setrecursionlimit(2000)
    print ("New Recursion limit %i" % (sys.getrecursionlimit()))

    main()