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
    ListNode* reverse(ListNode*head){
        if(!head || !head->next)
            return head;
        ListNode*prev=NULL,*cur=head,*nex=head->next;
        while(cur){
            cur->next=prev;
            prev=cur;
            cur=nex;
            nex=nex?nex->next:NULL;
        }
        return prev;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(!l1)return l2;
        if(!l2)return l1;
        ListNode* h1=reverse(l1);
        ListNode* h2=reverse(l2);
        ListNode* res=new ListNode(-1);
        ListNode*ret=res;
        int sum=0,carry=0;
        while(h1 && h2){
            sum=h1->val+h2->val+carry;
            if(sum<=9){
                res->next=new ListNode(sum);
                res=res->next;
                carry=0;
            }
            else{
                res->next=new ListNode(sum%10);
                res=res->next;
                carry=1;
            }
            h1=h1->next;
            h2=h2->next;
        }
        
        while(h1){
            sum=h1->val+carry;
            if(sum<=9){
                res->next=new ListNode(sum);
                res=res->next;
                carry=0;
            }
            else{
                res->next=new ListNode(sum%10);
                res=res->next;
                carry=1;
            }
            h1=h1->next;
        }
        while(h2){
            sum=h2->val+carry;
            if(sum<=9){
                res->next=new ListNode(sum);
                res=res->next;
                carry=0;
            }
            else{
                res->next=new ListNode(sum%10);
                res=res->next;
                carry=1;
            }
            h2=h2->next;
        }
        if(carry){
            res->next=new ListNode(1);
        }
        ListNode * ans=ret->next;
        return reverse(ans);
        
    }
};
 */