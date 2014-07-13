/*
 *
 * implement queue with two stacks
 * by parker 0203
 *
 */



#include <iostream>
#include <stack>

using namespace std;

class stack_to_queue{

  public:
    stack<int> s1, s2;
    int size();
    void add(int );
    int peek();
    int remove();
};

int stack_to_queue::size(){

  return s1.size() + s2.size();
}

void stack_to_queue::add(int item){

  s1.push(item);
}

int stack_to_queue::peek(){

  if(!s2.empty()) return s2.top();
  while(!s1.empty()){
    s2.push(s1.top());
    s1.pop();
  }
  return s2.top();
} 

int stack_to_queue::remove(){

  if(!s2.empty()){
    int res = s2.top();
    s2.pop();
    return res;
  } 
  while(!s1.empty()){
    s2.push(s1.top());
    s1.pop();
  }
  int res = s2.top();
  s2.pop();
  return res;
}

int main(){

  stack_to_queue to_queue;
  for(int i = 5; i < 9; ++i){
    to_queue.add(i);
  }

  cout << "size is:" << to_queue.size() << endl;

  for(int i = 0; i < 3; ++i){
    cout << to_queue.remove() << endl;
  }
  cout<< "removed 3 item"<< endl;

  to_queue.add(35);
  to_queue.add(45);
  to_queue.add(55);
  to_queue.add(65);

  cout << "peek: " << to_queue.peek() << endl;

  while(to_queue.size()){
    cout << to_queue.remove() << endl;
  }

  cout << "size is: " << to_queue.size() << endl;

  return 0;
}
