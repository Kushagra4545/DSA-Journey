#include<bits/stdc++.h>
using namespace std;

bool dfs(int node, vector<vector<int>>& adjList, vector<int>& visited, int papa, vector<int>& parent, vector<int>& cycle){
    visited[node] = 1;
    parent[node] = papa;

    for(auto it : adjList[node]){
        if(!visited[it]){
            if(dfs(it, adjList, visited, node, parent, cycle)){
                return true;
            }
        }
        else if(papa != it){
            cycle.push_back(it);

            int curr = node;

            while(curr != it){
                cycle.push_back(curr);
                curr = parent[curr];
            }
            cycle.push_back(it);
            return true;
        }
    }
    return false;
}

int main(){
    int n;
    cin>>n;
    int m;
    cin>>m;

    vector<vector<int>>adjList(n+1);

    for(int i = 0; i < m; i++){
        int u, v;
        cin>>u>>v;

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    vector<int>visited(n+1, 0);
    vector<int>parent(n+1, -1);
    vector<int>cycle;
    for(int i = 1; i <= n; i++){
        if(!visited[i]){
            if(dfs(i, adjList, visited, -1, parent, cycle)){
                break;
            }
        }
    }

    if(cycle.size() == 0){
        cout<<"IMPOSSIBLE"<<endl;
        return 0;
    }
    cout<<cycle.size()<<endl;
    for(auto it : cycle){
        cout<<it<<" ";
    }
    return 0;
}