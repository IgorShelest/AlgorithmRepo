#!/usr/bin/python

# GradeSchool Multiplication Algorithm

# ------------------------------------------------------------------------------

import CommonLibrary

# ------------------------------------------------------------------------------


def grade_school_multiplication(left_hs, right_hs):
    """GradeSchool Multiplication Algorithm"""

    try:
        # Num of digits
        left_hs_digit_number = len(str(left_hs))
        right_hs_digit_number = len(str(right_hs))

        # Lists of digits
        left_hs_digits = CommonLibrary.devideIntoDigits(left_hs)
        right_hs_digits = CommonLibrary.devideIntoDigits(right_hs)

        # Number of digits in first temp result
        first_temp_result_max_digit_number = right_hs_digit_number + 1

        # Number of shifts left
        shift_left_num = left_hs_digit_number - 1

        # Number of digits after shifts left
        shift_left_digit_num = shift_left_num * 2

        # Max number of digits in any temp result
        temp_result_digit_number = first_temp_result_max_digit_number + shift_left_digit_num

        # Initialize temp multiplication results with zeros
        temp_results = []
        for left_iter in range(left_hs_digit_number):
            temp_results.append([])

            for temnp_result_iter in range(temp_result_digit_number):
                temp_results[left_iter].append(0)

        # Calculate temp results
        for left_iter in range(left_hs_digit_number):
            cash = 0
            num_of_digits_to_shift_left = left_iter

            for right_iter in range(right_hs_digit_number):
                multiplication_temp = left_hs_digits[left_iter] * right_hs_digits[right_iter]

                temp_results[left_iter][right_iter + num_of_digits_to_shift_left] = (multiplication_temp + cash) % 10
                cash = multiplication_temp / 10

                # Last multiplication in temp result
                if right_iter == (right_hs_digit_number - 1):
                    temp_results[left_iter][right_iter + num_of_digits_to_shift_left + 1] = cash

        # # DEBUG
        # if __debug__:
        #     print "Temp results:"
        #
        #     for left_iter in range(left_hs_digit_number):
        #
        #         for temnp_result_iter in range(temp_result_digit_number):
        #             print temp_results[left_iter][temnp_result_iter]

        # Sum calculation
        sum_list = []
        cash = 0
        for position_iter in range(temp_result_digit_number):
            temp_sum = 0

            for temp_result_iter in range(left_hs_digit_number):
                temp_sum += temp_results[temp_result_iter][position_iter]

            sum_list.append(temp_sum + cash % 10)
            cash = (temp_sum + cash) / 10

        # # DEBUG
        if __debug__:
            print "Sum:"
            sum_str = ''.join(str(digit) for digit in sum_list)
            print sum_str

        result = int(sum_str)

        return result

    except Exception as ex:
        template = "An exception of type {0} occurred. Arguments:\n{1!r}"
        message = template.format(type(ex).__name__, ex.args)
        print message