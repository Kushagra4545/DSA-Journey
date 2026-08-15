#include<bits/stdc++.h>
using namespace std;

void dfs(int node, vector<vector<int>>& adjList, vector<int>& visited){
    visited[node] = 1;

    for(auto it : adjList[node]){
        if(!visited[it]){
            dfs(it, adjList, visited);
        }
    }
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

    vector<int>pairs;
    int count = 0;

    for(int i = 1; i <= n; i++){
        if(!visited[i]){
            pairs.push_back(i);
            dfs(i, adjList, visited);
            count++;
        }
    }

    if(count == 0){
        cout<<0<<endl;
        return 0;
    }

    cout<<count-1<<endl;
    for(int i = 1; i < pairs.size(); i++){
        int u = pairs[i];
        int v = pairs[i-1];

        cout<<v<<" "<<u<<endl;
    }
}