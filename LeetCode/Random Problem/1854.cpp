/*
Problem Link - https://leetcode.com/problems/maximum-population-year/description/

Time = O(n);
Space - O(2051) == O(1)
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        vector<int>hash(2051, 0);

        for(int i = 0; i < logs.size(); i++){
            int birth = logs[i][0];
            int death = logs[i][1];

            hash[birth] += 1;
            hash[death] += -1;
        }

        int population = 0;
        int maxPopulation = 0;
        int yr = 0;

        for(int i = 1950; i < hash.size(); i++){
            population += hash[i];

            if(population > maxPopulation){
                maxPopulation = population;
                yr = i;
            }
        }
        return yr;
    }
};
