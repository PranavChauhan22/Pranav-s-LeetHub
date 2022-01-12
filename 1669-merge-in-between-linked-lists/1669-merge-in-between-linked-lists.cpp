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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* prev;  ListNode* last;
        int i=1;
        ListNode* t=list1;
        while(i<=a-1){
            t=t->next;
            i++;
        }
        prev=t;
        while(i<=b+1){
            t=t->next;
            i++;
        }
        last=t;
        ListNode* mid=list2;
        while(list2->next!=NULL){
            list2=list2->next;
        }
        prev->next=mid;
        list2->next=last;
        return (a==1?prev:list1);
        
    }
};