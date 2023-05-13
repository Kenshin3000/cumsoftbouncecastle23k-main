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
    if(numbers.size() < 3)
	return false;
	
    if(index >= numbers.size() or index < 0)
	return false;
	
    auto balancePoint =  [](vector<int> const& vec)
    {
        vector<int> prefixSum(vec.size(), 0);
	vector<int> postfixSum(vec.size(), 0);
	
	prefixSum[0] = vec[0];
	for(size_t i=1; i<vec.size(); ++i)
	    prefixSum[i] = prefixSum[i-1] + vec[i];
	
	auto len = vec.size();
	postfixSum[len-1] = vec[len-1];	
	for(int i = len-2; i >= 0; --i)
	{
	    postfixSum[i] = postfixSum[i+1] + vec[i];
	}
	
	for(size_t i=1; i<vec.size()-1; ++i)
	    if(prefixSum[i-1] == postfixSum[i+1])
	        return i;
		
	return len;
    };

	
    auto balanceIndex = balancePoint(numbers);
	
    //case where there is no tippingpoint
    if(balanceIndex > numbers.size()-1)
        return false;
	
    if(balanceIndex == index)
        return false;
	
    return true;
}

int main()
{
	vector<int> test1{-10, -12, 0, -22};
	cout<<"would tip = " <<(IsTippingPoint( test1,2) == true ? "true":"false") << "\n";
}
