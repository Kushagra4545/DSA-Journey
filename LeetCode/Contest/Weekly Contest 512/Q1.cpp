/*
Problem Link - https://leetcode.com/problems/largest-integer-with-given-digit-sum/description/

Time Complexity - O(S);
Space = O(1);
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestInteger(int n, int s) {
        if(9*n < s){
            return -1;
        }

        int tens = 1;
        for(int i = 0; i < n-1; i++){
            tens *= 10;
        }
        int num = 0;
        while(s > 0){
            if(s < 9){
                num += s*tens;
            }
            else{
                num += 9*tens;
            }
            s -= 9;
            tens /= 10;
        }
        return num;
    }
};