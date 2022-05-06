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
    ListNode* insertionSortList(ListNode* head) {
        if(!head || !head->next)
            return head;
        ListNode * h=head,*p=head->next,*itr=NULL,*temp=NULL;
        h->next=NULL;
        while(p){
            temp=p;
            p=p->next;
            if(temp->val <= h->val){
                temp->next=h;
                h=temp;
            }
            else{
                itr=h;
                while(itr->next && temp->val > itr->next->val){
                    itr=itr->next;
                }
                temp->next=itr->next;
                itr->next=temp;
                
            }
        }
        return h;
        
    }
};
 */