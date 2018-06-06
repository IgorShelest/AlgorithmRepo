// Selection Sort.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "../../Sorting Algorithms/StaticLib/CommonLibrary.h"

#include <iostream>
#include <iomanip>

//-----------------------------------------------------------------------------

template <typename Type>
void selectionSort(Type aray[], unsigned int arraySize)
{
    for (unsigned int i = 0; i < arraySize - 1; ++i)
    {
        unsigned int minValueIter = i;

        for (unsigned int j = i + 1; j < arraySize; ++j)
        {
            if (aray[j] < aray[minValueIter])
            {
                minValueIter = j;
            }
        }

        common_library::swap(aray[i], aray[minValueIter]);
    }
};

//-----------------------------------------------------------------------------

int main()
{
    int aray[] = {4,1,7,9,5,2,1,3,66,5454,33};

    const unsigned int arraySize = sizeof(aray) / aray[0];

    selectionSort(aray, arraySize);
    common_library::printArray(aray, arraySize);


    system("pause");
    return 0;
}

