/*
Given the head of a linked list, remove the nth node from the end of the list and return its head.

Beats 100% of users with C++ runtime
Beats 83.94% of users with C++ in memory
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // if the only value in the list is the head return to save runtime
        if(!head->next)
            return NULL;

        ListNode* currentNode = head;
        ListNode* leadingNode = head;
        int currPosition = 0;
        int leadingPosition = 0;
        
        // setup the lead node to find the end so current is at the n-1 position
        while(leadingNode->next && leadingPosition < n){
            leadingNode = leadingNode->next;
            leadingPosition++;
        }
        cout << "leading pos: " << leadingPosition << "\n";


        // If leading node last element
        if(!leadingNode->next){
            // if removing the 
            if(n == leadingPosition){
                if(!head->next->next)
                    head->next = NULL;
                else
                    head->next = head->next->next;
                return head;
            } else{
                return head->next;
            }
            // cout << currentNode->val << " " << leadingNode->val << "\n";
            // currentNode->next = NULL;
            // return head;
        }
        while(leadingNode->next){
            leadingNode = leadingNode->next;
            currentNode = currentNode->next;
            cout << currentNode->val << " " << leadingNode->val << "\n";
            if(!leadingNode->next){
                currentNode->next = currentNode->next->next;
                return head;
            }
        }
        return head;
    }
};
