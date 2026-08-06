#include<bits/stdc++.h>
using namespace std;

int helper(int idx, int prev, vector<int>& nums){
    if(prev == 0){
        return -1;
    }
    int n = nums[idx];
    int count = 0;
    while(n >= prev){
        count++;
        n = n/2;
    }
    nums[idx] = n;
    return count;
}

int main(){
    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;
        vector<int>nums(n);

        for(int i =0 ; i < n; i++){
            cin>>nums[i];
        }
        
        if(n == 1){
            cout<<0<<endl;
            continue;
        }
        if(nums[n-1] == 1 && n > 2){
            cout<<-1<<endl;
            continue;
        }

        int count = 0;
        int prev = nums[n-1];
        bool isSafe = true;

        for(int i = n-2; i >= 0; i--){
            int val = helper(i, prev, nums);
            if(val == -1){
                isSafe = false;
                break;
            }
            count += val;
            prev = nums[i];
        }

        if(isSafe){
            cout<<count<<endl;
        }
        else{
            cout<<-1<<endl;
        }
    }
}