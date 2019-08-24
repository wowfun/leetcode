#include<iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  ListNode *swapPairs(ListNode *head) {
    ListNode **pp = &head, *a, *b;
    while ((a = *pp) && (b = a->next)) {
      a->next = b->next;
      b->next = a;
      *pp = b;
      pp = &(a->next);
    }
    return head;
  }
};

// recursion
// invert the first 2 and then recurse for the rest
class Solution2 {
public:
  ListNode *swapPairs(ListNode *head) {
    if (!head || !head->next) return head;
    ListNode *tmp = head->next;
    head->next = swapPairs(tmp->next);
    tmp->next = head;
    return tmp;
  }
};
