/*
 *
 * remove duplicates from an unsorted list
 * using list in C++
 * by parker0203
 *
 */


#include <iostream>
#include <list>
#include <cstring>

using namespace std;

void print_list(list<int> &mylist){  // print all data in list

  list<int>::iterator myiter;
  for(myiter = mylist.begin(); myiter != mylist.end(); ++myiter){
    cout<<*myiter<<" ";
  }
  cout<<endl;
  cout<<"list size is "<<mylist.size()<<endl;
  //	cout<<"list capacity is "<<mylist.capacity()<<endl; //no capacity in list
}

void add_dummy_data(list<int> &mylist){ // add 10 dummy data

  for(int i = 0; i < 10; ++i){
    mylist.push_back(i);
  }
}

void add_dup_data(list<int> &mylist){  // add some duplicated data

  for(int i = 0; i < 10; ++i){
    mylist.push_back(i * 2);
  }

}

void remove_dup_hash(list<int> &mylist){   //remove dup using hash table

  int hash_table[100];
  memset(hash_table, 0, sizeof(hash_table));
  list<int>::iterator myiter;
  for(myiter = mylist.begin(); myiter != mylist.end(); ){
    if(hash_table[*myiter] == 1){
      mylist.erase(myiter++); // erase(iter) returns the first element of list, myiter++ will reserve the next iter so it would be Ok
    }
    else{
      hash_table[*myiter++] = 1;
    }	
  }

}

void remove_dup_nobuffer(list<int> &mylist){  //using no buffer (remove front dup)

  list<int>::iterator iter_check; //check dup with myiter
  list<int>::iterator iter_myiter;

  for(iter_myiter = ++mylist.begin(); iter_myiter != mylist.end();++iter_myiter){
    for(iter_check = mylist.begin(); iter_check != iter_myiter; ++iter_check){
      if(*iter_check == *iter_myiter){
        mylist.erase(iter_check++); //remove the front dup
        break;
      }
    }
  }
}

int main(){

  list<int> mylist;
  add_dummy_data(mylist);
  add_dup_data(mylist);
  print_list(mylist);

  //	remove_dup_hash(mylist);
  remove_dup_nobuffer(mylist);
  print_list(mylist);

  return 0;

}
