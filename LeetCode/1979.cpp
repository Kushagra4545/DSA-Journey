/*
Problem Link = https://leetcode.com/problems/find-greatest-common-divisor-of-array/description/

Time - O(n);
Space - O(1);
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findGCD(vector<int>& nums) {
        int smallest = *min_element(nums.begin(), nums.end());
        int largest = *max_element(nums.begin(), nums.end());

        return __gcd(smallest, largest);
    }
};