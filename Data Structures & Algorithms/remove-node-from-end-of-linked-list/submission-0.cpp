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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0,head);
        ListNode* left = dummy;
        ListNode* right = head;
        while(n>0 && right != nullptr){
            right = right->next;
            n--;
        }
        while(right !=nullptr){
            left = left->next;
            right = right->next;
        }
        ListNode* todelete = left->next;
        left->next = left->next->next;
        delete todelete ;
        ListNode * newhead = dummy ->next;
        delete dummy;
        return newhead;
    }
};
