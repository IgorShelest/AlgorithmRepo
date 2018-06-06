// Merge Sort.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <iomanip>
#include <memory.h>
#include "../../Sorting Algorithms/StaticLib/CommonLibrary.h"

//-----------------------------------------------------------------------------

template <typename Type>
void merge(Type aray[], unsigned int startIter, unsigned int endIter, unsigned int size)
{
    unsigned int numOfRightPartElems = size / 2;
    unsigned int numOfLeftPartElems = size - numOfRightPartElems;

    // Creating copy of LeftPart 
    Type* leftPartArray = new Type[numOfLeftPartElems];
    for (unsigned int arayIter = startIter, leftPartArrayIter = 0; arayIter <= (endIter - numOfRightPartElems); ++arayIter, ++leftPartArrayIter)
    {
        leftPartArray[leftPartArrayIter] = aray[arayIter];
    }

    // Creating copy of RightPart 
    Type* rightPartArray = new Type[numOfRightPartElems];
    for (unsigned int arayIter = endIter - numOfRightPartElems + 1, rightPartArrayIter = 0; arayIter <= endIter; ++arayIter, ++rightPartArrayIter)
    {
        rightPartArray[rightPartArrayIter] = aray[arayIter];
    }

    unsigned int leftIter = 0;
    unsigned int rightIter = 0;
    unsigned int arayIter = startIter;

    // Merge LeftPart and RightPart into one aray
    while (leftIter < numOfLeftPartElems && rightIter < numOfRightPartElems)
    {
        if (leftPartArray[leftIter] <= rightPartArray[rightIter])
            aray[arayIter++] = leftPartArray[leftIter++];
        else
            aray[arayIter++] = rightPartArray[rightIter++];
    }

    // Add remaining LeftPart elems
    while (leftIter < numOfLeftPartElems)
        aray[arayIter++] = leftPartArray[leftIter++];

    // Add remaining RightPart elems
    while (rightIter < numOfRightPartElems)
        aray[arayIter++] = rightPartArray[rightIter++];

    delete leftPartArray;
    delete rightPartArray;
};

//-----------------------------------------------------------------------------

template <typename Type>
void merge2(Type aray[], unsigned int startIter, unsigned int midIter, unsigned int endIter)
{
    unsigned int numOfRightPartElems = endIter - midIter;
    unsigned int numOfLeftPartElems = midIter - startIter + 1;

    // Creating copy of LeftPart 
    Type* leftPartArray = new Type[numOfLeftPartElems];
    for (unsigned int arayIter = startIter, leftPartArrayIter = 0; arayIter <= (endIter - numOfRightPartElems); ++arayIter, ++leftPartArrayIter)
    {
        leftPartArray[leftPartArrayIter] = aray[arayIter];
    }

    // Creating copy of RightPart 
    Type* rightPartArray = new Type[numOfRightPartElems];
    for (unsigned int arayIter = endIter - numOfRightPartElems + 1, rightPartArrayIter = 0; arayIter <= endIter; ++arayIter, ++rightPartArrayIter)
    {
        rightPartArray[rightPartArrayIter] = aray[arayIter];
    }

    unsigned int leftIter = 0;
    unsigned int rightIter = 0;
    unsigned int arayIter = startIter;

    // Merge LeftPart and RightPart into one aray
    while (leftIter < numOfLeftPartElems && rightIter < numOfRightPartElems)
    {
        if (leftPartArray[leftIter] <= rightPartArray[rightIter])
            aray[arayIter++] = leftPartArray[leftIter++];
        else
            aray[arayIter++] = rightPartArray[rightIter++];
    }

    // Add remaining LeftPart elems
    while (leftIter < numOfLeftPartElems)
        aray[arayIter++] = leftPartArray[leftIter++];

    // Add remaining RightPart elems
    while (rightIter < numOfRightPartElems)
        aray[arayIter++] = rightPartArray[rightIter++];

    delete leftPartArray;
    delete rightPartArray;
};

//-----------------------------------------------------------------------------

template <typename Type>
void mergeSortRecursive(Type aray[], unsigned int startIter, unsigned int endIter, unsigned int size)
{
    if (size == 1)
        return;
    else
    {
        unsigned int numOfRightPartElems = size / 2;
        unsigned int numOfLeftPartElems = size - numOfRightPartElems;

        // Division for Left part
        mergeSortRecursive(aray, startIter, endIter - numOfRightPartElems, numOfLeftPartElems);

        // Division for Right part
        mergeSortRecursive(aray, endIter - numOfRightPartElems + 1, endIter, numOfRightPartElems);
    }

    merge(aray, startIter, endIter, size);
};

//-----------------------------------------------------------------------------

template <typename Type>
void mergeSort(Type aray[], unsigned int size)
{
    for (unsigned int subArraySize = 2; subArraySize <= 2 * size; subArraySize *= 2)
    {
        for (unsigned int iter = 0; iter <= size - 1; iter += subArraySize)
        {
            unsigned int subArrayStartIter = iter;
            unsigned int subArrayEndIter = iter + subArraySize - 1;
            unsigned int subArrayMidIter = subArrayEndIter - (subArraySize / 2);

            // The last subArray's midIter
            if ((size - 1) < subArrayMidIter)
            {
                subArrayMidIter = size - 1;
            }

            // The last subArray's endIter
            if ((size - 1) < subArrayEndIter)
            {
                subArrayEndIter = size - 1;
            }
            merge2(aray, subArrayStartIter, subArrayMidIter, subArrayEndIter);
        }
    }

    merge(aray, 0, size - 1, size);
};

//-----------------------------------------------------------------------------

int main()
{
    int aray[] = { 4, 3, 2, 10, 12, 1, 5, 6, 8, 0};
    int aray2[] = { 4, 3, 2, 10, 12, 1, 5, 6, 8, 0};

    const unsigned int arraySize = sizeof(aray) / sizeof(aray[0]);

    std::cout << "\mMergeSortRecursive:\n";
    mergeSortRecursive(aray, 0, arraySize -1, arraySize);
    common_library::printArray(aray, arraySize);

    std::cout << "\mMergeSort:\n";
    mergeSort(aray2, arraySize);
    common_library::printArray(aray2, arraySize);

    system("pause");
    return 0;
}

