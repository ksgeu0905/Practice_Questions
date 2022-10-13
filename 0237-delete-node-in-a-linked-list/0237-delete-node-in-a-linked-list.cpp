/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* temp=node->next,*temp2=node;
        while(temp){
            node->val=temp->val;
            node=temp;
            temp=temp->next;
        }
        while(temp2->next->next){
            temp2=temp2->next;
        }
        temp2->next=NULL;
    }
};