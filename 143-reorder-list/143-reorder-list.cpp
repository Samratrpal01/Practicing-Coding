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
    void reorderList(ListNode* head) {
        vector<int>v;
        ListNode* ll=head;
        ListNode* temp=head;
        while(temp)
        {
            v.push_back(temp->val);
            temp=temp->next;
            
        }
        bool flag=false;
        
        int i=1,j=v.size()-1;
        while(i<=j)
        {   if(flag==true)
            {
            ListNode* tmp=new ListNode(v[i++]);
            flag=false;
            head->next=tmp;
                head=head->next;
            }
            else
            {
                ListNode*tmp=new ListNode(v[j--]);
                flag=true;
                head->next=tmp;
                head=head->next;
            }
         
        
        
        }
    }
};