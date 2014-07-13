/*
 *
 * largest people num in tower
 * by parker0203
 *
 */


#include <iostream>
#include <utility>
#include <vector>
#include <cassert>


using namespace std;

typedef vector<pair <int, int> > people_list;
typedef vector<pair <int, int> >::iterator people_iter;

people_list create_pair(){

  people_list p;
  p.push_back(make_pair(60, 100));
  p.push_back(make_pair(70, 150));
  p.push_back(make_pair(56, 90));
  p.push_back(make_pair(75, 190));
  p.push_back(make_pair(60, 95));
  p.push_back(make_pair(68, 90));

  return p;
}

people_list sort_people(people_list p){   // sorted by height first, then weight

  assert(p.size());
  people_list p_height;
  people_iter p_height_iter;
  p_height.push_back(p.at(0));
  for(int i = 1; i < p.size(); ++i){
    for(p_height_iter = p_height.begin(); ; ){
      if(p.at(i).first <= p_height_iter -> first){
        if(p.at(i).second <= p_height_iter -> second){
          p_height.insert(p_height_iter, p.at(i));
          break;
        }
      }
      if(++p_height_iter == p_height.end()){
        p_height.push_back(p.at(i));
        break;
      }
    }
  }

  return p_height;
}

void print_people_list(people_list p){

  for(int i = 0; i < p.size(); ++i){
    cout << p.at(i).first << " " << p.at(i).second << endl;
  }
  cout << endl;
}

int num_people(people_list p, int start){

  cout << p.size() << " " << start << endl;
  assert(start < p.size());
  int num = 1;
  int next = 0;
  for(++start; start < p.size(); ++start){
    if(p.at(start).second >= p.at(start - 1).second){
      ++num;
    }
    else{
      next = start;
    }
  }

  if(next != 0){
    int next_num = num_people(p, next);
    return num > next_num ? num : next_num;
  }

  return num;

}

int main(){

  people_list p = create_pair();
  print_people_list(p);

  people_list sorted_p = sort_people(p);
  print_people_list(sorted_p);

  cout << num_people(sorted_p, 0) << endl;

  return 0;
}
