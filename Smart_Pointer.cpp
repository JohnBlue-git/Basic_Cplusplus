/*
Auther: John Blue
Time: 2022/6
Platform: atom
Object: to use smart pointer
Reference:
smaprt pointer
https://kheresy.wordpress.com/2012/03/03/c11_smartpointer_p1/
smart pointer is in <momory>
https://stackoverflow.com/questions/18078153/error-unique-ptr-is-not-a-member-of-std
*/

#include <iostream>
#include <vector>// for vector
#include <memory>// for smart pointer
using namespace std;

int main()
{
  // traditionally, we have to delete(free) arr before the end of main()
  //vector<int>* arr = new vector<int>();
  //arr->push_back(3);
  //delete arr;

  // with help of smart pointer, arr will be collected auomatically. the trade off is some space consumption.
  unique_ptr<vector<int>> arr(new vector<int>());
  arr->push_back(3);

  unique_ptr<int> ptr(new int);
  *ptr = 3;

  // there are 3 to 4 kinds of smart pointer in C++
  // auto_ptr, unique_ptr, shared_ptr, weak_ptr
  // ...
}
