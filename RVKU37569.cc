/*
QUESTION ONE - Power of three

PLEASE READ THIS SECTION IN ITS ENTIRETY!

Given an integer, return whether it is a power of three.

number: 3 -> true
number: 81 -> true
number: 5 -> false

Your solution must conform to the following function signature:

bool IsPowerOfThree(int number);

Additional information:
 - Please include any helper methods that you write as lambdas in IsPowerOfThree(int number). 
 - Only the content of the IsPowerOfThree(int number) method will be copied from Rextester.
 - Your code will be run against a MSVC compiler (C++17)
 - If you need to make any assumptions, please include them as a comment in the method.
 - Assume that STL is available to be used.
 - We recommend you write your code in an IDE of your choice (Visual Studio 2019 is preferred, but not required) before pasting your answer down below.

Once you are done, please click "Fork it", and paste the corresponding link into the FlexiQuiz response section associated with this question.
*/
#include <cmath>
bool IsPowerOfThree(int number)
{
    // Write your code here.
    double p = log10(number) / log10(3);
    if (p - (int)p == 0)
        return true;
    
    return false;
}
