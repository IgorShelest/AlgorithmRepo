from collections import namedtuple
import random

from Bubble_Sort import bubble_sort


Const = namedtuple('Const', 'data')
test_counter = Const(10)
num_of_elements = Const(20)


for test_iter in range(test_counter.data):
    unsorted_list = []

    for element_iter in range(num_of_elements.data):
        unsorted_list.append(random.randint(1, num_of_elements.data))

    print("Test: " + str(test_iter))
    print("Unsorted list before sorting: " + str(unsorted_list))
    bubble_sort(unsorted_list)
    print("Unsorted list after sorting" + str(unsorted_list))
    print("")

