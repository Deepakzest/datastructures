class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* rabbit=head;
        ListNode* tortoise=head;
        while(rabbit&&rabbit->next)
        {
            rabbit=rabbit->next->next;
            tortoise=tortoise->next;
        }
        return tortoise;
    }
};
