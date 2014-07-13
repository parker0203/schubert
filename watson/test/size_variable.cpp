/*
 * size of variable
 */

#include <iostream>

using namespace std;

void val_size_test(){

  cout << "bool size: " << sizeof(bool) << endl;                      /* bool size: 1 */
  cout << "char size: " << sizeof(char) << endl;                      /* char size: 1 */
  cout << "short int size: " << sizeof(short int) << endl;            /* short int size: 2 */
  cout << "short size: " << sizeof(short) << endl;                    /* short size: 2 */
  cout << "int size: " << sizeof(int) << endl;                        /* int size: 4 */
  cout << "double size: " << sizeof(double) << endl;                  /* double size: 8 */
  cout << "float size: " << sizeof(float) << endl;                    /* float size: 4 */
  cout << "long size: " << sizeof(long) << endl;                      /* long size: 8 */
  cout << "long int size: " << sizeof(long int) << endl;              /* long int size: 8 */
  cout << "long long size: " << sizeof(long long) << endl;            /* long long size: 8 */
  cout << "long long int size: " << sizeof(long long int) << endl;    /* long long int size: 8 */
  cout << "long double size: " << sizeof(long double) << endl;        /* long double size: 16 */

}

void ptr_size_test(){
  /* all pointer size is 8, include function pointer and class */
  cout << "char size: " << sizeof(char *) << endl;
  cout << "short int size: " << sizeof(short int *) << endl;
  cout << "short size: " << sizeof(short *) << endl;
  cout << "int size: " << sizeof(int *) << endl;
  cout << "double size: " << sizeof(double *) << endl;
  cout << "float size: " << sizeof(float *) << endl;
  cout << "long size: " << sizeof(long *) << endl;
  cout << "long int size: " << sizeof(long int *) << endl;
  cout << "long long size: " << sizeof(long long *) << endl;
  cout << "long long int size: " << sizeof(long long int *) << endl;
  cout << "long double size: " << sizeof(long double *) << endl;

}

int main(){

  cout << "value" << endl;
  val_size_test();
  cout << endl;
  cout << "pointer" << endl;
  ptr_size_test();

  return 0;
}
