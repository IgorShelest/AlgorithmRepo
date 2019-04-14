"""
    Selection Sort Recursive
"""


def selection_sort_recursive_iteration(unsorted_list, position):
    """Selection Sort Single Iteration"""

    if position == len(unsorted_list):
        return

    current_min = unsorted_list[position]

    for elem_iter in range(position + 1, len(unsorted_list)):
        if unsorted_list[elem_iter] < current_min:
            unsorted_list[elem_iter], current_min = current_min, unsorted_list[elem_iter]

    unsorted_list[position] = current_min

    selection_sort_recursive_iteration(unsorted_list, position + 1)


def selection_sort_recursive(unsorted_list):
    """Selection Sort Recursive"""

    selection_sort_recursive_iteration(unsorted_list, 0)
