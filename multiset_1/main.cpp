#include <iostream>
#include <vector>
#include <set>

using namespace std;

vector<int> smallestRange(vector<vector<int>>& nums)
{

    multiset<pair<int, pair<int, int>>> s;

    int k = nums.size();


    for (int i = 0; i < k; i++)
    {
        s.insert({nums[i][0], {i, 0}});
    }

    int start = -1e5, end = 1e5;

    while (true)
    {

        int min_val = s.begin()->first;
        int max_val = s.rbegin()->first;


        if (max_val - min_val < end - start)
        {
            start = min_val;
            end = max_val;
        }


        int list_idx = s.begin()->second.first;
        int elem_idx = s.begin()->second.second;


        if (elem_idx + 1 == nums[list_idx].size())
        {
            break;
        }


        s.erase(s.begin());
        s.insert({nums[list_idx][elem_idx + 1], {list_idx, elem_idx + 1}});
    }

    return {start, end};
}

int main()
{
    vector<vector<int>> nums =
    {
        {0, 10, 15, 24, 26},
        {4, 9, 12, 20},
        {5, 18, 22, 30}
    };

    vector<int> result = smallestRange(nums);

    cout << "Smallest Range: [" << result[0] << ", " << result[1] << "]" << endl;

    return 0;
}
