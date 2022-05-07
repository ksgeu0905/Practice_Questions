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
    ListNode* reverse_list(ListNode* head){
        ListNode* p=NULL,*q=head,*r=q?head->next:NULL;
        while(q){
            q->next=p;
            p=q;
            q=r;
            r=r?r->next:NULL;
        }
        return p;
    }
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> ans;
        head=reverse_list(head);
        stack<int> s;
        while(head){
            if(s.empty()){
                ans.push_back(0);
                s.push(head->val);
                head=head->next;
            }
            else if(s.top()> head->val){
                ans.push_back(s.top());
                s.push(head->val);
                head=head->next;
            }
            else
                s.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
 */