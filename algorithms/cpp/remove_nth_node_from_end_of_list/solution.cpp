#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// Solution 1 (better)
class Solution {
public:
  ListNode *removeNthFromEnd(ListNode *head, int n) {
    ListNode *fast = head, *slow = head;
    for (int i = 0; i < n; ++i)
      fast = fast->next;

    if (fast == NULL)
      return head->next;

    while (fast->next != NULL) {
      fast = fast->next;
      slow = slow->next;
    }
    // ListNode *to_del = slow->next;
    slow->next = slow->next->next;
    // delete to_del;
    return head;
  }
};

// Solution 2
class Solution1 {
public:
  ListNode *removeNthFromEnd(ListNode *head, int n) {
    ListNode *p = head;
    int len_list = 0;
    while (p != NULL) {
      len_list++;
      p = p->next;
    }
    if (n == len_list)
      return head->next;
    p = head;
    for (int i = 0; i < len_list - n - 1; i++) {
      p = p->next;
    }
    // ListNode *to_del = p->next;
    p->next = p->next->next;
    // delete to_del;
    return head;
  }
};


