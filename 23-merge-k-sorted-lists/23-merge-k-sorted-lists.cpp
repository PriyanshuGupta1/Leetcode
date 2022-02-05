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
class Solution 
{
    public:
    //Time Complexity: O(N(logN))
    //Space Complexity :O(N)
    ListNode* mergeKLists(vector<ListNode*>& lists) 
    {
        vector <int> a; //creating a vector of array to store all nodes value
        if(lists.size()==0) //if no lists are present just return NULL
            return NULL;
        for(int i=0;i!=lists.size();i++)
        {
            ListNode *curr=lists[i]; // accessing the first list
            while(1)
            {
                if(curr!=NULL)
                {
                    a.push_back(curr->val);
                    curr=curr->next;
                }
                else
                    break;
            }
        }
        sort(a.begin(),a.end());
        ListNode *curr=NULL,*start=NULL;
        for(int i=0;i<a.size();i++)
        {
            ListNode *curr1=new ListNode(a[i]);
            if(start==NULL)
            {
                start=curr1;
                curr=curr1;
            }
            else
            {
                curr->next=curr1;
                curr=curr1;
            }
        }
        return start;
    }
};