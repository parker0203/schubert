/*
 *
 * returen rand7 using rand5
 * by parker0203
 *
 */



#include <iostream>
#include <cstdlib>

using namespace std;

void test(){

  cout << time(NULL) << endl;
  cout << rand() % 20 << endl;
  cout << rand() % 20 << endl;
  cout << rand() % 20 << endl;
  cout << rand() % 20 << endl;
}

int rand5(){

  return rand() % 5 + 1;
}

int rand7(){

  while(true){
    int num = (rand5() - 1) * 5 + (rand5() - 1);
    if(num < 21) return num % 7 + 1;
  }
}

int main(){

  srand(time(NULL));
  cout << rand5() << endl;
  cout << rand7() << endl;


  return 0;
}
