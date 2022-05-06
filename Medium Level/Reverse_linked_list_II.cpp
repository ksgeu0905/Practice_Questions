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
    void reverse(ListNode**head,ListNode**tail){
        if(!(*head) || !(*head)->next)
            return;
        ListNode* p=NULL,*q=*head,*r=(*head)->next;
            while(q){
                q->next=p;
                p=q;
                q=r;
                r=r?r->next:NULL;
            }
            p=(*head);
            *head=*tail;
            *tail=p;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(!head || !head->next)
            return head;
        int p=left,n=right;
        ListNode * prev=NULL,*next_node=head,*headr=head,*tailr=NULL;
        
        while(p>1){
            headr=headr->next;
            p--;
            prev=prev?prev->next:head;
         }

        while(right){
            next_node=next_node->next;
            tailr=tailr?tailr->next:head;
            right--;
        }
        tailr->next=NULL;
        reverse(&headr,&tailr);
        if(prev){
            prev->next=headr;
        }
        tailr->next=next_node;
        if(left==1)
            return headr;
        return head;
    }
};