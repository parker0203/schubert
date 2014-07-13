/*
 *
 * fibonacci recursive and iterative
 * by parker0203
 *
 */



#include <iostream>

using namespace std;

int fibo(int n){

  if(n == 0){
    return 0;
  }else if(n == 1){
    return 1;
  }else if(n > 1){
    return fibo(n - 1) + fibo(n - 2);
  }else{
    cout << "error" << endl;
    return -1;
  }
}

int fibo_iter(int n){

  if(n < 0){
    cout << "error" << endl;
    return -1;
  }else if(n == 0){
    return 0;
  }
  int a = 1, b = 1;
  for(int i = 3; i <= n; ++i){
    int c = a + b;
    a = b;
    b = c;
  }
  return b;
}

int main(){

  cout << fibo(5) << endl;
  cout << fibo(4) << endl;
  cout << fibo(10) << endl;
  cout << fibo(0) << endl;
  cout << fibo(1) << endl;

  cout << endl;

  cout << fibo_iter(5) << endl;
  cout << fibo_iter(4) << endl;
  cout << fibo_iter(10) << endl;
  cout << fibo_iter(0) << endl;
  cout << fibo_iter(1) << endl;

  return 0;
}
