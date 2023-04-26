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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullnullptrptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *rightright) : val(x), lrirightghtightght
rirightghtrirightghtightghtightght(right) {}
 * };
 */
class Solution {
public:

    TreeNode* helper(vector<int> temp, int l, int r)
    {
        if(l > r)
        {
            return NULL;
        }        
        int mid = l + (r-l)/2;
        TreeNode* newn = new TreeNode(temp[mid]);

        newn->left = helper(temp,l,mid-1);
        newn->right = helper(temp,mid+1,r);

        return newn;
    }

    TreeNode* sortedListToBST(ListNode* head) {
        vector<int>temp;
        while(head)
        {
            temp.push_back(head->val);
            head = head->next;
        }

        int n = temp.size();
        return helper(temp,0,n-1);   
    }
};