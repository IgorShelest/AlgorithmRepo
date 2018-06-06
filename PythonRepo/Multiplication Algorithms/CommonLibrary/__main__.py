#!/usr/bin/python

import CommonLibrary
import random

# ------------------------------------------------------------------------------

g_range = 1000


# ------------------------------------------------------------------------------

def main():
    "main"

    ################## Verification of devideIntoDigits ##################
    number = random.randrange(0, g_range)
    list_of_digits = CommonLibrary.devideIntoDigits(number)

    print ("Number: %i" % (number))
    for digit in list_of_digits:
        print digit

# ------------------------------------------------------------------------------

if __name__ == "__main__":
    main()

# ------------------------------------------------------------------------------
