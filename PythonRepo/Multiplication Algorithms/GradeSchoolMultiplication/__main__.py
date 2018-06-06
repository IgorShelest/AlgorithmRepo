#!/usr/bin/python

import random
import GradeSchoolMultiplication
import sys

#------------------------------------------------------------------------------

g_range = 1000

#------------------------------------------------------------------------------

def main():
    for index in range(999):
        left = random.randrange(0, g_range)
        right = random.randrange(0, g_range)

        calculated = GradeSchoolMultiplication.grade_school_multiplication(left, right)
        correct = left * right

        if calculated != correct:
            print("\n[%i] %i * %i" % (index, left, right))
            print("Calculated %i != Correct %i" % (calculated, correct))

    GradeSchoolMultiplication.grade_school_multiplication(123, 456)

#------------------------------------------------------------------------------


if __name__== "__main__":
    main()