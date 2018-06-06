#pragma once

#include <iostream>

namespace common_library
{
//-----------------------------------------------------------------------------

template <typename Type>
void swap(Type& leftHS, Type& rightHS)
{
    Type temp = leftHS;
    leftHS = rightHS;
    rightHS = temp;
};

//-----------------------------------------------------------------------------

template <typename Type>
void printArray(Type aray[], unsigned int arraySize)
{
    for (unsigned int i = 0; i < arraySize; ++i)
        std::cout << std::setw(3) << aray[i];
    std::cout << "\n";
};

//-----------------------------------------------------------------------------
}