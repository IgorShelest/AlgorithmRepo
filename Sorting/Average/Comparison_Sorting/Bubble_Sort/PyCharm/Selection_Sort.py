"""
    Selection Sort
"""


def selection_sort(unsorted_list):
    """Selection Sort"""

    for loop_iter in range(len(unsorted_list) - 1):
        current_max = unsorted_list[loop_iter]

        for element_iter in range(loop_iter + 1, len(unsorted_list)):
            if unsorted_list[element_iter] < current_max:
                unsorted_list[element_iter], current_max = current_max, unsorted_list[element_iter]

        unsorted_list[loop_iter] = current_max

