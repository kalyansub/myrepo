// Find the nth largest numbers in a given list  

#include <iostream>
#include <algorithm>
#include <vector>

struct Pred
{
    Pred(int nth) : m_nth(nth) {};
    bool operator()(int k) { return k >= m_nth; }
    int m_nth;
};

int main()
{
    int n = 4;
    std::vector<int> v = {5, 12, 27, 9, 4, 7, 2, 1, 8, 13, 1};

    // Moves the nth element to the nth from the end position.
    std::nth_element(v.begin(), v.end() - n, v.end());

    // Reorders the range, so that the first n elements would be >= nth.
    std::partition(v.begin(), v.end(), Pred(*(v.end() - n)));

    int c = 0;
    for (auto it = v.begin(); it != v.end(); ++it, ++c)
    {
        if ( c == n) break;
        std::cout << *it << " ";
    }
    std::cout << "\n";

    return 0;
}
