/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* hare=head;
        ListNode* tortoise=head;
        while(hare&&hare->next)
        {
            hare=hare->next->next;
            tortoise=tortoise->next;
            if(hare==tortoise)
            {
                tortoise=head;
                while(tortoise!=hare)
                {
                    tortoise=tortoise->next;
                    hare=hare->next;
                }
                return hare;
            }
        }
        return nullptr;
        
    }
};
