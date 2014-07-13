/*
 *
 * return kth number represented by factors of 3, 5 and 7
 * by parker0203
 *
 */



#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

queue<int> Q3;
queue<int> Q5;
queue<int> Q7;
int result = 1;

int get_kth_num(int k){

  Q3.push(3);
  Q5.push(5);
  Q7.push(7);

  for(--k; k > 0; --k){
    result = min(Q3.front(), 
        min(Q5.front(), Q7.front()));
    if(result == Q7.front()){
      Q7.pop();
    }else{
      if(result == Q5.front()){
        Q5.pop();
      }else{
        Q3.pop();
        Q3.push(result * 3);
      }
      Q5.push(result * 5);
    }
    Q7.push(result * 7);
  }

  return result;
}


int main(){

  cout << get_kth_num(10) << endl;

  return 0;
}

