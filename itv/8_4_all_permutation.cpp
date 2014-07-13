/*
 *
 * print all permutations of a string
 * by parker0203
 *
 */



#include <iostream>
#include <string>

using namespace std;

void print_permutation(string temp, string s){

  string::size_type size = s.size();
  if(size == 1){
    cout << temp + s << endl;
    return;
  }else{
    for(int i = 0; i < size; ++i){
      string temp_temp = temp + s[i];
      string temp_s = s;
      print_permutation(temp_temp, temp_s.erase(i, 1));
    }
  }

}

int main(){

  string temp;
  string s("abcde");
  print_permutation(temp, s);

  return 0;
}
