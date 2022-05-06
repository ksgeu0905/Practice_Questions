/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head || !head->next)
            return NULL;
        ListNode *slow=head,*fast=head;
        int f=0;
        while(fast){
            slow=slow->next;
            fast=fast->next?fast->next->next:fast->next;
            if(slow==fast){
                f=1;
                break;
            }
        }
        if(f==1){
            slow=head;
            while(slow!=fast){
                slow=slow->next;
                fast=fast->next;
            }
            return slow;
        }
        return NULL;
    }
};
 */