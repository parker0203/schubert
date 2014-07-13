/*
 *
 * sort sorted string with quick sort and hash table
 * by parker0203
 *
 */


#include <iostream>
#include <string>
#include <cstring>

using namespace std;

string *create_strings(){

  string *s = new string[10];
  cout<< "input 10 strings: " << endl;
  for(int i = 0; i < 10; ++i){
    cout<< i + 1 << "th string is: ";
    cin >> s[i];
  }

  return s;
}

void print_strings(string *s){

  for(int i = 0; i < 10; ++i){
    cout<< "the " << i + 1 << "th string is: " << s[i] << endl;
  }
  cout<<endl;
}

void sort_string(string &s){

  if(s.empty()) return;
  string::size_type s_size = s.size();
  int hash_table[256];
  memset(hash_table, 0, sizeof(hash_table));
  for(int i = 0; i < s_size; ++i){
    ++hash_table[(int)s[i]];
  }
  for(int i = 0, j = 0; i < 256; ){
    if(hash_table[i] != 0){
      s[j++] = (char)i;
      --hash_table[i];
    }else{
      ++i;
    }
  }

}

/*
   void swap_string(string *s1, string *s2){

   string *temp = s1;
   s1 = s2;
   s2 = temp;
   }
   */


void quicksort_strings(string *s, int left, int right){

  if(left >= right) return;
  string pivot = s[left]; // use the first element as pivot
  int i, j;
  for(i = left + 1, j = left; i <= right; ++i){
    if(pivot.compare(s[i]) > 0){
      s[i].swap(s[j + 1]);
      //	swap_string(&s[i], &s[j + 1]);
      ++j;
    }
  }
  s[j].swap(s[left]);
  //	swap_string(&s[j], &s[left]);


  quicksort_strings(s, left, j - 1);
  quicksort_strings(s, j + 1, right);

}

int main(){

  string *s = create_strings();
  for(int i = 0; i < 10; ++i){
    sort_string(s[i]);
  }
  print_strings(s);
  quicksort_strings(s, 0, 9);
  print_strings(s);

  return 0;
}
