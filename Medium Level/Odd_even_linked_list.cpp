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
    ListNode* oddEvenList(ListNode* head) {
        ListNode*odd=new ListNode(0);
        ListNode*even=new ListNode(0);
        ListNode*reto=odd,*rete=even;
        ListNode*ptr=head;
        int i=1;
        while(ptr){
            if(i%2){
                odd->next=new ListNode(ptr->val);
                odd=odd->next;   
            }
            else{
                even->next=new ListNode(ptr->val);
                even=even->next;
            }
            i++;
            ptr=ptr->next;
        }
        odd->next=rete->next;
        return reto->next;

        
    }
};
 */