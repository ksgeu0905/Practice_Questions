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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode*ptr=list1;
        ListNode*ptr2=list1,*ptr3=list2;
        while(--a){
            ptr=ptr->next;
        }
        while(b--){
            ptr2=ptr2->next;
        }
        while(ptr3->next){
            ptr3=ptr3->next;
        }
        if(a==1)
            list1=list2;
        else
            ptr->next=list2;
        ptr3->next=ptr2->next;
        
        return list1;
        
    }
};
 */