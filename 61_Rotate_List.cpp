class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL)
        {
            return NULL;
        }
        ListNode* temp = head;
        int len = 0;
        while(temp != NULL)
        {
            temp = temp->next;
            len++;
        }

        int newlen = k%len;
        if(newlen == 0)
        {
            return head;
        }
        

        k = len-newlen;
        
        temp = head;
        while(--k)
        {
            temp = temp->next;
        }
        ListNode* ans = temp->next;

        ListNode* part2 = temp->next;
        temp->next = NULL;

        while(part2->next)
        {
            part2 = part2->next;
        }

        part2->next = head;
        
        return ans;
    }
};  