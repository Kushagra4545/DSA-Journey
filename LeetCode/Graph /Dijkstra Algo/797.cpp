/*
Problem Link = https://leetcode.com/problems/all-paths-from-source-to-target/
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();

        vector<vector<int>>ans;
        queue<pair<vector<int>, int>>q;

        q.push({{0}, 0});

        while(!q.empty()){
            auto it = q.front();
            q.pop();

            int node = it.second;
            vector<int>temp = it.first;

            if(node == n-1){
                ans.push_back(temp);
            }

            for(auto neigh : graph[node]){
                temp.push_back(neigh);
                q.push({temp, neigh});
                temp.pop_back();
            }
        }
        return ans;
    }
};