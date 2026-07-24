/*
Problem Link - https://leetcode.com/problems/corporate-flight-bookings/description/

Time - O(n);
Space - O(n);
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int>hash(n, 0);
        for(int i = 0; i < bookings.size(); i++){
            int first = bookings[i][0]-1;
            int last = bookings[i][1] -1;

            int seat = bookings[i][2];

            for(int j = first; j <= last; j++){
                hash[j] += seat;
            }
        }
        return hash;
    }
    //Difference Array
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int>hash(n+1, 0);
        for(int i = 0; i < bookings.size(); i++){
            int first = bookings[i][0] - 1;
            int last = bookings[i][1];

            int seat = bookings[i][2];

            hash[first] += seat;
            hash[last] += (-1 * seat);
        }

        int sum = 0;
        for(int i = 0; i <= n; i++){
            sum += hash[i];
            hash[i] = sum;
        }
        hash.pop_back();
        return hash;
    }
};