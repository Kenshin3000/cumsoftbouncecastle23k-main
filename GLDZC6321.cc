/*
QUESTION TWO - Tipping point

PLEASE READ THIS SECTION IN ITS ENTIRETY!

You are given a vector of integers X, and an integer Y. Y is an index of X and is bound by [0 - X.size()).
X has a tipping point, that being a location at which the vector of integers is balanced. This location is the index in the vector at which all the numbers to the left
are equal in sum to all the numbers to the right of this index. Note, the sum does not include the integer at the index.

For example, if X is defined as {-2, 4, 0, -5, 7}, then the tipping point is 2, which is the index in X that corresponds to the number 0. 

We define a tipping point as the location at which, if we were to increment the integer at the location Y, X will no longer be balanced. 

If incrementing the integer at index Y would 'tip' (lead to the unbalancing of) X, return true. If incrementing the integer at Y would not lead to a 'tip', then return false.
The vector of integers X may not have a balancing point. If it doesn't, then it also doesn't have a tipping point. In this case, return false.

For example,
X: {-10, -12, 4, 22} Y: 2 -> false (No tipping point. The two numbers to the left of index 2 add up to -22, the number to the right of index 2 is 22, -22 is not equal to 22. Hence, the vector is not balanced to begin with)
X: {-10, -12, 0, -22} Y: 3 -> true (Tipping point at index 2, incrementing the number at index 3 will tip the vector)
X: {-10, -12, 0, -22} Y: 0 -> true (Tipping point at index 2, incrementing the number at index 0 will tip the vector)
X: {-1, -1, -1} Y: 2 -> true (Tipping point at index 1, incrementing the number at index 2 will tip the vector)
X: {-1, 0, 1} Y: 1 -> false (No tipping point)

Your answer will be run against a suite of test cases; please consider all potential scenarios.
For example, if X.size() == 0, return false.

Your solution must conform to the following function signature:

bool IsTippingPoint(const std::vector<int>& numbers, int index);

Additional information:
 - Please include any helper methods that you write as lambdas in IsTippingPoint(const std::vector<int>&, int). 
 - Only the content of the IsTippingPoint(const std::vector<int>&, int) method will be copied from Rextester.
 - Your code will be run against a MSVC compiler (C++17)
 - If you need to make any assumptions, please include them as a comment in the method.
 - Assume that STL is available to be used.
 - We recommend you write your code in an IDE of your choice (Visual Studio 2019 is preferred, but not required) before pasting your answer down below.

Once you are done, please click "Fork it", and paste the corresponding link into the FlexiQuiz response section associated with this question.
*/

bool IsTippingPoint(const std::vector<int>& numbers, int index)
{
    // Write your code here.
     // Assumptions:
    // When numbers has more than 1 tipping points, incrementing the number
    // at index must break the balance for at least 1 tipping point
    // For example:
    // X: {-1, 0, 0, -1}  Y: 1   -> true
    // Tipping points at index 1,2.
    // Incrementing the number at index 1 will tip the vector for tipping point 2

    int N = numbers.size();
    if (N == 0) return false;
    if (N == 1) return false;

    vector<int> v1(N);
    vector<int> v2(N);

    v1[0] = numbers[0];
    for (int i = 1 ; i < N; i++) {
        v1[i] = v1[i-1] + numbers[i];
    }
    v2[N-1] = numbers[N-1];
    for (int i = N-2 ; i >= 0; i--) {
        v2[i] = v2[i+1] + numbers[i];
    }

//    // print sum vectors
//    for (int i = 0 ; i < N; i++) {
//        printf("%5d ", v1[i]);
//    }
//    cout << endl;
//    for (int i = 0 ; i < N; i++) {
//        printf("%5d ", v2[i]);
//    }
//    cout << endl;
//    // ===================================

    // find tipping point
    vector<int> t;
    for (int i = 0 ; i < N; i++) {
        if (i == 0 && v2[i+1] == 0)
            t.push_back(i);
        else if (v1[i-1] == v2[i+1])
            t.push_back(i);
        else if (i == N-1 && v1[i-1] == 0)
            t.push_back(i);
    }

//    // print tipping points
//    cout << "tipping points: " ;
//    for (auto &i: t)
//        cout << i << " ";
//    cout << endl;
//    cout << "==============" << endl;

    if (t.empty()) return false; // no tipping points
    else if (t.size() == 1) {  // there is only 1 tipping point
        if (index != t[0])
            return true;    // index is not the tipping point
        else
            return false;   // index is the tipping point

    }
    else {
        // numbers has more than 1 tipping points, then incrementing the number
        // at index must break the balance for at least 1 tipping point
        return true;
    }

    return true;
}
