"""
    Bubble Sort Recursive
"""


def bubble_sort_recursive_iteration(unsorted_array, array_length):
    """Bubble Sort Single Iteration"""

    "End case"
    if array_length == 1:
        return

    "Perform single Bubble Sort iteration"
    for element_iter in range(array_length - 1):
        if unsorted_array[element_iter] > unsorted_array[element_iter + 1]:
            unsorted_array[element_iter], unsorted_array[element_iter + 1] = \
                unsorted_array[element_iter + 1], unsorted_array[element_iter]

    "Perform next Bubble Sort iteration"
    bubble_sort_recursive_iteration(unsorted_array, array_length - 1)


def bubble_sort_recursive(unsorted_array):
    """Bubble Sort Recursive"""

    bubble_sort_recursive_iteration(unsorted_array, len(unsorted_array))
