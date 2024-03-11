/*
Given the head of a singly linked list, return the middle node of the linked list.

If there are two middle nodes, return the second middle node.

Beats 100% of users with C++: Runtime
Beats 44.98% of users with C++: Memory
*/

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
    ListNode* middleNode(ListNode* head) {
        ListNode* ahead = head;
        ListNode* behind = head;

        while(ahead->next){
            if(!ahead->next->next)
                return behind->next;
            else{
                ahead = ahead->next->next;
                behind = behind->next;
            }
                
        }
        return behind;
    }
};
