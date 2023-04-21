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
    ListNode* removeNodes(ListNode* head) 
    {
        ListNode* temp = head;
        stack<ListNode*>st;
        while(head)
        {
            if(st.empty())
            {
                st.push(head);
            }
            else
            {
                while(!st.empty() && st.top()->val < head->val)
                {
                    st.pop();
                }
                st.push(head);
            }
            head = head->next;
        }    
        
        ListNode* finalhead = NULL;
        while(!st.empty())
        {
            cout<<st.top()->val<<endl;
            if(finalhead==NULL)
            {
                finalhead = st.top();
                finalhead->next  = NULL;
                st.pop();
            }
            else
            {
                st.top()->next = finalhead;
                finalhead = st.top();
                st.pop();
            }
        }

        return finalhead;
    }
};