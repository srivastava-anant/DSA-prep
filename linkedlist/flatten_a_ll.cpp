class Solution {
public:
    Node* flatten(Node* head) {

        if(head == NULL)
            return NULL;

        Node* curr = head;

        while(curr != NULL){

           
            if(curr->child != NULL){

                Node* childHead = flatten(curr->child); 
                Node* nextNode = curr->next;             

                
                curr->next = childHead;
                childHead->prev = curr;
                curr->child = NULL;

                
                Node* tail = childHead;
                while(tail->next != NULL){
                    tail = tail->next;
                }

                
                tail->next = nextNode;
                if(nextNode != NULL)
                    nextNode->prev = tail;
            }

            
            curr = curr->next;
        }

        return head;
    }
};
