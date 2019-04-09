"""
    Bubble Sort algorithm
"""


def bubble_sort(unsorted_array):
    """Bubble Sort function"""

    for loop_iter in range(len(unsorted_array) - 1):

        for elem_iter in range(len(unsorted_array) - 1 - loop_iter):

            if unsorted_array[elem_iter] > unsorted_array[elem_iter + 1]:
                unsorted_array[elem_iter], unsorted_array[elem_iter + 1] = unsorted_array[elem_iter + 1], unsorted_array[elem_iter]
