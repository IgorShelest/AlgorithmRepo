"""
    Insertion Sort
"""


def insertion_sort(unsorted_list):
    """Insertion Sort"""

    for loop_iter in range(1, len(unsorted_list)):

        unsorted_elem = unsorted_list[loop_iter]

        elem_iter = loop_iter - 1

        while elem_iter >= 0:

            if unsorted_list[elem_iter] > unsorted_elem:
                unsorted_list[elem_iter + 1] = unsorted_list[elem_iter]
                elem_iter -= 1
            else:
                break

        unsorted_list[elem_iter + 1] = unsorted_elem

