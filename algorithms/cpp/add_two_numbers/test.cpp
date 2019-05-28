#include <iostream>
using namespace std;

struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(NULL) {}
};

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

ListNode* createLinkListNum(int num) {
  int head = -1;
  ListNode* l=new ListNode(head);
  l->next = NULL;
  while (num > 0) {
    ListNode* p;
    p = new ListNode(num % 10);
    p->next = l->next;
    l->next = p;
    num = num / 10;
  }
  return l;
}

void printLinkList(ListNode* l) {
  ListNode* p;
  p = l->next;
  while (p) {
    cout<<p->val;
    p = p->next;
  }
  cout << endl;
}

void test() {
  ListNode* l1 = createLinkListNum(123);
  ListNode* l2 = createLinkListNum(5678);
  ListNode* l3;
  Solution* s1 = new Solution();
  l3 = s1->addTwoNumbers(l1, l2);
  printLinkList(l1);
  printLinkList(l2);
  printLinkList(l3);
}

int main() {
  test();
  return 0;
}