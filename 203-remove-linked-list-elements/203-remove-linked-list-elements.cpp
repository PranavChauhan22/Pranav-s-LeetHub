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
    ListNode* removeElements(ListNode* head, int val) {
        if(head==NULL){
            return NULL;
        }
        if(head->next==NULL)
        {
            if(head->val==val){
                return NULL;
            }else{
                return head;
            }
        }
        ListNode* d=new ListNode(-1);
        ListNode* p=d;
        d->next=head;
        ListNode* c=head;
        while(c){
            if(c->val==val){
                p->next=c->next;
                c=c->next;
            }else{
                p=p->next;
                c=c->next;
            }
        }
        return d->next;
            
    }
};