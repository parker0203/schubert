/*
 * longest substring without repeate
 * checked on leetcode
 */

#include <iostream>
#include <string.h>

using namespace std;

int lengthOfLongestSubstring(string s) {
  // Start typing your C/C++ solution below
  // DO NOT write int main() function
  int index[256] = {};
  int res = 0;
  int counter = 0;
  for(int i = 0; i < s.length(); ){
    if(index[s[i]] != 0){
      if(res < counter){
        res = counter;
      }
      counter = 0;
      i = index[s[i]];
      bzero(index, 256 * sizeof(int));
    }else{
      index[s[i]] = ++i;
      ++counter;
    }
  }
  if(counter > res)
    res = counter;

  return res;
}

int main(){
  string a = "abcabcbb";
  cout << lengthOfLongestSubstring(a) << endl; 
}
