#include "stdafx.h"

//-----------------------------------------------------------------------------

//#define LOGGING

#include "../CommonLibrary/CommonLibrary.h"
#include "Grade-School.h"

#include <iostream>
#include <iomanip>
#include <string>

//-----------------------------------------------------------------------------


int main()
{
    const unsigned long long range = 1000000000000000000;

    //std::cout << "\n\n ---------------- Integer multiplication ---------------------\n";

    //srand(static_cast<unsigned int>(time(NULL)));
    //for (unsigned int iter = 0; iter < 1000; ++iter)
    //{
    //    unsigned int left = rand() % range + 1;
    //    unsigned int right = rand() % range + 1;

    //    const long long resultInt = grade_school::multiplyGradeSchool(left, right);

    //    if (resultInt != (left * right))
    //    {
    //        std::cout << "[" << iter << "] " 
    //            << left << " * " << right << " != " << resultInt << "\n"
    //            << "Correct: " << (left * right) << "\n";
    //    }
    //}
    
    std::cout << "\n\n ---------------- String multiplication ----------------------\n";

    srand(static_cast<unsigned int>(time(NULL)));
    for (unsigned int iter = 0; iter < 1000; ++iter)
    {
        unsigned int left = rand() % range + 1;
        unsigned int right = rand() % range + 1;
        std::string leftStr = std::to_string(left);
        std::string rightStr = std::to_string(right);

        const std::string resultStr = grade_school::multiplyGradeSchool(leftStr, rightStr);

        if (resultStr != std::to_string(left * right))
        {
            std::cout << "[" << iter << "] " 
                << left << " * " << right << " != " << resultStr << "\n"
                << "Correct: " << (left * right) << "\n";
        }
    }

    //std::cout << "\n\n ---------------- Integer summing ---------------------\n";

    //srand(static_cast<unsigned int>(time(NULL)));
    //for (unsigned int iter = 0; iter < 1000; ++iter)
    //{
    //    unsigned int left = rand() % range + 1;
    //    unsigned int right = rand() % range + 1;

    //    const long long resultInt = grade_school::sumGradeSchool(left, right);

    //    if (resultInt != (left + right))
    //    {
    //        std::cout << "[" << iter << "] "
    //            << left << " + " << right << " != " << resultInt << "\n"
    //            << "Correct: " << (left + right) << "\n";
    //    }
    //}

    //std::cout << "\n\n ---------------- String summing ----------------------\n";

    //srand(static_cast<unsigned int>(time(NULL)));
    //for (unsigned int iter = 0; iter < 1000; ++iter)
    //{
    //    unsigned int left = rand() % range + 1;
    //    unsigned int right = rand() % range + 1;
    //    std::string leftStr = std::to_string(left);
    //    std::string rightStr = std::to_string(right);

    //    const std::string resultStr = grade_school::sumGradeSchool(leftStr, rightStr);

    //    if (resultStr != std::to_string(left + right))
    //    {
    //        std::cout << "[" << iter << "] "
    //            << left << " + " << right << " != " << resultStr << "\n"
    //            << "Correct: " << (left + right) << "\n";
    //    }
    //}

    //std::cout << "\n\n ---------------- Integer subtraction ---------------------\n";

    //srand(static_cast<unsigned int>(time(NULL)));
    //for (unsigned int iter = 0; iter < 1000; ++iter)
    //{
    //    long long left = rand() % range + 1;
    //    long long right = rand() % range + 1;

    //    const long long resultInt = grade_school::subtractGradeSchool(left, right);

    //    if (resultInt != (left - right))
    //    {
    //        std::cout << "[" << iter << "] "
    //            << left << " - " << right << " != " << resultInt << "\n"
    //            << "Correct: " << (left - right) << "\n";
    //    }
    //}

    //std::cout << "\n\n ---------------- String subtraction ----------------------\n";

    //srand(static_cast<unsigned int>(time(NULL)));
    //for (unsigned int iter = 0; iter < 1000; ++iter)
    //{
    //    long long left = rand() % range + 1;
    //    long long right = rand() % range + 1;
    //    std::string leftStr = std::to_string(left);
    //    std::string rightStr = std::to_string(right);

    //    const std::string resultStr = grade_school::subtractGradeSchool(leftStr, rightStr);

    //    if (resultStr != std::to_string(left - right))
    //    {
    //        std::cout << "[" << iter << "] "
    //            << left << " - " << right << " != " << resultStr << "\n"
    //            << "Correct: " << (left - right) << "\n";
    //    }
    //}

    std::system("pause");
    return 0;
}

//-----------------------------------------------------------------------------