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
    ListNode* removeZeroSumSublists(ListNode* head) 
    {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* temp = head;

        map<int,ListNode*>mp;
        mp[0] = dummy;
        int pref_sum = 0;
        
        while(temp != NULL)
        {
            pref_sum += temp->val;
            if(mp.count(pref_sum))
            {
                ListNode *p = mp[pref_sum]->next;
                int value = pref_sum;
                while(p != temp)
                {
                    value += p->val;
                    mp.erase(value);
                    p = p->next;
                }
                mp[pref_sum]->next = temp->next;
            }
            else
            {
                mp[pref_sum] = temp; 
            }
            temp = temp->next;
        }
        return dummy->next;
    }
};