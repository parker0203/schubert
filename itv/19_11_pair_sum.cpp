/*
 *
 * find pairs sum to a specific value
 * by parker0203
 *
 */


#include <iostream>
#include <utility>
#include <vector>
#include <map>

using namespace std;


vector<pair<int, int> > sum_pair(int a[], int sum, int size){

  map<int, int> sum_map;
  vector<pair<int, int> > res;
  for(int i = 0; i < size; ++i){
    if(sum_map[sum - a[i]]){
      res.push_back(make_pair(sum - a[i], a[i]));
    }else{
      sum_map[a[i]] = 1;
    }
  }

  return res;
}

int main(){

  vector<pair<int, int> > res;
  int a[10];
  for(int i = 0; i < 10; ++i){
    a[i] = i;
  }
  res = sum_pair(a, 7, 10);

  for(int i = 0; i < res.size(); ++i){
    cout << res[i].first << " " << res[i].second << endl;
  }

  return 0;
}
