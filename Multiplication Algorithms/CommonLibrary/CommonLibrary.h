#pragma once

//-----------------------------------------------------------------------------

#include <vector>

//-----------------------------------------------------------------------------

//#include "../Grade-School/Grade-School.h"

//-----------------------------------------------------------------------------

namespace common_library
{

//-----------------------------------------------------------------------------//
//                              Help Functions                                 //
//-----------------------------------------------------------------------------//   

long long getDigitNumber(unsigned long long number);

//-----------------------------------------------------------------------------

long long getDigitNumber(const std::string& number);

//-----------------------------------------------------------------------------

std::vector<unsigned int> devideIntoClasses(unsigned int number, const unsigned int digitNumber);

//-----------------------------------------------------------------------------//
//                              devideIntoDigits                               //
//-----------------------------------------------------------------------------// 

std::vector<unsigned int> devideIntoDigits(unsigned long long number, const unsigned long long digitNumber);

//-----------------------------------------------------------------------------

std::vector<unsigned int> devideIntoDigits(const std::string& number, const unsigned long long digitNumber);

//-----------------------------------------------------------------------------//
//                              combineIntoNumber                              //
//-----------------------------------------------------------------------------// 

long long combineIntoNumber(const std::vector<unsigned int>& digites);

//-----------------------------------------------------------------------------

long long combineIntoNumberNonReversal(const std::vector<unsigned int>& digites);

//-----------------------------------------------------------------------------//
//                              combineIntoString                              //
//-----------------------------------------------------------------------------// 

std::string combineIntoString(const std::vector<unsigned int>& digites);

//-----------------------------------------------------------------------------

std::string combineIntoStringNonReversal(const std::vector<unsigned int>& digites);


//-----------------------------------------------------------------------------//
//                                  comparison                                 //
//-----------------------------------------------------------------------------// 

bool isGreater(const std::string& leftHS, const std::string& rightHS);

//-----------------------------------------------------------------------------

bool isLess(const std::string& leftHS, const std::string& rightHS);

//-----------------------------------------------------------------------------

bool areEqual(const std::string& leftHS, const std::string& rightHS);

//-----------------------------------------------------------------------------

template<typename Type>
Type min(Type leftHS, Type rightHS)
{
    return leftHS < rightHS ? leftHS : rightHS;
};

//-----------------------------------------------------------------------------

template<typename Type>
Type max(Type leftHS, Type ightHS)
{
    return leftHS > rightHS ? leftHS : rightHS;
};

//-----------------------------------------------------------------------------

template<typename Type>
void swap(Type& leftHS, Type& rightHS)
{
    Type temp = leftHS;
    leftHS = rightHS;
    rightHS = temp;
};

//-----------------------------------------------------------------------------

template <typename Type>
Type pow(Type number, Type power)
{
    Type result = number;

    if (power == 0) return 1;
    if (power == 1) return result;

    for (Type iter = 0; iter < power - 1; ++iter)
    {
        result *= number;
    }

    return result;
};

//-----------------------------------------------------------------------------

std::string pow(const std::string number, const std::string power);

//-----------------------------------------------------------------------------

}