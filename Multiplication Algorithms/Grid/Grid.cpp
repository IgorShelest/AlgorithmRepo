// Grid.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

//-----------------------------------------------------------------------------

#include <vector>
#include <iostream>
#include <iomanip>
#include <math.h>
#include "../CommonLibrary/CommonLibrary.h"

using namespace std;

//-----------------------------------------------------------------------------

// -----------------
// | X  | 30  | 4  |
// -----------------
// | 10 | 300 | 40 |
// -----------------
// | 3  | 90  | 12 |
// -----------------

//-----------------------------------------------------------------------------

unsigned int multiplyGrig(const unsigned int& leftHS, const unsigned int& rightHS)
{
    // Numbers of digits
    const unsigned int leftHS_digitNumber = common_library::getDigitNumber(leftHS);
    const unsigned int rightHS_digitNumber = common_library::getDigitNumber(rightHS);

    // Vectors of class numbers
    const std::vector<unsigned int> leftHS_Classes = common_library::devideIntoClasses(leftHS, leftHS_digitNumber);
    const std::vector<unsigned int> rightHS_Classes = common_library::devideIntoClasses(rightHS, rightHS_digitNumber);

    // Multiplication of class number vectors
    vector< vector<unsigned int> > table(leftHS_digitNumber, vector<unsigned int>(rightHS_digitNumber));

    for (unsigned int leftIter = 0; leftIter < leftHS_digitNumber; ++leftIter)
    {
        for (unsigned int rightIter = 0; rightIter < rightHS_digitNumber; ++rightIter)
        {
            table[leftIter][rightIter] = leftHS_Classes[leftIter] * rightHS_Classes[rightIter];
        }
    }

    // Adding of multiplied table results
    unsigned int result = 0;

    for (unsigned int leftIter = 0; leftIter < leftHS_digitNumber; ++leftIter)
    {
        for (unsigned int rightIter = 0; rightIter < rightHS_digitNumber; ++rightIter)
        {
            result += table[leftIter][rightIter];
        }
    }

    return result;
};

//-----------------------------------------------------------------------------

int main()
{

    for (unsigned int leftIter = 0; leftIter < 25; ++leftIter)
    {
        for (unsigned int rightIter = 0; rightIter < 25; ++rightIter)
        {
            if ((leftIter * rightIter) != multiplyGrig(leftIter, rightIter))
            {
                cout << "\nTest " << leftIter << ":" << rightIter << " = " << (leftIter * rightIter) << " != " << multiplyGrig(leftIter, rightIter);
            }
        }
    }


    std::system("pause");
    return 0;
}

