// Insertion Sort.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include "../../Sorting Algorithms/StaticLib/CommonLibrary.h"

//-----------------------------------------------------------------------------

template <typename Type>
void insertionSort(Type aray[], unsigned int size)
{
    for (unsigned int j = 1; j < size; ++j)
    {
        Type currentValue;
        unsigned int currentIter;

        if (aray[j] < aray[j - 1])
        {
            currentValue = aray[j];
            currentIter = j;

            while (j > 0 && currentValue < aray[j - 1])
            {
                aray[j] = aray[j - 1];
                --j;
            }

            aray[j] = currentValue;
            j = currentIter;

            common_library::printArray(aray, size);
        }
    }
};

//-----------------------------------------------------------------------------

template <typename Type>
void insertionSortRecursive(Type aray[], unsigned int size)
{
    if (size <= 1)
        return;

    insertionSortRecursive(aray, size -1);

    Type currentValue;
    unsigned int j = size - 1;

    if (aray[j] < aray[j - 1])
    {
        currentValue = aray[j];

        while (j > 0 && currentValue < aray[j - 1])
        {
            aray[j] = aray[j - 1];
            --j;
        }

        aray[j] = currentValue;

        common_library::printArray(aray, size);
    }

};

//-----------------------------------------------------------------------------

int main()
{
    int aray[] = { 4,3,2,10,12,1,5,6 };
    int aray2[] = { 4,3,2,10,12,1,5,6 };

    const unsigned int arraySize = sizeof(aray) / aray[0];

    std::cout << "\nInsertionSort:\n";
    insertionSort(aray, arraySize);
    common_library::printArray(aray, arraySize);

    std::cout << "\nInsertionSortRecursive:\n";
    insertionSortRecursive(aray2, arraySize);
    common_library::printArray(aray, arraySize);

    system("pause");
    return 0;
}

