/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };

Input: head = [1,2,3], k = 5
Output: [[1],[2],[3],[],[]]
Explanation:
The first element output[0] has output[0].val = 1, output[0].next = null.
The last element output[4] is null, but its string representation as a ListNode is [].



class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> ans;
        if(k==1){
            ans.push_back(head);
            return ans;
        }
        if(!head){
            while(k--){
                ans.push_back(NULL);
            }
            return ans;
        }
        
        int c=0;
        ListNode*ptr=head;
        while(ptr){
            c++;
            ptr=ptr->next;
        }
        int min=c/k;
        int extra=c%k;
        int max=min+1;
        ptr=head;
        ListNode*ptr2=head->next;
        for(int i=0;i<extra;i++){
            ans.push_back(ptr);
            for(int i=1;i<max;i++){
                ptr=ptr2;
                ptr2=ptr2->next;
            }
            ptr->next=NULL;
            ptr=ptr2;
            ptr2=ptr2?ptr2->next:NULL;
        }
        for(int i=0;i<k-extra;i++){
            ans.push_back(ptr);
            for(int i=1;i<min;i++){
                ptr=ptr2;
                ptr2=ptr2->next;
            }
            if(ptr)
                ptr->next=NULL;
            ptr=ptr2;
            ptr2=ptr2?ptr2->next:NULL;
        }
        return ans;
    }
};
 */