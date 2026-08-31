struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isCritical(ListNode* curr, ListNode* prev){
        ListNode* forward = curr->next;

        if(forward->val > curr->val && prev->val > curr->val){
            return true;
        }
        if(curr->val > forward->val && curr->val > prev->val){
            return true;
        }
        return false;
    }
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if(head == NULL) return {-1, -1}; 
        if(head->next == NULL){
           return {-1, -1};
        }

        int prevCritical = -1;
        int firstCritical = -1;

        int maxDistance = 0;
        int minDistance = INT_MAX;

        int i = 1;
        ListNode* prev = head;
        ListNode* curr = head->next;
        bool isFirstCritical = true;

        while(curr->next != NULL){
            if(isCritical(curr, prev)){
                if(firstCritical != -1 && prevCritical != -1){
                    maxDistance = max(maxDistance, i - firstCritical);
                    minDistance = min(minDistance, i - prevCritical);
                }
                if(isFirstCritical){
                    firstCritical = i;
                    isFirstCritical = false;
                }
                prevCritical = i;
            }
            i++;
            prev = curr;
            curr = curr->next;
        }

        if(minDistance == INT_MAX || maxDistance == 0){
            return {-1, -1};
        }
        return {minDistance, maxDistance};
    }
};