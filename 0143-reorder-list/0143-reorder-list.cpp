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
    void reorderList(ListNode* head) {
        if(!head || !head->next)
            return;
        ListNode*slow=head,*fast=head;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* head2=slow->next;
        slow->next=NULL;
        slow=head;
        ListNode*ptr=head2;
        
        stack<ListNode*>s;
        while(ptr){
            s.push(ptr);
            ptr=ptr->next;
        }
        while(!s.empty()){
            ptr=s.top();
            ptr->next=slow->next;
            slow->next=ptr;
            slow=slow->next->next;
            s.pop();
        }
    }
};