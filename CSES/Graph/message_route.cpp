#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int m;
    cin>>m;

    vector<vector<int>>edges(m, vector<int>(2));

    for(int i = 0; i < m; i++){
        cin>>edges[i][0]>>edges[i][1];
    }

    vector<vector<int>>adjList(n+1);

    for(int i = 0; i < m; i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    vector<int>visited(n+1, 0);
    vector<int>parent(n+1, -1);

    queue<pair<int, int>>q;
    q.push({0, 1});
    visited[1] = 1;
    parent[1] = -1;

    int distance = -1;

    while(!q.empty()){
        auto it = q.front();
        q.pop();

        int dist = it.first;
        int node = it.second;

        if(node == n){
            distance = dist;
            break;
        }

        for(auto neigh : adjList[node]){
            if(!visited[neigh]){
                q.push({dist + 1, neigh});
                parent[neigh] = node;
                visited[neigh] = 1;
            }
        }
    }

    if(!visited[n]){
        cout<<"IMPOSSIBLE"<<endl;
        return 0;
    }

    vector<int>path;
    int stNode = n;

    while(stNode != -1){
        path.push_back(stNode);
        stNode = parent[stNode];
    }

    reverse(path.begin(), path.end());

    cout<<distance + 1<<endl;
    for(int i = 0; i < path.size(); i++){
        cout<<path[i]<<" ";
    }

}