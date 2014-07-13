#include <iostream>
#include <string>

using namespace std;

/*
 * a hash routine for string objects
 * a good routine
 */
int hash(const string &key, int table_size){
  
  int hash_val = 0;
  for(int i = 0; i < key.length(); ++i){
    hash_val = 37 * hash_val + key[i];
  }

  hash_val %= table_size;
  if(hash_val < 0){
    hash_val += table_size;  // not necessary in most case
  }

  return hash_val;
}

int main(){
  string str1 = "Hello";
  string str2 = "World";

  cout << hash(str1, 10) << endl;
  cout << hash(str2, 10) << endl;
}
