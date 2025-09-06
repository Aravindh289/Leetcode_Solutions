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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* temp = head,*pre1,*pre2;
        int c = 0;
        while(temp!=nullptr)
        {
            c++;
            temp=temp->next;
        }
        int end = (c - k) + 1;
        int st = k;
        temp = head;
        while(st > 0)
        {
            st--;
            pre1 = temp;
            temp = temp->next;
        }
        temp = head;
        while(end > 0)
        {
            end--;
            pre2 = temp;
            temp = temp->next;
        }
        int p2 = pre2->val;
        pre2->val = pre1->val;
        pre1->val = p2;
        return head;
    }
};