#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isAvailable(int p, int q, vector<int>& temp){
        bool flag = true;
        for(int i = p; i <= q; i++){
            if(temp[i] != 0){
                flag = false;
                break;
            }
        }
        return flag;
    }
    int helper(vector<int>col){
        vector<int>temp(11, 0);

        for(int i = 0; i < col.size(); i++){
            temp[col[i]] = 1;
        }
        for(auto it : temp){
            cout<<it<<" ";
        }
        cout<<endl;
        int count = 0;

        if(isAvailable(2, 5, temp)){
            count++;
            if(isAvailable(6, 9, temp)){
                count++;
            }
        }
        else{
            if(isAvailable(4, 7, temp)){
                count++;
            }
            else{
                if(isAvailable(6, 9, temp)){
                    count++;
                }
            }
        }
        return count;
    }
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        map<int, vector<int>>mpp;

        for(auto it : reservedSeats){
            int r = it[0];
            int c = it[1];

            mpp[r].push_back(c);
        }

        int ans = (n - mpp.size()) * 2;

        for(auto it : mpp){
            vector<int>temp = it.second;
            ans += helper(temp);
        }
        return ans;
    }
};