class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(head->next==NULL)
            return true;
        ListNode* p=head,*q=head;
        while(q && q->next){
            q=q->next->next;
            p=p->next;
        }
        q=head;
        while(q->next!=p)
            q=q->next;
        q->next=NULL;
        ListNode* head2=p;
        p=head2->next;
        q=head2;
        ListNode*r=NULL;
        while(q){
            q->next=r;
            r=q;
            q=p;
            p=p?p->next:NULL;
        }
        head2=r;
        while(head && head2 ){
            if(head->val != head2->val)
                return false;
            head=head->next;
            head2=head2->next;
        }
        return true;
    }
};