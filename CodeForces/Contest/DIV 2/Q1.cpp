#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;
        vector<int>nums(n);
        for(int i = 0; i < n; i++){
            cin>>nums[i];
        }

        map<int, int>mpp;

        for(auto it : nums){
            mpp[it]++;
        }

        int score = 0;

        int maxFreq = INT_MIN;

        for(auto it : mpp){
            maxFreq = max(maxFreq, it.second);
        }
        if(maxFreq <= n - maxFreq + 1){
            cout<<accumulate(nums.begin(), nums.end(), 0)<<endl;
            continue;
        }
        while(mpp.size() > 1){
            for(auto it = mpp.begin(); it != mpp.end(); ){
                score += it->first;
                it->second--;

                if(it->second == 0){
                    it = mpp.erase(it);
                }
                else{
                    ++it;
                }
            }
        }
        for(auto it : mpp){
            score += it.first;
            if(it.second >= 2){
                score += it.first;
            }
        }
        cout<<score<<endl;
    }
}