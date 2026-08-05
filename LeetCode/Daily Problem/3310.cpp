/*
Problem Link - https://leetcode.com/problems/remove-methods-from-project/description/

Time - O((V + E)logV)
Space - O(V + E)
*/
/*
This can be took down to O(V + E) by using a vector<bool>isSus which boils down the time of searching to O(1);
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(int node, vector<vector<int>>& adjList, vector<int>& visited, vector<int>& sus){
        visited[node] = 1;
        sus.push_back(node);

        for(auto it : adjList[node]){
            if(!visited[it]){
                dfs(it, adjList, visited, sus);
            }
        }
    }
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>>adjList(n);

        for(auto it : invocations){
            int u = it[0];
            int v = it[1];

            adjList[u].push_back(v);
        }

        vector<int>sus;

        vector<int>visited(n, 0);
        dfs(k, adjList, visited, sus);

        if(sus.size() == n){
            return {};
        }

        unordered_map<int, int>susMpp;
        for(auto it : sus){
            susMpp[it]++;
        }

        bool isReachable = false;

        for(int i = 0; i < adjList.size(); i++){
            if(susMpp.find(i) != susMpp.end()){
                continue;
            }

            for(int j = 0; j < adjList[i].size(); j++){
                int node = adjList[i][j];

                if(susMpp.find(node) != susMpp.end()){
                    isReachable = true;
                    break;
                }
            }
        }
        vector<int>ans;

        if(isReachable == true){
            for(int i = 0; i < n; i++){
                ans.push_back(i);
            }
        }
        else{
            for(int i =0 ; i < n; i++){
                if(susMpp.find(i) != susMpp.end()){
                    continue;
                }
                ans.push_back(i);
            }
        }
        return ans;
    }
};
