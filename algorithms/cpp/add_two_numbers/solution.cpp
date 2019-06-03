/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}  // Constructor
 * };
 */

class Solution {
 public:
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    int sum = 0;
    ListNode* l3 = NULL;
    ListNode** p = &l3;
    while (l1 != NULL || l2 != NULL) {
      if (l1 != NULL) {
        sum += l1->val;
        l1 = l1->next;
      }
      if (l2 != NULL) {
        sum += l2->val;
        l2 = l2->next;
      }
      (*p) = new ListNode(sum % 10);
      sum /= 10;
      p = &((*p)->next);
    }
    if (sum > 0) {
      *p = new ListNode(sum);
      p = &((*p)->next);
    }
    return l3;
  }
};