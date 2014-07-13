/*
 *
 * print num in en
 * by parker0203
 *
 */



#include <iostream>


using namespace std;


string word1[] = {"", "One ", "Two ", "Three ", "Four ", "Five", 
  "Six ", "Seven ", "Eight ", "Nine ", 
  "Ten ", "Eleven ", "Twelve ", "Thirteen ", "Fourteen ", "Fifteen", 
  "Sixteen ", "Seventeen ", "Eighteen ", "Nineteen "};
string word10[] = {"", "Ten ", "Twenty ", "Thirty ", "Forty ", "Fifty ", 
  "Sixty ", "Seventy ", "Eighty ", "Ninety "};
string word1000[] = {"", "Thousand ", "Million "};


void print_num(int num, int level){

  if(num == 0){
    if(level == 0){
      cout << "Zero" << endl;
    }
    return;
  }


  int upper;
  int lower;
  upper = num / 1000;
  lower = num - upper * 1000;
  print_num(upper, level + 1);

  //handle lower 1000 number
  int temp;
  temp = lower / 100;
  if(temp > 0){
    cout << word1[temp] << "Hundred and ";
  }

  lower -= temp * 100;
  if(lower < 20){
    cout << word1[lower];
  }else{
    cout << word10[lower / 10] << word1[lower % 10];
  }

  if(level > 0){
    cout << word1000[level] << ", ";
  }else{
    cout << endl;
  }

}

int main(){

  print_num(99909919, 0);

  return 0;
}
