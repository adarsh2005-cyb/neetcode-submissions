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
    bool hasCycle(ListNode* head) {
        if(head==NULL){
            return false;
        }
        unordered_set<ListNode*> m;
        while(head!=NULL){
            if(m.find(head)!=m.end()){
                return true;
            }
            m.insert(head);
            head=head->next;   
            }
            return false;
            
        }
        
    };
