#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int x;
    cin>>x;

    vector<int>weights(n);

    for(int i = 0; i < n; i++){
        cin>>weights[i];
    }

    sort(weights.begin(), weights.end());

    int ans = 0;
    
    int i = 0;
    int j = 1;

    while(j < n){
        int val = weights[i] + weights[j];

        if(val <= x){
            ans++;
            i++;
            j++;
        }
        else if(weights[i] >= x){
            
        }
    }
}