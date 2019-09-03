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
      // read from right to left, first,
      // it's a variable called node, then it's a reference ,then the reference points to a pointer,
      // then the pointer points to a ListNode, so node is a reference points to pointer which points to a ListNode.
      tail = tail->next = node;
      node = node->next;
    }
    tail->next = l1 ? l1 : l2;
    return head.next;
  }
};

// recursion
class Solution2 {
public:
  ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
    if (!l1 || !l2) {
      return l1 ? l1 : l2;
    }
    if (l1->val < l2->val) {
      l1->next = mergeTwoLists(l1->next, l2);
      return l1;
    }
    l2->next = mergeTwoLists(l1, l2->next);
    return l2;
  }
};