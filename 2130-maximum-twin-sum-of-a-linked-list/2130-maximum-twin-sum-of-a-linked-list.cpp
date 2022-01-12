/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int pairSum(ListNode* head) {
     vector<int> v1;
    ListNode* t=head;
        int n=0;
        while(t!=NULL){
            v1.push_back(t->val);
            t=t->next;
            n++;
        }
        int ans=INT_MIN;
        for(int i=0;i<=(n/2)-1;i++){
            ans=max(ans,v1[i]+v1[n-1-i]);
        }
        return ans;
    }
};