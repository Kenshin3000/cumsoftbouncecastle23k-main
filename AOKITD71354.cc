#include <vector>
#include <cassert>
#include <stdexcept>
#include <iostream>
#include <numeric>

bool IsTippingPoint(const std::vector<int> &numbers, int index)
{
    if (numbers.size() == 0)
    {
        return false;
    }

    // Since the sum does not include the integer at the index, this will never unbalance the vector (i.e. 0 vs 0)
    if (numbers.size() == 1)
    {
        return false;
    }

    if (index >= numbers.size() || index < 0)
    {
        throw std::out_of_range("Index is out of range");
    }

    // Assume that int64_t is not going to be overflow for practical use cases
    std::int64_t leftSum = 0;
    std::int64_t rightSum = std::accumulate(numbers.begin(), numbers.end(), 0);
    int currentElement = 0;

    for (std::size_t i = 0; i < numbers.size(); ++i)
    {
        currentElement = numbers[i];
        rightSum -= currentElement;
        if (leftSum == rightSum)
        {
            // The only case where incrementing a value would not tip the vector
            // is when incrementing the tipping point itself. All other points
            // are tipping points.The method name is already aptly named
            // `IsTippingPoint`
            return i != index;
        }
        leftSum += currentElement;
    }

    return false;
}

int main()
{
    assert(!IsTippingPoint({-10, -12, 4, 22}, 2));
    assert(IsTippingPoint({-10, -12, 0, -22}, 3));
    assert(IsTippingPoint({-10, -12, 0, -22}, 0));
    assert(IsTippingPoint({-1, -1, -1}, 2));
    assert(!IsTippingPoint({-1, 0, 1}, 1));
    std::cout << "OK" << std::endl;
    return 0;
}
