/*
Auther: John Blue
Time: 2022/6
Platform: atom
Object: to use reference in C++
*/

#include <iostream>

class Object {
public:
  Object() {
    std::cout << "Create object" << std::endl;
  }
  ~Object() {}
};

int main()
{
  const int av = 3;

  // reference a const
  const int& ar = av;

  // const reference a non const
  int bc = av;// copy const
  const int& br = bc;
  //br = 33;// not workable, it is const

  Object obj;

  // reference an object
  //Object& agent;// not allowed
  Object& agent = obj;
}
