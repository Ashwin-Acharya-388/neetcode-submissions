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
        ListNode* fn = head;
        ListNode* sn = head;
        while(fn && fn->next){
            fn=fn->next->next;
            sn=sn->next;
        }
        ListNode * curr = sn->next;
        ListNode * prev = sn->next = nullptr;
        ListNode * next;
        while(curr){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        ListNode* first = head;
        ListNode* sec = prev;
        while(sec){
            ListNode* t1 = first->next;
            ListNode* t2 = sec->next;
            first->next = sec;
            sec->next = t1;
            first= t1;
            sec= t2;
        }
    }
};
