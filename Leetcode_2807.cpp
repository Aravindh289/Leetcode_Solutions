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
    int gcd(int a, int b) 
    {
        while (b != 0) 
        {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
    ListNode* insertGreatestCommonDivisors(ListNode* head) 
    {
        ListNode* temp = head;
        while(temp!=nullptr)
        {
            int a = temp->val;
            int b = 0;
            if(temp->next!=nullptr)
            {
                b = temp->next->val;
            }
            else
            {
                break;
            }
            int c = gcd(a,b);
            ListNode* addr = temp->next;
            ListNode* nn = new ListNode(c);
            nn->next = addr;             
            temp->next = nn;

            temp = nn->next;
        }
        return head;
    }
};