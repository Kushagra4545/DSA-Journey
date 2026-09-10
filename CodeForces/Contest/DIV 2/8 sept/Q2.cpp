#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;

    while(t--){
        long long x;
        cin>>x;
        long long y;
        cin>>y;
        long long k;
        cin>>k;

        long long count = 0;
        if(k == 0) {
            cout<<count<<endl;
            continue;
        }
        
        long long toAdd = y - 2LL * x;

        if(toAdd < 0){
            cout<<k * (y % x)<<endl;
            continue;
        }

        for(long long i = 0; i < min(toAdd, k); i++){
            count += y % x;
            y++;
            x++;
        }
        y++;
        x++;

        if(k <= toAdd){
            cout<<count<<endl;
            continue;
        }
        
        long long rem = k - toAdd - 1;

        long long val = y % x;

        count += (rem * val);
        cout<<count<<endl;
    }
}