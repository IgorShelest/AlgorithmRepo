#include "stdafx.h"

//-----------------------------------------------------------------------------

#include <iostream>
#include <string>
#include <vector>

//-----------------------------------------------------------------------------

#include "../Grade-School/Grade-School.h"

//-----------------------------------------------------------------------------

namespace common_library
{

//-----------------------------------------------------------------------------

long long getDigitNumber(unsigned long long number)
{
    long long digits = 0;

    try
    {
        if (number == 0)
        {
            digits = 1;
        }
        else
        {
            while (number)
            {
                number /= 10;
                ++digits;
            };
        }
    }
    catch (std::exception const& e)
    {
        std::cout << "Exception in getDigitNumber()\n"
            << "Message: " << e.what() << "\n"
            << "Type: " << typeid(e).name() << "\n";
    }

    return digits;
};

//-----------------------------------------------------------------------------

long long getDigitNumber(const std::string& number)
{
    return number.length();
};

//-----------------------------------------------------------------------------

std::vector<unsigned int> devideIntoClasses(unsigned int number, const unsigned int digitNumber)
{
    std::vector<unsigned int> digit_Classes(digitNumber);

    try
    {
        for (unsigned int iter = 0; iter < digitNumber; ++iter)
        {
            digit_Classes[iter] = static_cast<unsigned int> ((number % 10) * pow(10, iter));
            number = number / 10;
        }
    }
    catch (std::exception const& e)
    {
        std::cout << "Exception in devideIntoClasses()\n"
            << "Message: " << e.what() << "\n"
            << "Type: " << typeid(e).name() << "\n";
    }

    return move(digit_Classes);
};

//-----------------------------------------------------------------------------

std::vector<unsigned int> devideIntoDigits(unsigned long long number, const unsigned long long digitNumber)
{
    std::vector<unsigned int> digits(static_cast<unsigned int>(digitNumber));

    try
    {
        for (unsigned int iter = 0; iter < digitNumber; ++iter)
        {
            digits[iter] = number % 10;
            number /= 10;
        }
    }
    catch (std::exception const& e)
    {
        std::cout << "Exception in devideIntoDigits()\n"
            << "Message: " << e.what() << "\n"
            << "Type: " << typeid(e).name() << "\n";
    }

    return move(digits);
};

//-----------------------------------------------------------------------------

std::vector<unsigned int> devideIntoDigits(const std::string& number, const unsigned long long digitNumber)
{
    std::vector<unsigned int> digits;

    try
    {
        for (long long iter = digitNumber - 1; iter >= 0; --iter)
        {
            digits.push_back(number[iter] - 48);
        }
    }
    catch (std::exception const& e)
    {
        std::cout << "Exception in devideIntoDigits()\n"
            << "Message: " << e.what() << "\n"
            << "Type: " << typeid(e).name() << "\n";
    }

    return move(digits);
};

//-----------------------------------------------------------------------------

long long combineIntoNumber(const std::vector<unsigned int>& digites)
{
    long long result = 0;

    try
    {
        for (int iter = digites.size() - 1; iter >= 0; --iter)
        {
            result += static_cast<long long> (digites[iter] * pow(10, iter));
        }
    }
    catch (std::exception const& e)
    {
        std::cout << "Exception in combineIntoNumber()\n"
            << "Message: " << e.what() << "\n"
            << "Type: " << typeid(e).name() << "\n";
    }

    return result;
};

//-----------------------------------------------------------------------------

long long combineIntoNumberNonReversal(const std::vector<unsigned int>& digites)
{
    long long result = 0;

    try
    {
        for (int digitIter = 0, powIter = digites.size() - 1; digitIter < static_cast<int>(digites.size()) && powIter >= 0; ++digitIter, --powIter)
        {
            result += static_cast<long long> (digites[digitIter] * pow(10, powIter));
        }
    }
    catch (std::exception const& e)
    {
        std::cout << "Exception in combineIntoNumber()\n"
            << "Message: " << e.what() << "\n"
            << "Type: " << typeid(e).name() << "\n";
    }

    return result;
};

//-----------------------------------------------------------------------------

std::string combineIntoString(const std::vector<unsigned int>& digites)
{
    long long result = 0;
    std::string resultString;

    try
    {
        for (int iter = digites.size() - 1; iter >= 0; --iter)
        {
            result += static_cast<long long> (digites[iter] * pow(10, iter));
        }

        resultString = std::to_string(result);
    }
    catch (std::exception const& e)
    {
        std::cout << "Exception in combineIntoNumber()\n"
            << "Message: " << e.what() << "\n"
            << "Type: " << typeid(e).name() << "\n";
    }

    return resultString;
};

//-----------------------------------------------------------------------------

std::string combineIntoStringNonReversal(const std::vector<unsigned int>& digites)
{
    std::string resultString;

    try
    {
        for (unsigned int digitIter = 0; digitIter < static_cast<long long>(digites.size()); ++digitIter)
        {
            resultString += std::to_string(digites[digitIter]);
        }
    }
    catch (std::exception const& e)
    {
        std::cout << "Exception in combineIntoNumber()\n"
            << "Message: " << e.what() << "\n"
            << "Type: " << typeid(e).name() << "\n";
    }

    return resultString;
};

//-----------------------------------------------------------------------------

bool isGreater(const std::string& leftHS, const std::string& rightHS)
{
    // Numbers of digits
    unsigned int leftHS_digitNumber = leftHS.length();
    unsigned int rightHS_digitNumber = rightHS.length();

    if (leftHS_digitNumber < rightHS_digitNumber)
        return false;
    else if (leftHS_digitNumber > rightHS_digitNumber)
        return true;

    // Vectors of number digits
    std::vector<unsigned int> leftHS_Digits = common_library::devideIntoDigits(leftHS, leftHS_digitNumber);
    std::vector<unsigned int> rightHS_Digits = common_library::devideIntoDigits(rightHS, rightHS_digitNumber);

    for (int iter = leftHS_digitNumber - 1; iter >= 0; --iter)
    {
        if (leftHS_Digits[iter] > rightHS_Digits[iter])
            return true;
        else if (leftHS_Digits[iter] < rightHS_Digits[iter])
            return false;
    }

    return false;
};

//-----------------------------------------------------------------------------

bool isLess(const std::string& leftHS, const std::string& rightHS)
{
    // Numbers of digits
    unsigned int leftHS_digitNumber = leftHS.length();
    unsigned int rightHS_digitNumber = rightHS.length();

    if (leftHS_digitNumber < rightHS_digitNumber)
        return true;
    else if (leftHS_digitNumber > rightHS_digitNumber)
        return false;

    // Vectors of number digits
    std::vector<unsigned int> leftHS_Digits = common_library::devideIntoDigits(leftHS, leftHS_digitNumber);
    std::vector<unsigned int> rightHS_Digits = common_library::devideIntoDigits(rightHS, rightHS_digitNumber);

    for (int iter = leftHS_digitNumber - 1; iter >= 0; --iter)
    {
        if (leftHS_Digits[iter] > rightHS_Digits[iter])
            return false;
        else if (leftHS_Digits[iter] < rightHS_Digits[iter])
            return true;
    }

    return false;
};

//-----------------------------------------------------------------------------

bool areEqual(const std::string& leftHS, const std::string& rightHS)
{
    // Numbers of digits
    unsigned int leftHS_digitNumber = leftHS.length();
    unsigned int rightHS_digitNumber = rightHS.length();

    if (leftHS_digitNumber != rightHS_digitNumber)
        return false;

    // Vectors of number digits
    std::vector<unsigned int> leftHS_Digits = common_library::devideIntoDigits(leftHS, leftHS_digitNumber);
    std::vector<unsigned int> rightHS_Digits = common_library::devideIntoDigits(rightHS, rightHS_digitNumber);

    for (int iter = leftHS_digitNumber - 1; iter >= 0; --iter)
    {
        if (leftHS_Digits[iter] != rightHS_Digits[iter])
            return false;
    }

    return true;
};

//-----------------------------------------------------------------------------

std::string pow(const std::string number, const std::string power)
{
    std::string result = number;

    if (power == std::to_string(0)) return std::to_string(1);
    if (power == std::to_string(1)) return result;

    for (std::string iter = std::to_string(0); common_library::isLess(iter, grade_school::subtractGradeSchool(power, std::to_string(1))); iter = grade_school::sumGradeSchool(iter, std::to_string(1)))
    {
        result = grade_school::multiplyGradeSchool(result, number);
    }

    return result;
};

//-----------------------------------------------------------------------------

}