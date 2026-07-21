/*
You have an inventory of different colored balls, and there is a customer that wants orders balls of any color.

The customer weirdly values the colored balls. Each colored ball's value is the number of balls of that color you currently have in your inventory. For example, if you own 6 yellow balls, the customer would pay 6 for the first yellow ball. After the transaction, there are only 5 yellow balls left, so the next yellow ball is then valued at 5 (i.e., the value of the balls decreases as you sell more to the customer).

You are given an integer array, inventory, where inventory[i] represents the number of balls of the ith color that you initially own. You are also given an integer orders, which represents the total number of balls that the customer wants. You can sell the balls in any order.

Return the maximum total value that you can attain after selling orders colored balls. As the answer may be too large, return it modulo 109 + 7

*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& inventory, int orders) {
        const long long MOD = 1e9 + 7;

        sort(inventory.begin(), inventory.end());

        long long common = 1;
        long long ans = 0;

        for (int i = inventory.size() - 1; i > 0; i--) {

            if (inventory[i] == inventory[i - 1]) {
                common++;
                continue;
            }

            long long curr = inventory[i];
            long long next = inventory[i - 1];
            long long level = curr - next;

            if (orders >= level * common) {

                long long sold = (curr + next + 1) * level / 2;

                ans = (ans + (sold % MOD) * common) % MOD;

                orders -= level * common;
            } else {

                long long fullLevel = orders / common;
                long long rem = orders % common;

                long long low = curr - fullLevel;

                long long sold = (curr + low + 1) * fullLevel / 2;

                ans = (ans + (sold % MOD) * common) % MOD;
                ans = (ans + (rem * low) % MOD) % MOD;

                return ans;
            }

            common++;
        }

        if (orders > 0) {

            long long curr = inventory[0];

            long long fullLevel = orders / common;
            long long rem = orders % common;

            long long low = curr - fullLevel;

            long long sold = (curr + low + 1) * fullLevel / 2;

            ans = (ans + (sold % MOD) * common) % MOD;
            ans = (ans + (rem * low) % MOD) % MOD;
        }

        return ans;
    }
};