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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy=new ListNode(head->val);
        dummy->next=head;
        ListNode* s=dummy;
        ListNode* f=dummy;
        for(int i=1;i<=n;i++){
            f=f->next;
        }
        while(f->next!=NULL){
            s=s->next;
            f=f->next;
        }
        s->next=s->next->next;
        return dummy->next;
    }
    
};