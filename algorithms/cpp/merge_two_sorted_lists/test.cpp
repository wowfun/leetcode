#include"solution.cpp"

int main() {
  auto *head1 = new ListNode(1); // 1 2 3 4 5
  auto *head2 = new ListNode(0); // 0 1 2 3 4
  head1->next = nullptr;
  head2->next = nullptr;
  int i = 5;
  while (i > 1) {
    auto *p1 = new ListNode(i);
    auto *p2 = new ListNode(i - 1);
    p1->next = head1->next;
    p2->next = head2->next;
    head1->next = p1;
    head2->next = p2;
    i--;
  }

  auto *s1 = new Solution();
  ListNode *res_head = s1->mergeTwoLists(head1, head2);
  while (res_head != nullptr) {
    cout << res_head->val << ",";
    res_head = res_head->next;
  }

  return 0;
}

