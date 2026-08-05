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
    int j = n-1;

    while(i <= j){
        int val1 = weights[i];
        int val2 = weights[j];

        if(i == j){
            ans += 1;
            break;
        }

        if(val1 + val2 <= x){
            ans += 1;
            i++;
            j--;
        }
        else if(val1 > val2){
            ans++;
            i++;
        }
        else{
            ans++;
            j--;
        }
    }
    cout<<ans<<endl;
}