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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) 
    {
        ListNode* temp = list1, *head = list1;

        int cnt = a-1;
        while(temp->next && cnt)
        {
            temp = temp->next;
            cnt--;
        }    

        ListNode* temp2 = temp;
        cnt =  b-a+1;
        
        while(temp->next && cnt)
        {
            temp2 = temp2->next;
            cnt--;
        }

        temp->next = list2;
        ListNode* head2 = list2;

        while(head2->next)
        {
            head2 = head2->next;
        }

        head2->next = temp2->next;
        return head;
    }
};