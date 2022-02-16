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
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL||head->next==NULL){
            return head;
        }
        ListNode* h=head;
        vector<ListNode*> v;
        while(h!=NULL){
            v.push_back(h);
            h=h->next;
        }
        
        int i=0,j=1;
        ListNode* t=NULL;
        ListNode* pr=NULL;
        while(j<v.size()){
            if(t==NULL){
                t=v[j];
                pr=v[j];
                pr->next=v[i];
                pr=v[i];
            }
            else{
                pr->next=v[j];
                pr=v[j];
                pr->next=v[i];
                pr=v[i];
            }
            i+=2;j+=2;
        }
        if(i<=v.size()-1){
            pr->next=v[i];
            pr=v[i];
        }
        pr->next=NULL;
        return t;
        
    }
};