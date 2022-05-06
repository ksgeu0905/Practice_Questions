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
    ListNode* partition(ListNode* head, int x) {
        ListNode*res=new ListNode(0);
        ListNode* ret=res;
        ListNode*ptr=head;
        while(ptr && ptr->val<x){
            res->next=new ListNode(ptr->val);
            res=res->next;
            ptr=ptr->next;
        }
        ListNode*ptr2=ptr;
        while(ptr2!=NULL){
            if(ptr2->val < x){
                res->next=new ListNode(ptr2->val);
                res=res->next;
            }
            ptr2=ptr2->next;
        }
        while(ptr){
            if(ptr->val>=x){
                res->next=new ListNode(ptr->val);
                res=res->next;
            }
            ptr=ptr->next;
        }
        return ret->next;
        
    }
};