/*
 *
 * virtual function
 * by parker0203 example in career cup
 *
 */


#include <iostream>

using namespace std;

class Shape{

  public:
    int edge_length;
    virtual int circumference(){
      cout << "Circumference of Base Class" << endl;
      return 0;
    }
};

class Triangle: public Shape{

  public:
    int circumference(){
      cout << "Circumference of Triangle Class" << endl;
      return 3 * edge_length;
    }
};

int main(){

  Shape *x = new Shape();
  x -> circumference();
  Shape *y = new Triangle();
  y -> circumference();

  return 0;
}
