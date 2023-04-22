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
    vector<int>list;
    int i;
public:
    Solution(ListNode* head) 
    {
        while(head)
        {
            list.push_back(head->val);
            head = head->next;
        }
    }
    
    int getRandom()
    {
        static int i = 0;

        if(i == 0)
        {
            srand(time(NULL));
            i++;
        }
        int n = list.size();
        return list[rand()%n];    
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */