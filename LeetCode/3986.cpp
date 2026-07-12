/*
Problem Link = https://leetcode.com/problems/number-of-elapsed-seconds-between-two-times/description/

Time - O(1);
space - O(1);

*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int secondsBetweenTimes(string startTime, string endTime) {
        int startHour = stoi(startTime.substr(0, 2));
        int endHour = stoi(endTime.substr(0, 2));

        int startMinute = stoi(startTime.substr(3, 2));
        int endMinute = stoi(endTime.substr(3, 2));

        int startSec = stoi(startTime.substr(6, 2));
        int endSec = stoi(endTime.substr(6, 2));

        int startTotalSec = startHour * 3600 + startMinute*60 + startSec;
        int endTotalSec = endHour * 3600 + endMinute * 60 + endSec;

        return endTotalSec - startTotalSec;
    }
};