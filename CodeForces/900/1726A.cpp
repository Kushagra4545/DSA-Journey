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

        int maxi = nums[n-1] - nums[0];

        for(int i = 0; i < n-1; i++){
            maxi = max(maxi, nums[i] - nums[i+1]);
        }

        for(int i = 0; i < n-1; i++){
            maxi = max(maxi, nums[n-1] - nums[i]);
        }

        for(int i = 1; i < n; i++){
            maxi = max(maxi, nums[i] - nums[0]);
        }

        cout<<maxi<<endl;
    }
}