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
        ListNode* current = head;
        for(int i =0;i<k;i++){
            if(current == nullptr){
                return head;
            }
            current = current->next;
        }
        ListNode* prev = nullptr;
        current = head;
        for(int i =0;i < k; i++){
            ListNode* next = current-> next;
            current -> next = prev;
            prev = current;
            current = next;
        }
        head ->next = reverseKGroup(current,k);
        return prev;
    }
    
};