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
    ListNode* swapPairs(ListNode* head) {
       
        ListNode *d = new ListNode(0);
        ListNode *temp = d,*ptr,*ptr1,*ptr2;
        d->next = head;
        if(head== NULL || head->next == NULL)
            return head;
        ptr = d->next;
        ptr1 = ptr->next;
        ptr2 = ptr1->next;
        while(ptr&&ptr1)
        {
            d->next = ptr1;
            ptr1->next = ptr;
            ptr->next = ptr2;
            d = ptr;
            ptr = d->next;
            ptr1 = ptr==NULL?NULL:ptr->next;
            ptr2 = ptr1==NULL?NULL:ptr1->next;            
        }
        
        return temp->next;
    }
};