#include"solution.cpp"

int main() {
  auto *head1 = new ListNode(1); // 1 2 3 4 5
  head1->next = nullptr;
  int i = 5;
  while (i > 1) {
    auto *p1 = new ListNode(i);
    auto *p2 = new ListNode(i - 1);
    p1->next = head1->next;
    head1->next = p1;
    i--;
  }

  auto *s1 = new Solution();
  ListNode *res_head = s1->swapPairs(head1);
  while (res_head != nullptr) {
    cout << res_head->val << ",";
    res_head = res_head->next;
  }

  return 0;
}
