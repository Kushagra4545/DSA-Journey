#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long t;
    cin>>t;
    while(t--){
        long long n;
        cin>>n;
        vector<long long>nums(n);
        for(long long i = 0; i < n; i++){
            cin>>nums[i];
        }

        map<long long, long long>mpp;

        for(auto it : nums){
            mpp[it]++;
        }

        long long maxFreq = INT_MIN;

        for(auto it : mpp){
            long long freq = it.second;
            maxFreq = max(maxFreq, freq);
        }
        if(maxFreq == n){
            cout<<0<<endl;
            continue;
        }
        long long count = 0;
        while(2*maxFreq <= n){
            count = count + 1 + maxFreq;
            maxFreq = maxFreq * 2;
        }

        if(maxFreq < n){
            count += n - maxFreq + 1;
        }
        cout<<count<<endl;
    }
}