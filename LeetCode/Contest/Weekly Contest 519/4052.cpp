#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> cyclicShift(int n, vector<vector<int>>& grid, vector<int>& rowShift, vector<int>& colShift) {
        
        for(int i = 0; i < n; i++){
            int k = rowShift[i];

            reverse(grid[i].begin(), grid[i].begin() + k);
            reverse(grid[i].begin() + k, grid[i].end());
            reverse(grid[i].begin(), grid[i].end());

        }

        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                swap(grid[i][j], grid[j][i]);
            }
        }

        for(int i = 0; i < n; i++){
            int k = colShift[i];

            reverse(grid[i].begin(), grid[i].begin() + k);
            reverse(grid[i].begin() + k, grid[i].end());
            reverse(grid[i].begin(), grid[i].end());
        }

        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                swap(grid[i][j], grid[j][i]);
            }
        }
        return grid;
    }
};