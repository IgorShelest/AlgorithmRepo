// Bubble Sort.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include "../../Sorting Algorithms/StaticLib/CommonLibrary.h"

//-----------------------------------------------------------------------------

template <typename Type>
void bubbleSort(Type aray[], unsigned int size)
{
    for (unsigned int i = 0; i < size - 1; ++i)
    {
        for (unsigned int j = 0; j < size - 1 - i; ++j)
        {
            if (aray[j] > aray[j + 1])
            {
                common_library::swap(aray[j], aray[j + 1]);
            }
        }
    }
};

//-----------------------------------------------------------------------------

template <typename Type>
void bubbleSortRecursive(Type aray[], unsigned int size)
{
    if (size <= 1)
        return;

    bubbleSortRecursive(aray, size -1);

    for (unsigned int j = 0; j < size - 2; ++j)
    {
        if (aray[j] > aray[j + 1])
        {
            common_library::swap(aray[j], aray[j + 1]);
        }
    }
};

//-----------------------------------------------------------------------------

int main()
{
    int aray[] = { 4,3,2,10,12,1,5,6 };
    int aray2[] = { 4,3,2,10,12,1,5,6 };

    const unsigned int arraySize = sizeof(aray) / aray[0];

    std::cout << "\nBubbleSort:\n";
    bubbleSort(aray, arraySize);
    common_library::printArray(aray, arraySize);

    std::cout << "\nInsertionSortRecursive:\n";
    bubbleSortRecursive(aray2, arraySize);
    common_library::printArray(aray, arraySize);

    system("pause");
    return 0;
}

