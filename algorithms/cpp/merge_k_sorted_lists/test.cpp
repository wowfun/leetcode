#include"solution.cpp"

int main() {
  auto *head1 = new ListNode(1); // 1 2 3 4 5
  auto *head2 = new ListNode(0); // 0 1 2 3 4
  auto *head3 = new ListNode(-1); // -1 0 1 2 3
  head1->next = nullptr;
  head2->next = nullptr;
  int i = 5;
  while (i > 1) {
    auto *p1 = new ListNode(i);
    auto *p2 = new ListNode(i - 1);
    auto *p3 = new ListNode(i - 2);
    p1->next = head1->next;
    p2->next = head2->next;
    p3->next = head3->next;
    head1->next = p1;
    head2->next = p2;
    head3->next = p3;
    i--;
  }

  vector<ListNode *> lists;
  lists.push_back(head1);
  lists.push_back(head2);
  lists.push_back(head3);

  auto *s1 = new Solution();
  ListNode *res_head = s1->mergeKLists(lists);
  while (res_head != nullptr) {
    cout << res_head->val << ",";
    res_head = res_head->next;
  }

  return 0;
}

