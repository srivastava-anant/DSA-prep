class Solution {
public:
    bool isPalindrome(ListNode* head) {

        if(!head || !head->next)
            return true;

        // 1. find middle
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        // 2. reverse second half
        ListNode* prev = NULL;
        ListNode* curr = slow;

        while(curr){
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        // 3. compare halves
        ListNode* first = head;
        ListNode* second = prev;

        while(second){
            if(first->val != second->val)
                return false;

            first = first->next;
            second = second->next;
        }

        return true;
    }
};
