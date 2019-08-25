#include"solution.cpp"

int main(){
  auto *head = new ListNode(1);
  head->next = nullptr;
  int i = 5;
  while (i > 1) {
    auto *p = new ListNode(i);
    p->next = head->next;
    head->next = p;
    i--;
  }
  auto *p = head;
  while (p != nullptr) {
    cout << p->val << ',';
    p = p->next;
  }
  cout << endl;

  auto *s1 = new Solution();
  ListNode *res_head = s1->reverseList(head);
  while (res_head != nullptr) {
    cout << res_head->val << ",";
    res_head = res_head->next;
  }

  return 0;
}

