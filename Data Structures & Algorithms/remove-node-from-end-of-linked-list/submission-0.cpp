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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fn = head;
        int cou=0,i=1;
        while(fn){
            cou++;
            fn=fn->next;
        }
        fn=head;
        if(cou==n){
            return head->next;
        }
        while(i<cou-n && fn){
            fn=fn->next;
            i++;
        }
        fn->next=fn->next->next;
        return head;
    }
};
