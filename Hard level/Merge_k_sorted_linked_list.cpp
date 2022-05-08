/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 

Input: lists = [[1,4,5],[1,3,4],[2,6]]
Output: [1,1,2,3,4,4,5,6]
Explanation: The linked-lists are:
[
  1->4->5,
  1->3->4,
  2->6
]
merging them into one sorted list:
1->1->2->3->4->4->5->6


class Solution {
public:
    ListNode * merge(ListNode * left,ListNode*right){
        if(!left)return right;
        if(!right)return left;
        ListNode* head=new ListNode(-1);
        ListNode* ans=head;
        while(left && right){
            if(left->val<=right->val){
                head->next=left;
                head=left;
                left=left->next;
            }
            else{
                head->next=right;
                head=right;
                right=right->next;
            }
            
        }
        if(left)
            head->next=left;
        if(right)
            head->next=right;
        return ans->next;
    }
    ListNode* merge_sort(vector<ListNode*> & lists,int l,int r){
        if(l==r){
            return lists[l];
        }
        if(l<r){
            int mid=l+(r-l)/2;
            ListNode* left=merge_sort(lists,l,mid);
            ListNode* right=merge_sort(lists,mid+1,r);
            return merge(left,right);
        }
        return NULL;
        
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode*ans=NULL;
        ans=merge_sort(lists,0,lists.size()-1);
        return ans;
    }
};
 */