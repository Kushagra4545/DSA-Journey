#include<bits/stdc++.h>
using namespace std;

int countDifferent(string s){
    stack<char>st;
    int count = 0;

    for(int i = 0; i < s.size(); i++){
        if(!st.empty() && st.top() != s[i]){
            count++;
            st.pop();
        }
        else{
            st.push(s[i]);
        }
    }
    return count;
}

int main(){
    int t;
    cin>>t;

    while(t--){
        string s;
        cin>>s;

        int count = countDifferent(s);
        if(count % 2 == 0){
            cout<<"NET"<<endl;
        }
        else{
            cout<<"DA"<<endl;
        }
    }
}