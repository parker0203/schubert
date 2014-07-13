/*
 *
 * find the nth to last element
 * using list in C++
 * by parker0203
 *
 */


#include <iostream>
#include <list>

using namespace std;

void print_list(list<int> &mylist){  // print all data in list

  list<int>::iterator myiter;
  for(myiter = mylist.begin(); myiter != mylist.end(); ++myiter){
    cout << *myiter << " ";
  }
  cout << endl;
  cout << "list size is " << mylist.size() << endl;
  //	cout<<"list capacity is "<<mylist.capacity()<<endl; //no capacity in list
}

void add_dummy_data(list<int> &mylist){ // add 11 dummy data

  for(int i = 0; i < 11; ++i){
    mylist.push_back(i);
  }
}

void print_nth(list<int> &mylist, int n){

  if(n < 1) return;
  if(n > mylist.size()) return;
  list<int>::iterator myiter = mylist.begin(), nth_iter = mylist.begin();
  for(int i = 0; i < n; ++i){     //it is definitely n, not n - 1
    ++myiter;
  }
  for( ; myiter != mylist.end(); ++myiter){
    ++nth_iter;
  }
  cout << "last " << n << " th element is: " << *nth_iter << endl;
}

int main(){

  list<int> mylist;
  add_dummy_data(mylist);
  print_list(mylist);
  print_nth(mylist, 3);
  print_nth(mylist, 11);
  print_nth(mylist, 51);

  return 0;

}

