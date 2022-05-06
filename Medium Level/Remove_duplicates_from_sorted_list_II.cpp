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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head->next)
            return head;
        ListNode* dummy=new ListNode(0,head);
        // int f=0;
        // while(1){
        //     f=0;
        //     while(head && head->next && head->val == head->next->val){
        //         head=head->next;
        //         f=1;
        //     }
        //     if(f==1)
        //         head=head->next;
        //     if(!head || !head->next || head->val!=head->next->val)
        //         break;
        // }
        ListNode*p=dummy,*q=NULL,*r=NULL;
        q=p?p->next:NULL;
        r=q?q->next:NULL;
        while(q){
            int f=0;
            while(r && q->val==r->val){
                r=r->next;
                f=1;
            }
            if(f==1){
                p->next=r;
                q=r;
                r=r?r->next:NULL;
            }
            else{
                p=q;
                q=r;
                r=r?r->next:NULL;

            }
            
            
        }
        
        return dummy->next;
    }
};