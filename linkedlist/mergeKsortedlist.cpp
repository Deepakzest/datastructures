
class Solution {
public:
    ListNode* merge2lists(ListNode *l1,ListNode *l2)
    {
        ListNode* dummy=new ListNode();
        ListNode*curr=dummy;
        while(l1!=NULL&&l2!=NULL)
        {
            if(l1->val<l2->val)
            {
                curr->next=l1;
                l1=l1->next;
            }
            else
            {
                curr->next=l2;
                l2=l2->next;
            }
            curr=curr->next;
        }
        curr->next=(l1!=NULL)?l1:l2;
        return dummy->next;
    }
    ListNode* mergeKlistshelper(vector<ListNode*>&lists,int start,int end)
    {
        if(start==end)return lists[start];
        if(start+1==end) return merge2lists(lists[start],lists[end]);
        int mid=start+(end-start)/2;
        ListNode* left=mergeKlistshelper(lists,start,mid);
        ListNode* right=mergeKlistshelper(lists,mid+1,end);
        return merge2lists(left,right);
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()||lists.size()==0)
        {
            return nullptr;
        }
        return mergeKlistshelper(lists,0,lists.size()-1);
        
    }
};
