#!/usr/bin/python

def KaratsubaMultiplication(left_hs, right_hs):
    "Karatsuba Multiplication Algorithm"

    left_hs_num_of_digits = len(str(left_hs))
    right_hs_num_of_digits = len(str(right_hs))

    result = 0

    try:
        if (left_hs_num_of_digits > 1 && right_hs_num_of_digits > 1) :
            # Part 1
            B = 10
            m = min(left_hs / right_hs) / 2

            x1 = left_hs / pow(10, m)
            y1 = right_hs / pow(10, m)

            x0 = left_hs % pow(10, m)
            y0 = right_hs % pow(10, m)

            # Part 2
            z2 = KaratsubaMultiplication(x1, y1)
            z0 = KaratsubaMultiplication(x0, y0)

            t0 = x1 + x0
            t1 = y1 + y0
            z1 = KaratsubaMultiplication(t0, t1) - z2 - z0

            result =




    except:
        print "Some Exception"