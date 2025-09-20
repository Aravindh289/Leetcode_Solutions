class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int c = 0, rm = 0;
        ListNode *temp = head, *pre;
        
        while(temp != nullptr) {
            c++;
            temp = temp->next;
        }

        rm = c - n + 1; 

        if(rm == 1) 
        {
            return head->next;
        }

        c = 1;
        temp = head;
        while(c < rm) {
            pre = temp;
            temp = temp->next;
            c++;
        }
        pre->next = temp->next;
        delete temp;
        return head;
    }
};
