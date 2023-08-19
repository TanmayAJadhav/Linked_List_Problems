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
    ListNode* sortList(ListNode* head)
    {
        if(head==NULL || head->next==NULL)
        {
            return head;
        }

        ListNode* temp = NULL;
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast && fast->next)
        {
            temp = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        temp->next = NULL;
        ListNode* l1 = sortList(head);
        ListNode* l2 = sortList(slow);

        return mergeTwoLists(l1,l2);
        
    }

    ListNode* mergeTwoLists(ListNode* head1, ListNode* head2) {
        ListNode *temp = new ListNode;
        ListNode *dummy = temp;   
        while (head1 != NULL && head2 != NULL)
        {
            if (head1->val <= head2->val)
            {
                temp->next = head1;
                head1 = head1->next;
            }
            else
            {
                temp->next = head2;
                head2 = head2->next;
            }
            temp = temp->next;
        }

        while (head1 != NULL)
        {
            temp->next = head1;
            temp = temp->next;
            head1 = head1->next;
        }

        while (head2 != NULL)
        {
            temp->next = head2;
            temp = temp->next;
            head2 = head2->next;
        }

        return dummy->next;
        
    }
};