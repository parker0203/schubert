/*
 *
 * print last k lines in file
 * by parker0203
 *
 */



#include <iostream>
#include <fstream>

using namespace std;

void print_last(ifstream &in, int k){

  string last[k];
  int lines = 0;
  while(!in.eof()){        //same when use (in.good())
    getline(in, last[lines % k]);
    ++lines;
  }

  int start, count;
  if(lines < k){
    start = 0;
    count = lines;
  }else{
    start = lines % k;
    count = k;
  }
  cout << lines << endl;
  cout << start << endl;

  for(int i = 0; i < count; ++i){
    cout << i << ": "<< last[(start + i) % k] << endl;
  }
}

void print_last2(int k){

  string last[k];
  int lines = 0;
  freopen("13_1.txt", "r", stdin);
  string temp;

  while(getline(cin, temp)){
    last[lines % k] = temp;
    ++lines;
  }

  int start, count;
  if(lines < k){
    start = 0;
    count = lines;
  }else{
    start = lines % k;
    count = k;
  }
  cout << lines << endl;
  cout << start << endl;

  for(int i = 0; i < count; ++i){
    cout << i << ": " << last[(start + i) % k] << endl;
  }
}


int main(){

  ifstream in("13_1.txt");
  cout << "print_last" << endl;
  print_last(in,5);
  cout << endl;

  cout << "print_last2" << endl;
  print_last2(5);

  return 0;
}
