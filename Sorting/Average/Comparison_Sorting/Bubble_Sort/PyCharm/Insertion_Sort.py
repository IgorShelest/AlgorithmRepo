"""
    Insertion Sort
"""


def insertion_sort(unsorted_list):
    """Insertion Sort"""

    for loop_iter in range(len(unsorted_list) - 1):
        for elem_iter in reversed(range(loop_iter + 1)):
            if unsorted_list[elem_iter] < unsorted_list[elem_iter + 1]:
                unsorted_list[elem_iter], unsorted_list[elem_iter + 1] = \
                    unsorted_list[elem_iter + 1], unsorted_list[elem_iter]
