#include"solution.cpp"

int main(){
  auto s1=new Solution();
  auto res=s1->generate(5);
  for(auto & re : res){
    for(int j : re){
      cout<<j<<",";
    }
    cout<<endl;
  }
  return 0;
}

