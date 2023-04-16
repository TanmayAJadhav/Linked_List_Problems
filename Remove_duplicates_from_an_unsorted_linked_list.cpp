class Solution
{
    public:
    //Function to remove duplicates from unsorted linked list.
    Node * removeDuplicates( Node *head) 
    {
        unordered_map<int,bool>mp;
        
        Node* temp = head;
        int cnt = 1;
        while(temp->next != NULL)
        {
            mp[temp->data] = true;
            // cout<<"Out "<<temp->data<<endl;
            if(mp.find(temp->next->data) != mp.end())
            {
                // cout<<"In "<<temp->data<<" : "<<cnt<<endl;
                Node* del = temp->next;
                temp->next = temp->next->next;
                delete del;
            }
            else
            {
                temp = temp->next;
            }
            
            cnt++;
        }
        return head;
    }
};