/*
 *
 * search in sorted string with NULL
 * by parker0203
 *
 */


#include <iostream>
#include <string>

using namespace std;


string *create_sorted_strings(){

  string *a = new string[10];
  a[0] = "at";
  a[1] = "basketball";
  a[2] = "";
  a[3] = "cenima";
  a[4] = "dad";
  a[5] = "";
  a[6] = "fast";
  a[7] = "google";
  a[8] = "home";
  a[9] = "icecream";

  return a;
}

void print_strings(string *s){

  cout << sizeof(s) << endl;
  for(int i = 0; i < 10; ++i){
    if(s[i] == ""){
      cout << "NULL ";
    }
    cout << s[i] << " ";
  }
  cout << endl;
}

int binary_search_string(string *s, string sample, int left, int right){

  if(left > right) return -1;
  int mid = (left + right) / 2;

  if(s[mid] == sample) return mid;
  if(s[mid] == ""){
    int l = binary_search_string(s, sample, left, mid - 1);
    int r = binary_search_string(s, sample, mid + 1, right);
    if(l > 0) return l;
    else if( r > 0) return r;
    else return -1;
  }
  if(s[mid] > sample) return binary_search_string(s, sample, left, mid - 1); // string < > ?
  if(s[mid] < sample) return binary_search_string(s, sample, mid + 1, right);

}

int main(){

  string *s = create_sorted_strings();
  print_strings(s);

  string sample = "iceman";
  int result = binary_search_string(s, sample, 0, 9);
  cout << result << endl;

  return 0;
}
