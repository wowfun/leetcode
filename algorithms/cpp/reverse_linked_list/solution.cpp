#include<iostream>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  ListNode *reverseList(ListNode *head) {
    ListNode *curr_head = NULL;
    while (head) {
      ListNode *nxt = head->next;
      head->next = curr_head;
      curr_head = head;
      head = nxt;
    }
    return curr_head;
  }
};

// recursion
class Solution2 {
public:
  ListNode *reverseList(ListNode *head) {
    if (!head || !(head->next)) {
      return head;
    }
    ListNode *node = reverseList(head->next);
    head->next->next = head;
    head->next = NULL;
    return node;
  }
};