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
    struct compare{
        bool operator()(const ListNode*l1,const ListNode*l2){
            return l1->val > l2->val;
        }
    };
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*,vector<ListNode*>,compare>minheap;
        for(ListNode*node:lists){
            if(node!=nullptr){
                minheap.push(node);
            }
        }
        ListNode dummy;
        ListNode*tail = &dummy;
        while(!minheap.empty()){
            ListNode*curr = minheap.top();
            minheap.pop();
            tail->next = curr;
            tail = tail->next;
            if(curr->next !=nullptr){
                minheap.push(curr->next);
            }
        }
        return dummy.next;
    }
};
