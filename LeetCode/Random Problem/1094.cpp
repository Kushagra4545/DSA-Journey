/*
Problem Link - https://leetcode.com/problems/car-pooling/description/

Time = O(n);
Space = O(n);
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int maxi = INT_MIN;
        for(int i = 0; i < trips.size(); i++){
            maxi = max(maxi, trips[i][2]);
        }

        vector<int>hash(maxi + 2, 0);

        for(int i = 0; i < trips.size(); i++){
            int numPassengers = trips[i][0];
            int start = trips[i][1];
            int dest = trips[i][2];

            hash[start] += numPassengers;
            hash[dest] += (-1 * numPassengers);
        }
        int sum = 0;
        for(int i = 0; i < hash.size(); i++){
            sum += hash[i];
            if(sum > capacity){
                return false;
            }
        }
        return true;
    }
};