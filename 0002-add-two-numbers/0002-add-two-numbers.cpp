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
    void Insert(ListNode**head,ListNode**tail,int x){
        ListNode*p=new ListNode(x);
        if(*head==NULL)
            *head=*tail=p;
        else{
            (*tail)->next=p;
            *tail=p;
        }
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1==NULL)
            return l2;
        if(l2==NULL)
            return l1;
        int carry=0,s=0;
        ListNode*p1=l1,*p2=l2,*head=NULL,*tail=NULL;
        while(p1 && p2){
            s=p1->val+p2->val+carry;
            if(s<=9){
                Insert(&head,&tail,s);
                carry=0;
            }
            else{
                Insert(&head,&tail,s%10);
                carry=1;
            }
            p1=p1->next;
            p2=p2->next;
        }
        while(p1){
             s=p1->val+carry;
            if(s<=9){
                Insert(&head,&tail,s);
                carry=0;
            }
            else{
                Insert(&head,&tail,s%10);
                carry=1;
            }
            p1=p1->next;
        }
        while(p2){
             s=p2->val+carry;
            if(s<=9){
                Insert(&head,&tail,s);
                carry=0;
            }
            else{
                Insert(&head,&tail,s%10);
                carry=1;
            }
            p2=p2->next;
        }
        if(carry==1)
            Insert(&head,&tail,1);
        return head;
    }
};