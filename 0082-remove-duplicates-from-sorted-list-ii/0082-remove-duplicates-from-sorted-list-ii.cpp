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
    ListNode* deleteDuplicates(ListNode* head) {
            ListNode dummy(0);
            dummy.next = head;
            ListNode* prev = &dummy;
            ListNode* curr = head;
            while(curr != nullptr){
                bool duplicate = false;
                while(curr->next != nullptr && curr->val == curr->next->val){
                    duplicate = true;
                    curr = curr->next;
                }
                if(duplicate){
                    prev->next = curr->next;
                }
                else {
                    prev = prev->next;
                }
                curr = curr->next;
            }
            return dummy.next;
        
    }
};