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

        int count = 0;
        ListNode* current = head;

        while(current){
            current = current->next;
            ++count;
        }

        count -= n;

        current = head;
        ListNode* prev = nullptr;
        ListNode* next = current->next;

        for(int i = 0; i <= count; ++i){
            
            if(i == count){
                if(prev){
                    prev->next = next;
                }else{
                    head = next;
                }
                delete current;
                break;
            }

            prev = current;
            current = next;
            next = current->next;

        }

        return head;

    }
};