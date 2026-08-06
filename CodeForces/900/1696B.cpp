#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        long long n;
        cin>>n;

        vector<long long>nums(n);

        for(int i =0; i < n; i++){
            cin>>nums[i];
        }

        long long count = 0;
        long long prev = 0;

        for(int i = 0; i < n; i++){
            if(nums[i] == 0){
                prev = nums[i];
                continue;
            }
            else if(prev == 0){
                count++;
                prev = nums[i];
            }
            else{
                prev = nums[i];
            }
        }
        
        if(count == 0){
            cout<<0<<endl;
        }
        else if(count == 1){
            cout<<1<<endl;
        }
        else{
            cout<<2<<endl;
        }
    }
}