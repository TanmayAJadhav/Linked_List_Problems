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
    vector<int> nextLargerNodes(ListNode* head) 
    {
        stack<pair<int,int>>st;
        ListNode* temp = head;
        ListNode* temp2 = head;
        int cnt = 0;
        while(temp)
        {
            cnt++;
            temp = temp->next;
        }
        
        vector<int>ans(cnt);
        for(int i = 0; i < cnt; i++)
        {
            if(st.empty()==true)
            {
                st.push({i,temp2->val});
            }
            else
            {
                while(!st.empty() && st.top().second < temp2->val)
                {
                    ans[st.top().first] = temp2->val;
                    st.pop();   
                }
                st.push({i,temp2->val});
            }
            temp2 = temp2->next;
        }

        return ans;
    }
// };