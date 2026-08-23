#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string binary(int n){
        string res;

        while(n > 0){
            int i = n % 2;
            string b = to_string(i);
            res = res + b;
            n = n / 2;
        }

        reverse(res.begin(), res.end());
        
        while(res.size() < 8){
            res = "0" + res;
        }

        return res;
    }
    bool isPalindromic(string s) {
        string res;
        for(int i = 0; i < s.size(); i++){
            string a = binary((int)s[i]);
            res = res + a;
        }
        cout<<res<<endl;
        int i = 0;
        int j = res.size()-1;
        while(i <= j){
            if(res[i] != res[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};