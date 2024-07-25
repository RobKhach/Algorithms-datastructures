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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        if(list1 == nullptr){
            return list2;
        }else if(list2 == nullptr){
            return list1;
        }


        ListNode new_head;
        ListNode* new_list = &new_head;


        while(list1 && list2){
            if(list1->val <= list2->val){
                new_list->next = list1;
                list1 = list1->next;
                new_list = new_list->next;
            }else{
                new_list->next = list2;
                list2 = list2->next;
                new_list = new_list->next;
            }
        }

        if(list1){
            new_list->next = list1;
        }else if(list2){
            new_list->next = list2;
        }

        return new_head.next;
    }
};