#!/usr/bin/python

# Common Library

# ------------------------------------------------------------------------------

def devideIntoDigits(number):
    "devideIntoDigits"

    list_of_digits = []
    number_str = str(number)

    for index in range(len(number_str)):
        list_of_digits.append(int(number_str[index]))

    return list_of_digits

# ------------------------------------------------------------------------------