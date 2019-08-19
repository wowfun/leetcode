#include<iostream>
#include <vector>

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

  ListNode *mergeKLists(vector<ListNode *> &lists) {
    if (lists.empty()) return NULL;
    int len_lists = lists.size();
    while (len_lists > 1) {
      for (int i = 0; i < len_lists / 2; i++) {
        lists[i] = mergeTwoLists(lists[i], lists[len_lists - 1 - i]);
      }
      len_lists = (len_lists + 1) / 2;
    }
    return lists.front();
  }
};