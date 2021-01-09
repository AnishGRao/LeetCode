#include <bits/stdc++.h>
typedef double _d;
using namespace std;

int climbStairs(int n)
{
    // integer overflow if int for n>=45.
    ulong steps[2];
    ++(steps[1] = (steps[0] = 1));
    --(--n);

    while (n > 0)
    {
        steps[0] = steps[1] + steps[0];
        steps[1] = steps[1] + steps[0];
        --(--n);
    }

    return n == 0 ? (int)steps[1] : n == -1 ? (int)steps[0] : 0;
}

int main()
{
    std::cout << climbStairs(45);
    return 0;
}