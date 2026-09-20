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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode dummy(0, head);
        ListNode* groupPrev = &dummy;
        
        while (true) {
            // 1. Find the kth node of the current group
            ListNode* kth = getKth(groupPrev, k);
            if (kth == nullptr) {
                break; // Not enough nodes left to reverse
            }
            
            ListNode* groupNext = kth->next;
            
            // 2. Reverse the group
            ListNode* prev = groupNext; // Notice prev starts at groupNext, not nullptr
            ListNode* curr = groupPrev->next;
            
            while (curr != groupNext) {
                ListNode* temp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = temp;
            }
            
            // 3. Update groupPrev for the next iteration
            ListNode* tmp = groupPrev->next;
            groupPrev->next = kth; // Connect previous part to new head of this group
            groupPrev = tmp;       // Move groupPrev to the end of this reversed group
        }
        
        return dummy.next;
    }
    
private:
    ListNode* getKth(ListNode* curr, int k) {
        while (curr != nullptr && k > 0) {
            curr = curr->next;
            k--;
        }
        return curr;
    }
};