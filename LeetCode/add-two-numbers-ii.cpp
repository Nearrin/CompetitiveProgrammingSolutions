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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        vector<int>a,b;
        while(l1){
            a.push_back(l1->val);
            l1=l1->next;
        }
        while(l2){
            b.push_back(l2->val);
            l2=l2->next;
        }
        reverse(begin(a),end(a));
        reverse(begin(b),end(b));
        int carry=0;
        while(a.size()<b.size())a.push_back(0);
        while(b.size()<a.size())b.push_back(0);
        for(int i=0;i<a.size();++i){
            a[i]+=carry+b[i];
            carry=a[i]/10;
            a[i]%=10;
        }
        if(carry)a.push_back(carry);
        //reverse(begin(a),end(a));
        ListNode*p=0;
        for(int i=0;i<a.size();++i){
            auto tmp=new ListNode(a[i]);
            tmp->next=p;
            p=tmp;
        }
        return p;
    }
};
