
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* rabbit=head;
        ListNode* tortoise=head;
        while(rabbit&&rabbit->next)
        {
            tortoise=tortoise->next;
            rabbit=rabbit->next->next;
            if(rabbit==tortoise)
            {
                return true;
            }
        }
        return false;
        
    }
};
