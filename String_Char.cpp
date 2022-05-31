/*
Auther: John Blue
Time: 2022/6
Platform: atom
Object: transformation among string char*
*/

#include <iostream>
#include <string.h>// for strcpy
using namespace std;

int main ()
{
  // construct string from char*
  char* one = "char";
  string two(one);
  two += one;
  cout << two << endl;

  // copy string to char*
  string str = "string";
  char* cstr = new char[str.length() + 1];
  strcpy(cstr, str.c_str());
  cout << cstr << endl;

  // free stuff
  delete [] cstr;
}
