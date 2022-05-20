// { Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
using namespace std;
/* Link list Node */
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};




 // } Driver Code Ends
/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

class Solution{
  public:
    //Function to check whether the list is palindrome.
    Node* findMid(Node* h){
        if(h==NULL||h->next==NULL){
            return h;
        }
        Node* s=h;
        Node* f=h;
        while(f&&f->next){
            s=s->next;
            f=f->next->next;
        }
        return s;
    }
    Node* reverse(Node* h){
        if(h==NULL||h->next==NULL){
            return h;
        }
        Node* curr=h;
        Node* pre=NULL;
        Node* nxt;
        while(curr!=NULL){
            nxt=curr->next;
            curr->next=pre;
            pre=curr;
            curr=nxt;
        }
        return pre;
    }
    bool isPalindrome(Node *head)
    {
        
        if(head==NULL||head->next==NULL){
            return true;
        }
        Node* mid=findMid(head);
        if(mid->next==NULL){
            if(head->data!=head->next->data){
                return false;
            }
        }
        Node* h=reverse(mid);
        while(h!=NULL&&head!=NULL){
            if(h->data!=head->data){
                return false;
            }
            h=h->next;
            head=head->next;
        }
        return true;
    }
};



// { Driver Code Starts.
/* Driver program to test above function*/
int main()
{
  int T,i,n,l,firstdata;
    cin>>T;
    while(T--)
    {
        
        struct Node *head = NULL,  *tail = NULL;
        cin>>n;
        // taking first data of LL
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        // taking remaining data of LL
        for(i=1;i<n;i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }
    Solution obj;
   	cout<<obj.isPalindrome(head)<<endl;
    }
    return 0;
}

  // } Driver Code Ends