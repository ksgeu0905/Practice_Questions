/*
You are given the head of a singly linked-list. The list can be represented as:

L0 → L1 → … → Ln - 1 → Ln
Reorder the list to be on the following form:

L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
You may not modify the values in the list's nodes. Only nodes themselves may be changed.


Input: head = [1,2,3,4]
Output: [1,4,2,3]

*//**
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