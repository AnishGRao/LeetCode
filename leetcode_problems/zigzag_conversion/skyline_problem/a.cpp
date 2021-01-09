#include <bits/stdc++.h>
typedef double _d;
using namespace std;
/*
 * inputs come in left and right
 *  x coordinate values, not distance
 *  height is distance metric, not y coordinate
 *  want to return left endpoints of all horizontal lines created by overlaying all "buildings"
 *
 *
 *
 *
 *
 */

typedef struct
{
    int left;
    int right;
} coord;

std::vector<std::vector<int>> getSkyline(vector<vector<int>> & buildings)
{
    // given buildings, we first need to find points of overlapping.
    // buildings is already sorted by left coord
    std::vector<std::vector<int>> output;
    std::vector<std::pair<int, int>> events;
    std::multiset<int> heights;
    for (auto b : buildings)
    {
        //- to signify end of building
        events.push_back({b[0], -1 * b[2]});
        events.push_back({b[1], b[2]});
    }
    std::sort(events.begin(), events.end());
    int max = 0;
    heights.emplace(0);
    for (auto e : events)
    {
        if (e.second < 0)
            heights.emplace(-1 * e.second);
        else
            heights.erase(heights.find(e.second));
        if (*heights.rbegin() != max)
            output.push_back({e.first, *heights.rbegin()}), max = *heights.rbegin();
    }
    return output;
}

int main() {}
