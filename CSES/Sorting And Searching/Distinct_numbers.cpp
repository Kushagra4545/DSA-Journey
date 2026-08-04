#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);

    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    sort(nums.begin(), nums.end());

    int count = 0;
    int prev = -1;
    for (int i = 0; i < n; i++)
    {
        if (prev != nums[i])
        {
            count++;
        }
        prev = nums[i];
    }
    cout << count;
}