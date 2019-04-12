"""
    Selection Sort Recursive
"""


def selection_sort_recursive_iteration(unsorted_list, start_position):
    """Selection Sort Single Iteration"""

    if start_position == len(unsorted_list):
        return

    current_max = unsorted_list[start_position]

    for elem_iter in range(start_position + 1, len(unsorted_list)):
        if unsorted_list[elem_iter] > current_max:
            unsorted_list[elem_iter], current_max = current_max, unsorted_list[elem_iter]

    selection_sort_recursive_iteration(unsorted_list, start_position + 1)


def selection_sort_recursive(unsorted_list):
    """Selection Sort Recursive"""

    selection_sort_recursive_iteration(unsorted_list, 0)
