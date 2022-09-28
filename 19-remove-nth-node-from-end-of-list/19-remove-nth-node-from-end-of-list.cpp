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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int c=0;
        ListNode* cur=head,*prev=NULL,*p=head;
        while(p){
            c++;
            p=p->next;
        }
        c=c-n;
        if(c==0){
            return head->next;
        }
        while(c--){
            prev=cur;
            cur=cur->next;
        }
        prev->next=cur->next;
        return head;
    }
};