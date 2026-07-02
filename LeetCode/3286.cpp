/*
Problem Link - https://leetcode.com/problems/find-a-safe-walk-through-a-grid/description/

Time - O(nmlog(nm))
Space - O(nm)
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int n = grid.size();
        int m = grid[0].size();

        int delRow[4] = {0, +1, 0, -1};
        int delCol[4] = {+1, 0, -1, 0};

        vector<vector<int>>safe(n, vector<int>(m, INT_MIN));

        priority_queue<
            pair<int, pair<int, int>>
        >pq;

        if(grid[0][0] == 1){
            health--;
        }
        
        pq.push({health, {0, 0}});
        safe[0][0] = health;

        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();

            int currHealth = it.first;
            int r = it.second.first;
            int c = it.second.second;

            if(r == n-1 && c == m-1){
                if(currHealth >= 1) {
                    return true;
                }
            }

            for(int i = 0; i < 4; i++){
                int newRow = r + delRow[i];
                int newCol = c + delCol[i];

                if(newRow >= 0 && newRow < n && newCol >= 0 && newCol < m ){
                    int newHealth = currHealth;

                    if(grid[newRow][newCol] == 1){
                        newHealth--;
                    }
                    if(newHealth <= 0){
                        continue;
                    }
                    if(newHealth > safe[newRow][newCol]){
                        safe[newRow][newCol] = max(safe[newRow][newCol], newHealth);
                        pq.push({newHealth, {newRow, newCol}});
                    }
                }
            }
        }
        return false;
    }
};