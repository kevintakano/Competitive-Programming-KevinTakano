
// CPP program to illustrate
// std :: lower_bound
#include <bits/stdc++.h>

// Driver code
int main()
{
    std::vector<int> v{ 2,3,5,6 };

    // Print vector
    std::cout << "Vector contains :";
    for (unsigned int i = 0; i < v.size(); i++)
        std::cout << " " << v[i];
    std::cout << "\n";

    std::vector<int>::iterator low1, low2, low3, low4;

    // std :: lower_bound
    low1 = std::lower_bound(v.begin(), v.end(), 5);

    std::cout << "\nlower_bound for element  at position : " << (low1 - v.begin());
    std::cout << "\nlower_bound for element  at position : " << (low2 - v.begin());
    std::cout << "\nlower_bound for element  at position : " << (low3 - v.begin());
    std::cout << "\nlower_bound for element  at position : " << (low4 - v.begin());
    std::cout << "\nlower_bound for element  at position : " << (v.begin() - v.begin());

    return 0;
}

