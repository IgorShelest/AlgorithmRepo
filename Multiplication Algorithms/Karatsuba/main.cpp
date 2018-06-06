#include "stdafx.h"

//-----------------------------------------------------------------------------

#include <iostream>
#include <iomanip>
#include <math.h>
#include <string>

//-----------------------------------------------------------------------------

#include "Karatsuba.h"
#include "../CommonLibrary/CommonLibrary.h"

//-----------------------------------------------------------------------------

const long long g_range = 1000000000000000000;

//-----------------------------------------------------------------------------

int main()
{

    //srand(static_cast<unsigned int>(time(NULL)));
    //for (unsigned int iter = 0; iter < 1000; ++iter)
    //{
    //    long long left = rand() % g_range + 1;
    //    long long right = rand() % g_range + 1;

    //    const long long resultInt = KaratsubaMultiplication(left, right);
    //    if (resultInt != (left * right))
    //    {
    //        std::cout << "[" << iter << "] "
    //            << left << " * " << right << " != " << resultInt << "\n"
    //            << "Correct int: " << (left * right) << "\n";
    //    }
    //    
    //    const std::string resultStr = KaratsubaMultiplication(std::to_string(left), std::to_string(right));
    //    if (resultStr != std::to_string(left * right))
    //    {
    //        std::cout << "[" << iter << "] "
    //            << left << " * " << right << " != " << resultStr << "\n"
    //            << "Correct str: " << (left * right) << "\n";
    //    }
    //}





    const std::string leftHS = "3141592653589793238462643383279502884197169399375105820974944592";
    const std::string rightHS = "2718281828459045235360287471352662497757247093699959574966967627";
    const std::string result = KaratsubaMultiplication(leftHS, rightHS);
    std::cout << "Result: " << result << "\n";

    
    system("pause");
    return 0;
}