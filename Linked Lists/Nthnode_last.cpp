#include<bits/stdc++.h>
using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

  class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        if(head==NULL || head->next==NULL){
            return NULL;
        }
        
        int count=0;
        ListNode* temp=head;
        while(temp!=NULL){
            temp = temp->next;
            count++;
        }
        temp=head;
        int scount=0;
        ListNode*prev;
        while(scount<count-n){
            prev=temp;
            temp=temp->next;
            scount++;
        }
        
        //Remember this point 
        if(prev==NULL){
            return head->next;
        }
        
        prev->next = prev->next->next;
        
        
    return head;}
};