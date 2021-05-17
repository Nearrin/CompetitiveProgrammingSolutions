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
    ListNode* removeElements(ListNode* head, int val) {
        if(!head)return 0;
        if(head->val==val)return removeElements(head->next,val);
        auto tmp=removeElements(head->next,val);
        head->next=tmp;
        return head;
    }
};
