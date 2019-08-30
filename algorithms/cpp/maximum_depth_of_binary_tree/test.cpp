#include"solution.cpp"

int main(){
  auto bt=new TreeNode(3);
  bt->left=new TreeNode(9);
  bt->right=new TreeNode(20);
  bt->right->left=new TreeNode(15);
  bt->right->right=new TreeNode(7);

  auto s1=new Solution();
  cout<<s1->maxDepth(bt);

  return 0;
}

