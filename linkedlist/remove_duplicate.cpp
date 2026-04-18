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
        ListNode* curr = head;
        if(head == NULL){
            return head;
        }
        while(curr->next != NULL && curr!=NULL){
            if(curr->val == curr->next->val){
                ListNode* deletednode = curr->next;
                curr->next = curr->next->next;
                delete(deletednode);
            }
            else
            curr = curr->next;
        }

        return head;
    }
};
