#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    void moveZeroes(vector<int> &a)
    {
        int i = 0;
        for (int k = 0; k < a.size(); k++)
        {
            if (a[k] != 0)
            {
                swap(a[i], a[k]);
                i++;
            }
        }
    }
};