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
    void Insert(ListNode** head,ListNode** tail,int x){
            ListNode* p=NULL;
            p=new ListNode(x);
            if(*head==NULL)
                *head=*tail=p;
            else{
                (*tail)->next=p;
                *tail=p;
            }
        }
    ListNode* mergeNodes(ListNode* head) {
        ListNode*head2=NULL,*tail=NULL;
        int sum=0;
        int z=0;
        while(head){
            if(head->val==0)
                z++;
            if(z==2){
                z=1;
                Insert(&head2,&tail,sum);
                sum=0;
            }
            sum+=head->val;
            head=head->next;
        }
        return head2;
    }
};