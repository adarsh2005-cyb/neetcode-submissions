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
    ListNode* reverselist(ListNode* head){
        ListNode* prev=NULL;
        ListNode* curr=head;
        ListNode* next=NULL;
        if(head==NULL){
            return NULL;
        }
        while(curr!=NULL){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
        

    }
    void reorderList(ListNode* head) {
        ListNode* sl = head;
        ListNode* fs = head;
        while(fs->next!=NULL && fs->next->next!=NULL){
            sl=sl->next;
            fs=fs->next->next;
        }
        ListNode* st2=sl->next;
        sl->next=NULL;
        sl=head;
        ListNode* rev=reverselist(st2);
        while(rev!=0){
            ListNode* temp = sl->next;
            ListNode* temp2= rev->next;
            sl->next=rev;
            rev->next=temp;
            sl=temp;
            rev=temp2;
        }
    }
};
