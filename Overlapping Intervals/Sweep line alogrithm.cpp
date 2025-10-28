#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int sweepLine(vector<vector<int>> &intervals)
{
    vector<pair<int, int>> events;
    for (auto &it : intervals)
    {
        int L = it[0];
        int R = it[1];
        events.push_back({L, +1}); // Start
        events.push_back({R, -1}); // End
    }
    // Necessary to handle same point events correctly even if it done by default
    sort(events.begin(), events.end(),
         [](auto &a, auto &b)
         {
             if (a.first == b.first)
                 return a.second < b.second; // End (-1) before Start (+1)
             return a.first < b.first;
         });
    int active = 0, result = 0;
    for (auto &e : events)
    {
        active += e.second;
        result = max(result, active);
    }
    return result;
}
int main()
{
    vector<vector<int>> intervals = {{1, 3}, {2, 4}, {5, 7}, {6, 8}};
    cout << "Maximum overlapping intervals: " << sweepLine(intervals) << endl;
    return 0;
}
