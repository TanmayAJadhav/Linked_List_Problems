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
    ListNode* deleteDuplicates(ListNode* head) 
    {
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* temp = dummy; 
        while(temp->next && temp->next->next)
        {
            if(temp->next->val == temp->next->next->val)
            {
                int value = temp->next->val;
                while(temp->next && temp->next->val == value)
                {
                    temp->next = temp->next->next;
                }
            }
            else
            {
                temp = temp->next;
            }
        }
        return dummy->next;

        if(head->val == head->next->val)
        {

            temp = head;
            while(temp->val == temp->next->val)
            {
                temp = temp->next;
            }
            head = temp->next;
        }
        return head;
    }
};