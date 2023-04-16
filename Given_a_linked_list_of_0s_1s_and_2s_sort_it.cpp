class Solution
{
    public:
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) {
        
        Node* temp = head;
        int zero = 0, one = 0;
        while(temp)
        {
            if(temp->data == 0)
            {
                zero++;
            }
            else if(temp->data == 1)
            {
                one++;
            }
            temp = temp->next;
        }
        
        temp = head;
        while(temp)
        {
            if(zero)
            {
                temp->data = 0;
                zero--;
            }
            else if(one)
            {
                temp->data = 1;
                one--;
            }
            else
            {
                temp->data = 2;
            }
            temp = temp->next;
        }
        return head;
        
    }
};