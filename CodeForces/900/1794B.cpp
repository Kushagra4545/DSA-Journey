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

        for(int i = 0; i < n; i++){
            if(nums[i] == 1){
                nums[i]++;
            }
        }

        for(int i = 0; i < n-1; i++){
            int a = nums[i];
            int b = nums[i+1];
            
            if(b % a == 0){
                nums[i+1]++;
            }
        }
        for(int i = 0;i < n; i++){
            cout<<nums[i]<<" ";
        }
        cout<<endl;
    }
}