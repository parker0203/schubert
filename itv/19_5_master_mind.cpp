/*
 *
 * Master Mind game
 * by parker0203
 *
 */



#include <iostream>
#include <string>
#include <map>

using namespace std;

pair<int, int> result(string guess, string solution){

  map<char, bool> hash;
  for(int i = 0; i < 4; ++i){
    hash[solution[i]] = 1;
  }
  int hit = 0, pseudo_hit = 0;
  for(int i = 0; i < 4; ++i){
    if(guess[i] == solution[i]){
      ++hit;
    }else if(hash.count(guess[i])){
      ++pseudo_hit;
    }
  }

  pair<int, int> res(hit, pseudo_hit);
  return res;
}

int main(){

  pair<int, int> res;
  string guess("YRGB"), solution("RGGB");
  res = result(guess, solution);
  cout << "hit: " << res.first << "\npseudo_hit: " << res.second << endl;

  return 0;
}
