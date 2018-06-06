// Grade-School.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

//-----------------------------------------------------------------------------

#include "../CommonLibrary/CommonLibrary.h"
#include <string>
#include <iostream>

//-----------------------------------------------------------------------------

namespace grade_school
{

//-----------------------------------------------------------------------------

long long multiplyGradeSchool(const long long& leftHS, const long long& rightHS)
{
    // Numbers of digits
    const unsigned int leftHS_digitNumber = static_cast<unsigned int>(common_library::getDigitNumber(leftHS));
    const unsigned int rightHS_digitNumber = static_cast<unsigned int>(common_library::getDigitNumber(rightHS));

    // Vectors of number digits
    const std::vector<unsigned int> leftHS_Digits = common_library::devideIntoDigits(leftHS, leftHS_digitNumber);
    const std::vector<unsigned int> rightHS_Digits = common_library::devideIntoDigits(rightHS, rightHS_digitNumber);

    // Max number of digits in first temp result
    const unsigned int firstTempResultMaxDigitNumber = static_cast<unsigned int>(rightHS_digitNumber + 1);

    // Number of shifts left
    const unsigned int shiftLeftNum = static_cast<unsigned int>(leftHS_digitNumber - 1);

    // Number of additional digits after shifts left
    const unsigned int shiftLeftDigitNum = static_cast<unsigned int>(shiftLeftNum * 2);

    // Max number of digits in any temp result
    const unsigned int tempResultDigitNum = static_cast<unsigned int>(firstTempResultMaxDigitNumber + shiftLeftDigitNum);

    // Temp multiplication results
    std::vector< std::vector<unsigned int> > tempResults(leftHS_digitNumber, std::vector<unsigned int>(tempResultDigitNum, 0));

    for (unsigned int leftIter = 0; leftIter < leftHS_digitNumber; ++leftIter)
    {
        unsigned int cash = 0;
        unsigned int numOfDigitsToShiftLeft = leftIter;

        for (unsigned int rightIter = 0; rightIter < rightHS_digitNumber; ++rightIter)
        {
            unsigned int multiplication_temp = leftHS_Digits[leftIter] * rightHS_Digits[rightIter];

            tempResults[leftIter][rightIter + numOfDigitsToShiftLeft] = (multiplication_temp + cash) % 10;
            cash = (multiplication_temp + cash) / 10;

            // Last multiplication in temp Result
            if (rightIter == (rightHS_digitNumber - 1))
            {
                tempResults[leftIter][rightIter + numOfDigitsToShiftLeft + 1] = cash;
            }
        }
    }

#ifdef LOGGING
    // leftHS_Digits
    for (const unsigned int& digit : leftHS_Digits)
    {
        std::cout << digit;
    }
    std::cout << "\n";

    // rightHS_Digits
    for (const unsigned int& digit : rightHS_Digits)
    {
        std::cout << digit;
    }
    std::cout << "\n";

    // Temp results
    for (const vector<unsigned int>& tempResult : tempResults)
    {
        for (const unsigned int& digit : tempResult)
        {
            std::cout << digit;
        }
        std::cout << "\n";
    }
#endif

    std::vector<unsigned int> sum(tempResultDigitNum + 1);
    unsigned int cash = 0;

    // Summing of temp multiplication results
    for (unsigned int position = 0; position < tempResultDigitNum; ++position)
    {
        unsigned int tempSum = 0;

        for (unsigned int tempResult = 0; tempResult < leftHS_digitNumber; ++tempResult)
        {
            tempSum += tempResults[tempResult][position];
        }

        sum[position] = (tempSum + cash) % 10;
        cash = (tempSum + cash) / 10;
    }

#ifdef LOGGING
    // Sum
    for (const unsigned int& digit : sum)
    {
        std::cout << digit;
    }
    std::cout << "\n";
#endif

    unsigned int startPosition = 0;
    for (int iter = sum.size() - 1; iter >= 0; --iter)
    {
        if (sum[iter] != 0)
        {
            startPosition = iter;
            break;
        }
    }

    // Trim zeros
    std::vector<unsigned int> result(startPosition + 1);
    for (int tempSumPosition = startPosition, resultPosition = 0; tempSumPosition >= 0; --tempSumPosition, ++resultPosition)
    {
        result[resultPosition] = sum[tempSumPosition];
    }

#ifdef LOGGING
    // result
    for (const unsigned int& digit : result)
    {
        std::cout << digit;
    }
#endif

    return common_library::combineIntoNumberNonReversal(result);
};

//-----------------------------------------------------------------------------

long long sumGradeSchool(const long long& leftHS, const long long& rightHS)
{
    // Numbers of digits
    const unsigned int leftHS_digitNumber = static_cast<unsigned int>(common_library::getDigitNumber(leftHS));
    const unsigned int rightHS_digitNumber = static_cast<unsigned int>(common_library::getDigitNumber(rightHS));

    // Vectors of number digits
    std::vector<unsigned int> leftHS_Digits = common_library::devideIntoDigits(leftHS, leftHS_digitNumber);
    std::vector<unsigned int> rightHS_Digits = common_library::devideIntoDigits(rightHS, rightHS_digitNumber);

    // Max number of digits in result
    unsigned int resultDigitNum;

    // Add zeros to both vectors for them to be of the same size
    if (leftHS_digitNumber >= rightHS_digitNumber)
    {
        resultDigitNum = leftHS_digitNumber + 1;
        const unsigned int diffBetweenVectors = leftHS_digitNumber - rightHS_digitNumber;

        leftHS_Digits.push_back(0);

        for (unsigned int iter = 0; iter <= diffBetweenVectors; ++iter)
        {
            rightHS_Digits.push_back(0);
        }
    }
    else
    {
        resultDigitNum = rightHS_digitNumber + 1;
        const unsigned int diffBetweenVectors = rightHS_digitNumber - leftHS_digitNumber;

        rightHS_Digits.push_back(0);

        for (unsigned int iter = 0; iter <= diffBetweenVectors; ++iter)
        {
            leftHS_Digits.push_back(0);
        }
    }

    // Results vector
    std::vector< unsigned int > tempResult(resultDigitNum, 0);

    // Summing up
    unsigned int cash = 0;

    for (unsigned int iter = 0; iter < resultDigitNum - 1; ++iter)
    {
        const unsigned int summing_temp = leftHS_Digits[iter] + rightHS_Digits[iter];

        tempResult[iter] = (summing_temp + cash) % 10;
        cash = (summing_temp + cash) / 10;

        // Last summing in temp Result
        if (iter == (resultDigitNum - 2))
        {
            tempResult[resultDigitNum - 1] = cash;
        }
    }

#ifdef LOGGING
    // leftHS_Digits
    for (const unsigned int& digit : leftHS_Digits)
    {
        std::cout << digit;
    }
    std::cout << "\n";

    // rightHS_Digits
    for (const unsigned int& digit : rightHS_Digits)
    {
        std::cout << digit;
    }
    std::cout << "\n";

    // Results
    for (const unsigned int& digit : tempResult)
    {
        std::cout << digit;
    }
    std::cout << "\n";
#endif

    // Trim zeros from the end
    unsigned int startPosition = 0;
    for (int iter = tempResult.size() - 1; iter >= 0; --iter)
    {
        if (tempResult[iter] != 0)
        {
            startPosition = iter;
            break;
        }
    }

    std::vector<unsigned int> result(startPosition + 1);
    for (int tempSumPosition = startPosition, resultPosition = 0; tempSumPosition >= 0; --tempSumPosition, ++resultPosition)
    {
        result[resultPosition] = tempResult[tempSumPosition];
    }

#ifdef LOGGING
    // result
    for (const unsigned int& digit : result)
    {
        std::cout << digit;
    }
#endif

    return common_library::combineIntoNumberNonReversal(result);
};

//-----------------------------------------------------------------------------

std::string multiplyGradeSchool(const std::string& leftHS, const std::string& rightHS)
{
    // Numbers of digits
    const long long leftHS_digitNumber = leftHS.length();
    const long long rightHS_digitNumber = rightHS.length();

    // Vectors of number digits
    const std::vector<unsigned int> leftHS_Digits = common_library::devideIntoDigits(leftHS, leftHS_digitNumber);
    const std::vector<unsigned int> rightHS_Digits = common_library::devideIntoDigits(rightHS, rightHS_digitNumber);

    // Max number of digits in first temp result
    const long long firstTempResultMaxDigitNumber = rightHS_digitNumber + 1;

    // Number of shifts left
    const long long shiftLeftNum = leftHS_digitNumber - 1;

    // Number of additional digits after shifts left
    const long long shiftLeftDigitNum = shiftLeftNum * 2;

    // Max number of digits in any temp result
    const long long tempResultDigitNum = firstTempResultMaxDigitNumber + shiftLeftDigitNum;

    // Temp multiplication results
    std::vector< std::vector<unsigned int> > tempResults(static_cast<unsigned int>(leftHS_digitNumber), std::vector<unsigned int>(static_cast<unsigned int>(tempResultDigitNum), 0));

    for (unsigned int leftIter = 0; leftIter < leftHS_digitNumber; ++leftIter)
    {
        unsigned int cash = 0;
        unsigned int numOfDigitsToShiftLeft = leftIter;

        for (unsigned int rightIter = 0; rightIter < rightHS_digitNumber; ++rightIter)
        {
            unsigned int multiplication_temp = leftHS_Digits[leftIter] * rightHS_Digits[rightIter];

            tempResults[leftIter][rightIter + numOfDigitsToShiftLeft] = (multiplication_temp + cash) % 10;
            cash = (multiplication_temp + cash) / 10;

            // Last multiplication in temp Result
            if (rightIter == (rightHS_digitNumber - 1))
            {
                tempResults[leftIter][rightIter + numOfDigitsToShiftLeft + 1] = cash;
            }
        }
    }

#ifdef LOGGING
    // leftHS_Digits
    for (const unsigned int& digit : leftHS_Digits)
    {
        std::cout << digit;
    }
    std::cout << "\n";

    // rightHS_Digits
    for (const unsigned int& digit : rightHS_Digits)
    {
        std::cout << digit;
    }
    std::cout << "\n";

    // Temp results
    for (const vector<unsigned int>& tempResult : tempResults)
    {
        for (const unsigned int& digit : tempResult)
        {
            std::cout << digit;
        }
        std::cout << "\n";
    }
#endif

    std::vector<unsigned int> sum(static_cast<unsigned int>(tempResultDigitNum + 1));
    unsigned int cash = 0;

    // Summing of temp multiplication results
    for (unsigned int position = 0; position < tempResultDigitNum; ++position)
    {
        unsigned int tempSum = 0;

        for (unsigned int tempResult = 0; tempResult < leftHS_digitNumber; ++tempResult)
        {
            tempSum += tempResults[tempResult][position];
        }

        sum[position] = (tempSum + cash) % 10;
        cash = (tempSum + cash) / 10;
    }

#ifdef LOGGING
    // Sum
    for (const unsigned int& digit : sum)
    {
        std::cout << digit;
    }
    std::cout << "\n";
#endif

    unsigned int startPosition = 0;
    for (int iter = sum.size() - 1; iter >= 0; --iter)
    {
        if (sum[iter] != 0)
        {
            startPosition = iter;
            break;
        }
    }

    std::vector<unsigned int> result(startPosition + 1);
    for (int tempSumPosition = startPosition, resultPosition = 0; tempSumPosition >= 0; --tempSumPosition, ++resultPosition)
    {
        result[resultPosition] = sum[tempSumPosition];
    }

#ifdef LOGGING
    // Result
    std::cout << "\n";
    for (const unsigned int& digit : result)
    {
        std::cout << digit;
    }
#endif

    return common_library::combineIntoStringNonReversal(result);
};

//-----------------------------------------------------------------------------

std::string sumGradeSchool(const std::string& leftHS, const std::string& rightHS)
{
    // Numbers of digits
    const unsigned int leftHS_digitNumber = leftHS.size();
    const unsigned int rightHS_digitNumber = rightHS.size();

    // Vectors of number digits
    std::vector<unsigned int> leftHS_Digits = common_library::devideIntoDigits(leftHS, leftHS_digitNumber);
    std::vector<unsigned int> rightHS_Digits = common_library::devideIntoDigits(rightHS, rightHS_digitNumber);

    // Max number of digits in result
    unsigned int resultDigitNum;

    // Add zeros to both vectors for them to be of the same size
    if (leftHS_digitNumber >= rightHS_digitNumber)
    {
        resultDigitNum = leftHS_digitNumber + 1;
        const unsigned int diffBetweenVectors = leftHS_digitNumber - rightHS_digitNumber;

        leftHS_Digits.push_back(0);

        for (unsigned int iter = 0; iter < diffBetweenVectors; ++iter)
        {
            rightHS_Digits.push_back(0);
        }
    }
    else
    {
        resultDigitNum = rightHS_digitNumber + 1;
        const unsigned int diffBetweenVectors = rightHS_digitNumber - leftHS_digitNumber;

        rightHS_Digits.push_back(0);

        for (unsigned int iter = 0; iter < diffBetweenVectors; ++iter)
        {
            leftHS_Digits.push_back(0);
        }
    }

    // Results vector
    std::vector< unsigned int > tempResult(resultDigitNum, 0);

    // Summing up
    unsigned int cash = 0;

    for (unsigned int iter = 0; iter < resultDigitNum - 1; ++iter)
    {
        const unsigned int summing_temp = leftHS_Digits[iter] + rightHS_Digits[iter];

        tempResult[iter] = (summing_temp + cash) % 10;
        cash = (summing_temp + cash) / 10;

        // Last summing in temp Result
        if (iter == (resultDigitNum - 2))
        {
            tempResult[resultDigitNum - 1] = cash;
        }
    }

#ifdef LOGGING
    // leftHS_Digits
    for (const unsigned int& digit : leftHS_Digits)
    {
        std::cout << digit;
    }
    std::cout << "\n";

    // rightHS_Digits
    for (const unsigned int& digit : rightHS_Digits)
    {
        std::cout << digit;
    }
    std::cout << "\n";

    // Results
    for (const unsigned int& digit : tempResult)
    {
        std::cout << digit;
    }
    std::cout << "\n";
#endif

    // Trim zeros from the end
    unsigned int startPosition = 0;
    for (int iter = tempResult.size() - 1; iter >= 0; --iter)
    {
        if (tempResult[iter] != 0)
        {
            startPosition = iter;
            break;
        }
    }

    std::vector<unsigned int> result(startPosition + 1);
    for (int tempSumPosition = startPosition, resultPosition = 0; tempSumPosition >= 0; --tempSumPosition, ++resultPosition)
    {
        result[resultPosition] = tempResult[tempSumPosition];
    }

#ifdef LOGGING
    // result
    for (const unsigned int& digit : result)
    {
        std::cout << digit;
    }
#endif

    return common_library::combineIntoStringNonReversal(result);
};

//-----------------------------------------------------------------------------

long long subtractGradeSchool(const unsigned long long& left_hs, const unsigned long long& right_hs)
{
    long long result_Number = 0;

    // Numbers of digits
    unsigned int left_hs_digit_number = static_cast<unsigned int>(common_library::getDigitNumber(left_hs));
    unsigned int right_hs_digit_number = static_cast<unsigned int>(common_library::getDigitNumber(right_hs));

    // Vectors of number digits
    std::vector<unsigned int> left_hs_digits;
    std::vector<unsigned int> right_hs_digits;

    // Max number of digits in result
    unsigned int result_digit_num;
    bool result_is_negative = false;

    if (common_library::isGreater(std::to_string(left_hs), std::to_string(right_hs)))
    {
        result_digit_num = left_hs_digit_number;

        left_hs_digits = common_library::devideIntoDigits(left_hs, left_hs_digit_number);
        right_hs_digits = common_library::devideIntoDigits(right_hs, right_hs_digit_number);
    }
    else if (common_library::isLess(std::to_string(left_hs), std::to_string(right_hs)))
    {
        result_digit_num = right_hs_digit_number;
        result_is_negative = true;

        left_hs_digits = common_library::devideIntoDigits(right_hs, right_hs_digit_number);
        right_hs_digits = common_library::devideIntoDigits(left_hs, left_hs_digit_number);

        common_library::swap(right_hs_digit_number, left_hs_digit_number);
    }
    else
    {
        return 0;
    }

    // Results vector
    std::vector< unsigned int > result(result_digit_num, 0);

    // Subtraction
    unsigned int cash = 0;

    for (unsigned int iter = 0; iter < right_hs_digit_number; ++iter)
    {
        // Calculate temp_left_hs_digit
        int temp_left_hs_digit = left_hs_digits[iter];

        if (cash > 0)
        {
            if (left_hs_digits[iter] > 0)
            {
                temp_left_hs_digit -= 1;
                --cash;
            }
            else
            {
                temp_left_hs_digit = temp_left_hs_digit + 10 - 1;
            }
        }

        // Calculate temp_right_hs_digit
        int temp_right_hs_digit = right_hs_digits[iter];

        if (temp_left_hs_digit < temp_right_hs_digit)
        {
            // Increase temp_left_hs_digit in case it's lower then rightHS_digit
            temp_left_hs_digit += 10;
            ++cash;
        }

        result[iter] = temp_left_hs_digit - temp_right_hs_digit;
    }

    // If there are still left digits from the left_hs_digits
    for (unsigned int iter = right_hs_digit_number; iter < left_hs_digit_number; ++iter)
    {
        if (cash > 0)
        {
            if (left_hs_digits[iter] > 0)
            {
                result[iter] = left_hs_digits[iter] - 1;
                --cash;
            }
            else
            {
                result[iter] = left_hs_digits[iter] + 10 - 1;
            }
        }
        else
        {
            result[iter] = left_hs_digits[iter];
        }
    }

#ifdef LOGGING
    // leftHS_Digits
    for (const unsigned int& digit : leftHS_Digits)
    {
        std::cout << digit;
    }
    std::cout << "\n";

    // rightHS_Digits
    for (const unsigned int& digit : rightHS_Digits)
    {
        std::cout << digit;
    }
    std::cout << "\n";

    // result
    for (const unsigned int& digit : result)
    {
        std::cout << digit;
    }
#endif

    // Combine into number
    result_Number = common_library::combineIntoNumber(result);

    // Add sign
    result_Number *= result_is_negative ? (-1) : 1;

    return result_Number;
};

//-----------------------------------------------------------------------------

std::string subtractGradeSchool(const std::string& left_hs, const std::string& right_hs)
{
    // Numbers of digits
    unsigned int left_hs_digit_number = left_hs.length();
    unsigned int right_hs_digit_number = right_hs.length();

    // Vectors of number digits
    std::vector<unsigned int> left_hs_digits;
    std::vector<unsigned int> right_hs_digits;

    // Max number of digits in result
    unsigned int result_digit_num;
    bool result_is_negative = false;

    if (common_library::isGreater(left_hs, right_hs))
    {
        result_digit_num = left_hs_digit_number;

        left_hs_digits = common_library::devideIntoDigits(left_hs, left_hs_digit_number);
        right_hs_digits = common_library::devideIntoDigits(right_hs, right_hs_digit_number);
    }
    else if (common_library::isLess(left_hs, right_hs))
    {
        result_digit_num = right_hs_digit_number;
        result_is_negative = true;

        left_hs_digits = common_library::devideIntoDigits(right_hs, right_hs_digit_number);
        right_hs_digits = common_library::devideIntoDigits(left_hs, left_hs_digit_number);

        common_library::swap(right_hs_digit_number, left_hs_digit_number);
    }
    else
    {
        return std::to_string(0);
    }

    // Results vector
    std::vector< unsigned int > result(result_digit_num, 0);

    // Subtraction
    unsigned int cash = 0;

    for (unsigned int iter = 0; iter < right_hs_digit_number; ++iter)
    {
        // Calculate temp_left_hs_digit
        int temp_left_hs_digit = left_hs_digits[iter];

        if (cash > 0)
        {
            if (left_hs_digits[iter] > 0)
            {
                temp_left_hs_digit -= 1;
                --cash;
            }
            else
            {
                temp_left_hs_digit = temp_left_hs_digit + 10 - 1;
            }
        }

        // Calculate temp_right_hs_digit
        int temp_right_hs_digit = right_hs_digits[iter];

        if (temp_left_hs_digit < temp_right_hs_digit)
        {
            // Increase temp_left_hs_digit in case it's lower then rightHS_digit
            temp_left_hs_digit += 10;
            ++cash;
        }

        result[iter] = temp_left_hs_digit - temp_right_hs_digit;
    }

    // If there are still left digits from the left_hs_digits
    for (unsigned int iter = right_hs_digit_number; iter < left_hs_digit_number; ++iter)
    {
        if (cash > 0)
        {
            if (left_hs_digits[iter] > 0)
            {
                result[iter] = left_hs_digits[iter] - 1;
                --cash;
            }
            else
            {
                result[iter] = left_hs_digits[iter] + 10 - 1;
            }
        }
        else
        {
            result[iter] = left_hs_digits[iter];
        }
    }

#ifdef LOGGING
    // leftHS_Digits
    for (const unsigned int& digit : leftHS_Digits)
    {
        std::cout << digit;
    }
    std::cout << "\n";

    // rightHS_Digits
    for (const unsigned int& digit : rightHS_Digits)
    {
        std::cout << digit;
    }
    std::cout << "\n";

    // result
    for (const unsigned int& digit : result)
    {
        std::cout << digit;
    }
#endif

    // Combine into number
    std::string result_Number = common_library::combineIntoString(result);

    // Add sign
    if (result_is_negative)
    {
        result_Number.insert(0, "-");
    }

    return result_Number;
};

//-----------------------------------------------------------------------------

}