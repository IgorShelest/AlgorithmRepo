// Karatsuba.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

//-----------------------------------------------------------------------------

#include <iostream>
#include <iomanip>
#include <math.h>
#include <string>

//-----------------------------------------------------------------------------

#include "../Grade-School/Grade-School.h"
#include "../CommonLibrary/CommonLibrary.h"
#include "../Recursive integer multiplication/Recursive.h"

//-----------------------------------------------------------------------------

/*
 *  [Part 1]
 *     x * y
 *     Where:
 *        x = x1 * B^m + x0
 *        y = y1 * B^m + y0
 *
 *  [Part 2]
 *     x * y = z2 * B^2m + z1 * B^m + z0
 *     Where:
 *        z2 = x1 * y1
 *        z1 = t0 * t1 - z2 - z0           Or          z1 = x1 * y0 + x0 * y1
 *        z0 = x0 * y0
 *
 *        Where:
 *           t0 = x1 + x0
 *           t1 = y1 + y0
*/

//-----------------------------------------------------------------------------

long long KaratsubaMultiplication(long long leftHS, long long rightHS)
{
    const unsigned int leftHS_NumOfDigits = static_cast<unsigned int>(common_library::getDigitNumber(leftHS));
    const unsigned int rightHS_NumOfDigits = static_cast<unsigned int>(common_library::getDigitNumber(rightHS));
    long long result = 0;

    try 
    {
        if (leftHS_NumOfDigits > 1 && rightHS_NumOfDigits > 1)
        {
            /* [Part 1] */
            const unsigned int B = 10;
            const unsigned int m = common_library::min(leftHS_NumOfDigits, rightHS_NumOfDigits) / 2;

            const unsigned int x1 = static_cast<unsigned int> (leftHS / std::pow(10, m));
            const unsigned int y1 = static_cast<unsigned int> (rightHS / std::pow(10, m));

            const unsigned int x0 = leftHS % static_cast<unsigned int> (std::pow(10, m));
            const unsigned int y0 = rightHS % static_cast<unsigned int> (std::pow(10, m));

            /* [Part 2] */
            const long long z2 = KaratsubaMultiplication(x1, y1);

            const long long z0 = KaratsubaMultiplication(x0, y0);

            const unsigned int t0 = x1 + x0;
            const unsigned int t1 = y1 + y0;
            const long long z1 = KaratsubaMultiplication(t0, t1) - z2 - z0;

            result = grade_school::multiplyGradeSchool(z2, static_cast<long long>(std::pow(B, 2 * m)))
                     + grade_school::multiplyGradeSchool(z1, static_cast<long long>(std::pow(B, m)))
                     + z0;
        }
        else
        {
            result = grade_school::multiplyGradeSchool(leftHS, rightHS);
        }
    }
    catch (std::exception const& e)
    {
        std::cout << "Exception in KaratsubaMultiplication()\n"
                  << "Message: " << e.what()         << "\n"
                  << "Type: "    << typeid(e).name() << "\n";
    }

    return result;
};

//-----------------------------------------------------------------------------

std::string KaratsubaMultiplication(const std::string& leftHS, const std::string& rightHS)
{
    const unsigned int leftHS_NumOfDigits = leftHS.length();
    const unsigned int rightHS_NumOfDigits = rightHS.length();
    std::string result;

    try
    {
        if ((leftHS_NumOfDigits > 1) && (rightHS_NumOfDigits > 1))
        {
            /* [Part 1] */
            const unsigned int B = 10;
            const unsigned int m = common_library::min(leftHS_NumOfDigits, rightHS_NumOfDigits) / 2;

            const unsigned int x1_StartPos = 0;
            const unsigned int temp = static_cast<unsigned int>(common_library::getDigitNumber(common_library::pow(std::to_string(10), std::to_string(m))));
            const unsigned int x1_DigitNumber = leftHS_NumOfDigits - temp + 1;
            const std::string x1 = leftHS.substr(x1_StartPos, x1_DigitNumber);

            const unsigned int y1_StartPos = 0;
            const unsigned int y1_DigitNumber = rightHS_NumOfDigits - static_cast<unsigned int>(common_library::getDigitNumber(common_library::pow(std::to_string(10), std::to_string(m)))) + 1;
            const std::string y1 = rightHS.substr(y1_StartPos, y1_DigitNumber);

            const unsigned int x0_StartPos = x1_DigitNumber;
            const unsigned int x0_DigitNumber = static_cast<unsigned int>(common_library::getDigitNumber(common_library::pow(std::to_string(10), std::to_string(m)))) - 1;
            const std::string x0 = leftHS.substr(x0_StartPos, x0_DigitNumber);

            const unsigned int y0_StartPos = y1_DigitNumber;
            const unsigned int y0_DigitNumber = static_cast<unsigned int>(common_library::getDigitNumber(common_library::pow(std::to_string(10), std::to_string(m)))) - 1;
            const std::string y0 = rightHS.substr(y0_StartPos, y0_DigitNumber);

            /* [Part 2] */
            const std::string z2 = grade_school::multiplyGradeSchool(x1, y1);

            const std::string z0 = grade_school::multiplyGradeSchool(x0, y0);

            const std::string t0 = grade_school::sumGradeSchool(x1, x0);
            const std::string t1 = grade_school::sumGradeSchool(y1, y0);
            const std::string z1 = grade_school::subtractGradeSchool( grade_school::subtractGradeSchool(grade_school::multiplyGradeSchool(t0, t1), z2), z0 );
            
            const std::string z2_multiplication = grade_school::multiplyGradeSchool(z2, common_library::pow(std::to_string(B), std::to_string(2 * m)));
            const std::string z1_multiplication = grade_school::multiplyGradeSchool(z1, common_library::pow(std::to_string(B), std::to_string(m)));
            const std::string z2_z1_multiplication_sum = grade_school::sumGradeSchool(z2_multiplication, z1_multiplication);

            result = grade_school::sumGradeSchool(z2_z1_multiplication_sum, z0);
        }
        else
        {
            result = grade_school::multiplyGradeSchool(leftHS, rightHS);
        }
    }
    catch (std::exception const& e)
    {
        std::cout << "Exception in KaratsubaMultiplication()\n"
            << "Message: " << e.what() << "\n"
            << "Type: " << typeid(e).name() << "\n";
    }

    return result;
};

//-----------------------------------------------------------------------------



