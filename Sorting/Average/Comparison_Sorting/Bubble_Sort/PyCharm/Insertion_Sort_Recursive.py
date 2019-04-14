"""
    Insertion Sort Recursive
"""


def insertion_sort_recursive_iteration(unsorted_list, position):
    """Insertion Sort Recursive Iteration"""

    if position == len(unsorted_list):
        return

    unsorted_element = unsorted_list[position]
    element_iter = position - 1

    while element_iter >= 0:

        if unsorted_list[element_iter] > unsorted_element:
            unsorted_list[element_iter + 1] = unsorted_list[element_iter]
            element_iter -= 1
        else:
            break

    unsorted_list[element_iter + 1] = unsorted_element
    insertion_sort_recursive_iteration(unsorted_list, position + 1)


def insertion_sort_recursive(unsorted_list):
    """Insertion Sort Recursive"""

    insertion_sort_recursive_iteration(unsorted_list, 1)