/*
Problem Link - https://leetcode.com/problems/path-with-maximum-probability/description/

Time = O(m log(n));
Space = O(n) + O(m) + O(n + m) ; 

n -> number of node
m -> number of edges
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<vector<pair<int, double>>>adjList(n);

        for(int i = 0; i < edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            double w = succProb[i];

            adjList[u].push_back({v, w});
            adjList[v].push_back({u, w});
        }

        vector<double>prob(n, INT_MIN);

        priority_queue<
            pair<double, int>
        >pq;

        pq.push({1.0, start_node});
        prob[start_node] = 1.0;

        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();

            int node = it.second;
            double probability = it.first;

            if(node == end_node) {
                return probability;
            }

            for(auto neigh : adjList[node]){
                int newNode = neigh.first;
                double weight = neigh.second;

                double newProb = weight * probability;

                if(prob[newNode] < newProb){
                    prob[newNode] = newProb;
                    pq.push({newProb, newNode});
                }
            }
        }
        if(prob[end_node] == INT_MIN) return 0;

        return prob[end_node];
    }
};

