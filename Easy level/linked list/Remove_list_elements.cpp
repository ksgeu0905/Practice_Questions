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
        if(head==NULL ||( head->val==val && head->next==NULL))
            return NULL;
        
        ListNode*p=head,*q=head->next;
        while(p!=NULL && p->val==val){
            head=head->next;
            p=head;
        }
        if(head==NULL)
            return NULL;
        q=p->next;
        while(q){
            if(q->val==val){
                p->next=q->next;
                
            }
            else
                p=p->next;
            q=q->next;
        }
        return head;
    }
};