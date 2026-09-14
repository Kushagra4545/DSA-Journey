#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;

        vector<int>nums(n);

        vector<int>vis(n, 0);
        vector<int>ans;
        for(int i = 0; i < n; i++){
            int p;
            cin>>p;

            if(p != i + 1){
                ans.push_back(p);
                vis[i] = 1;
            }
            nums[i] = p;
        }

        reverse(ans.begin(), ans.end());
        
        int a = 0;
        for(int i = 0; i < n; i++){
            if(vis[i] == 1){
                nums[i] = ans[a++];
            }
        }

        bool isSorted = true;
        for(int i = 0; i < n; i++){
            if(nums[i] != i + 1){
                isSorted = false;
                break;
            }
        }

        if(isSorted){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
}