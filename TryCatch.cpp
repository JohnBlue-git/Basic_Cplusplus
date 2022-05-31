/*
Auther: John Blue
Time: 2022/6
Platform: atom
Object: display how to use try catch
*/

#include <iostream>
#include <typeinfo> // operator typeid
#include <exception> // std::exception

class Polymorphic {virtual void member(){}};

int main () {
  // try block 1
  try
  {
    Polymorphic* pb = 0;
    std::cout << typeid(*pb).name() << std::endl;// throws a bad_typeid exception, since pb == 0
  }
  catch (std::exception& e)
  {
    std::cout << "try block1:\n" << "exception caught: " << e.what() << "\n" << std::endl;
  }

  // try block 2
  try
  {
    int div = 0;
    std::cout << "try block2:\n";
    //std::cout <<  << "address of div: " << &div << std::endl;
    if(div == 0)
    {
       throw div;//throw "Division by zero condition!";
    }
    return (3 / div);
  }
  catch (int& e)
  {
    std::cout << "num: " << e;
    //std::cout << "addres of e: " << &e << std::endl;// note that e == div but the address is different
  }
}
