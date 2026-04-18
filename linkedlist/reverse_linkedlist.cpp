class Solution {
public:
    ListNode* reverseList(ListNode* head) {

        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next = NULL;

        while(curr != NULL){
            next = curr->next;   // store next
            curr->next = prev;   // reverse link
            prev = curr;         // move prev
            curr = next;         // move curr
        }

        return prev;
    }
};
change of link 
we first need to secure the first link then change the previous and after that increase the pointer 
