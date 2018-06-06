#!/usr/bin/python

# Recursive Multiplication Algorithm

def recursiveMultiplication(left_hs, right_hs):
    "Recursive Multiplication Algorithm"

    result = 0

    try:
        if(left_hs < 0):
            return -recursiveMultiplication(-left_hs, right_hs)

        if (right_hs < 0):
            return -recursiveMultiplication(left_hs, -right_hs)

        if(left_hs == 0 or right_hs == 0):
            return 0

        left_hs -= 1
        result = right_hs + recursiveMultiplication(left_hs, right_hs)

    except Exception as ex:
        template = "An exception of type {0} occurred. Arguments:\n{1!r}"
        message = template.format(type(ex).__name__, ex.args)
        print message

    return result


