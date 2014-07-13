/*
 *
 * sort stack
 * by parker0203
 *
 */


#include <iostream>
#include <stack>

using namespace std;

void sort_stack(stack<int> &s){

  stack<int> r;
  while(!s.empty()){
    int tmp = s.top();
    s.pop();
    while(!r.empty() && tmp < r.top()){
      s.push(r.top());
      r.pop();
    }
    r.push(tmp);
  }

  while(!r.empty()){
    s.push(r.top());
    r.pop();
  }
}

int main(){

  stack<int> s;
  s.push(4);
  s.push(6);
  s.push(2);
  s.push(7);
  s.push(8);

  sort_stack(s);

  while(!s.empty()){
    cout << s.top() << endl;
    s.pop();
  }

  return 0;
}
