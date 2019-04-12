import random

from collections import namedtuple
from Bubble_Sort import bubble_sort
from Bubble_Sort_Recursive import bubble_sort_recursive
from Insertion_Sort import insertion_sort
from Insertion_Sort_Recursive import insertion_sort_recursive
from Selection_Sort import selection_sort
from Selection_Sort_Rectursive import selection_sort_recursive


"""
    Custom Types
"""

ConstType = namedtuple('Const', 'data')

"""
    Global Variables
"""

g_test_counter = ConstType(10)
g_num_of_elements = ConstType(20)

"""
    Functions
"""


def create_unsorted_list(num_of_elements):
    """Create unsorted list"""

    unsorted_list = []
    for element_iter in range(num_of_elements.data):
        unsorted_list.append(random.randint(1, num_of_elements.data))
    return unsorted_list


def compare_lists(left_list, right_list):
    """List comparison"""

    if len(left_list) != len(right_list):
        return False

    for i in range(len(left_list)):
        if left_list[i] != right_list[i]:
            return False

    return True


def run_test(function, test_counter, num_of_elements):
    for test_iter in range(test_counter.data):

        "Create unsorted list"
        unsorted_list = create_unsorted_list(num_of_elements)
        verification_list = unsorted_list

        "Sort list"
        function(unsorted_list)

        "Create verification list"
        verification_list.sort()

        "Compare result"
        print("Test " + str(test_iter) + ": " + ("Passed" if compare_lists(unsorted_list, verification_list) else "Failed"))


"""
    Main 
"""

print("\nBubble Sort verification")
run_test(bubble_sort, g_test_counter, g_num_of_elements)

print("\nBubble Sort Recursive verification")
run_test(bubble_sort_recursive, g_test_counter, g_num_of_elements)

print("\nInsertion Sort verification")
run_test(insertion_sort, g_test_counter, g_num_of_elements)

print("\nInsertion Sort Recursive verification")
run_test(insertion_sort_recursive, g_test_counter, g_num_of_elements)

print("\nSelection Sort verification")
run_test(selection_sort, g_test_counter, g_num_of_elements)

print("\nSelection Sort Recursive verification")
run_test(selection_sort_recursive, g_test_counter, g_num_of_elements)
