#pragma once

//-----------------------------------------------------------------------------

#include <string>

//-----------------------------------------------------------------------------

#include "../Grade-School/Grade-School.h"
#include "../CommonLibrary/CommonLibrary.h"

//-----------------------------------------------------------------------------

namespace recursive_multiplication
{

//-----------------------------------------------------------------------------

std::string recursiveMultiplication(const std::string& leftHS, const std::string& rightHS)
{
    std::string tempLeftHS = leftHS;
    std::string tempRightHS = rightHS;

    if (common_library::isLess(leftHS, std::to_string(0))) return recursiveMultiplication(tempLeftHS.erase(0, 1), rightHS).insert(0, "-");
    if (common_library::isLess(rightHS, std::to_string(0))) return recursiveMultiplication(tempLeftHS, tempRightHS.erase(0, 1)).insert(0, "-");
    if (common_library::areEqual(leftHS, std::to_string(0)) || common_library::areEqual(rightHS, std::to_string(0))) return std::to_string(0);

    return grade_school::sumGradeSchool(rightHS, recursiveMultiplication(grade_school::subtractGradeSchool(leftHS, std::to_string(1)), rightHS));
};

//-----------------------------------------------------------------------------

template <typename SomeType>
SomeType recursiveMultiplication(SomeType leftHS, SomeType rightHS)
{
    long long result = 0;

    try
    {
        if (leftHS < 0)  return -recursiveMultiplication(-leftHS, rightHS);
        if (rightHS < 0) return -recursiveMultiplication(leftHS, -rightHS);
        if (leftHS == 0 || rightHS == 0) return 0;

        result = rightHS + recursiveMultiplication(--leftHS, rightHS);
    }
    catch (std::exception const& e)
    {
        std::cout << "Exception in recursiveMultiplication(SomeType leftHS, SomeType rightHS)\n"
            << "Message: " << e.what() << "\n"
            << "Type: " << typeid(e).name() << "\n";
    }

    return result;
};

//-----------------------------------------------------------------------------

}