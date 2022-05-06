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
        if(!head || !head->next)
            return head;
        ListNode* res=new ListNode(0);
        ListNode* ret=res;
        ListNode*ptr=head,*ptr2=head->next;
        while(ptr && ptr2){
            res->next=new ListNode(ptr2->val);
            res=res->next;
            res->next=new ListNode(ptr->val);
            res=res->next;
            ptr=ptr->next?ptr->next->next:NULL;
            ptr2=ptr2->next?ptr2->next->next:NULL;
            
        }
        if(ptr)
             res->next=new ListNode(ptr->val);
        if(ptr2)
             res->next=new ListNode(ptr2->val);

        return ret->next;
    }
};