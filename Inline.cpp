/*
Auther: John Blue
Time: 2022/6
Platform: atom
Object: to use inline

in the process of calling function, computer will have to remember the location of the status and return when function is end; that will cost time
instead,
in C, #define will unfold the function in the code literally, and the process would become more efficient
in C++, inline have the same purpose as #define, but it is more finer than the former
if function is too long and big, then avoid to use inline
if there have some ambuiguity related with the object or casting, then avoid to use inline

if inline is modified with static and the function is placed in header file
, it will make sure to expand the inline to whereever the function is used
, otherwise, compiler may still call the function as usual when the inline is not in the same coding block
*/

#include <iostream>
using namespace std;

static inline void print()
{
    cout << "hello world\n";
}

int main(void)
{
    print();
}
