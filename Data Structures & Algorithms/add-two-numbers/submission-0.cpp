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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
      int a = 0,c=0;
      int y = l1->val + l2->val + c;
         a = y%10 ;
         c = y/10;
        ListNode* l3 = new ListNode(a);
        l1 = l1->next;
        l2 = l2->next;
        ListNode* curr =l3;
      while(l1 && l2){
        int y = l1->val + l2->val + c;
         a = y%10 ;
         c = y/10;
        ListNode* node = new ListNode(a);
        l1 = l1->next;
        l2 = l2->next;
        curr->next = node;
        curr = curr->next;
      }
      while(l1){
        int y = l1->val + c;
        a = y%10;
        c = y/10;
        ListNode* node = new ListNode(a);
        l1=l1->next;
        curr->next = node;
        curr = curr->next;    
      }
      while(l2){
        int y = l2->val + c;
        a = y%10;
        c = y/10;
        ListNode* node = new ListNode(a);
        l2=l2->next;
        curr->next = node;
        curr = curr->next;     
      }
      if(c>0){
        ListNode* node = new ListNode(c);
        curr->next = node;
        curr = curr->next; 
      }
      return l3;
    }
};