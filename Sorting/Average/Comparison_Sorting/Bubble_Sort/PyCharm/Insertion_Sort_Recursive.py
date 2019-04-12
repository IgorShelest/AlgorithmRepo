"""
    Insertion Sort Recursive
"""


def insertion_sort_recursive_iteration(unsorted_list, array_length):
    """Insertion Sort Single Iteration"""

    if array_length == len(unsorted_list):
        return

    "Perform single Insertion Sort iteration"
    for element_iter in reversed(range(array_length)):

        if unsorted_list[element_iter] < unsorted_list[element_iter + 1]:

            unsorted_list[element_iter], unsorted_list[element_iter + 1] = \
                unsorted_list[element_iter + 1], unsorted_list[element_iter]

    "Perform next Insertion Sort iteration"
    insertion_sort_recursive_iteration(unsorted_list, array_length + 1)


def insertion_sort_recursive(unsorted_list):
    """Insertion Sort Recursive"""

    insertion_sort_recursive_iteration(unsorted_list, 1)
