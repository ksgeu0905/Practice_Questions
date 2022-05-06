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
    ListNode * findmid(ListNode* head){
        ListNode* slow=head,*fast=head->next;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    ListNode* merge(ListNode* left,ListNode * right){
        if(!left)return right;
        if(!right)return left;
        ListNode* res=new ListNode(-1);
        ListNode* ret=res;
        while(left && right){
            if(left->val<right->val){
                res->next=left;
                res=left;
                left=left->next;
            }
            else{
                res->next=right;
                res=right;
                right=right->next;
            }
        }
        if(left){
            res->next=left;
            res=res->next;
        }
        if(right){
            res->next=right;
            res=res->next;
        }
        return ret->next;
    }
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next)
            return head;
        ListNode* mid=findmid(head);
        ListNode* left=head;
        ListNode* right=mid->next;
        mid->next=NULL;
        
        left=sortList(left);
        right=sortList(right);
        
        ListNode * res=merge(left,right);
        return res;
    }
};
 */