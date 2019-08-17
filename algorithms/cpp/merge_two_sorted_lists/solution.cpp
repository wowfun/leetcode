#include<iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
    ListNode head(0);
    ListNode *tail = &head;
    while (l1 && l2) {
      ListNode *&node = l1->val < l2->val ? l1 : l2;
      tail = tail->next = node;
      node = node->next;
    }
    tail->next = l1 ? l1 : l2;
    return head.next;
  }
};