/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next)
            return head;
        ListNode* p=head,*tail=NULL;
        int c=0;
        while(p){
            c++;
            if(p->next==NULL)
                tail=p;
            p=p->next;

        }
        k=k%c;
        if(k==0)
            return head;
        k=c-k;
        ListNode*ptr=NULL,*ptr1=head;
        while(k--){
            ptr=ptr1;
            ptr1=ptr1->next;
        }
        ptr->next=NULL;
        tail->next=head;
        head=ptr1;
        return head;
        
    }
};
 */