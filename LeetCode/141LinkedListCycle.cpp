/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        
        ListNode* slow = head;
        ListNode* speed = head;

        while(speed && speed->next){
            slow = slow->next;
            speed = speed->next->next;
            if(slow == speed){
                return true;
            }
        }
        return false;
    }
};