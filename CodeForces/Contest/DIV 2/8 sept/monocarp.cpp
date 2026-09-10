#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>nums(n);
        
        int countEasy = 0;

        for(int i = 0; i < n; i++){
            int a;
            cin>>a;
            if(a == 0){
                countEasy++;
            }
            nums[i] = a;
        }

        if(countEasy < 2){
            cout<<-1<<endl;
            continue;
        }
        else{
            if(nums[0] == 0 && nums[n-1] == 0){
                cout<<0<<endl;
            }
            else if(nums[0] == 0 || nums[n-1] == 0){
                cout<<1<<endl;
            }
            else{
                cout<<2<<endl;
            }
        }
    }
}