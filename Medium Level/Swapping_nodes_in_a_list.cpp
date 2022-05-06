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
    ListNode* swapNodes(ListNode* head, int k) {
        int c=0;
        ListNode* ptr=head,*a=head,*b=head;
        while(ptr){
            c++;
            ptr=ptr->next;
            
        }
        int l=c-k;
        k--;
        while(k--)
            a=a->next;
        while(l--)
            b=b->next;
        int t=a->val;
        a->val=b->val;
        b->val=t;
        return head;
    }
};