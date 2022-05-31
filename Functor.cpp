/*
Auther: John Blue
Time: 2022/6
Platform: atom
Object: to use functor

functor
is an object which can be "called" like a function,
and it has mememory.
*/

#include <iostream>
using namespace std;

// A Functor
class functor_mult
{
private:
    int num;
public:
    functor_mult(int n): num(n) {}

    // This operator overloading enables calling
    // operator function () on objects of multiplication
    int operator () (int m) const {
        return num * m;
    }
};

struct Sum
{
    void operator() (int n) {
      cout << n << " ";
      sum += n;
    }
    int sum{0};// the same ... int sum = 0;
};

// Driver code
int main()
{
    cout << "functor, transform, auto:\n";
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    transform(arr, arr + n, arr, functor_mult(3));
    for (int i = 0; i < n; i++) {
      cout << arr[i] << " ";
    }
    cout << "\n";
    for (auto ao : arr) {
      cout << ao << " ";
    }
    cout << "\n\n";

    cout << "functor, for_each:\n";
    Sum s = for_each(arr, arr + n, Sum());
    cout << "sum: " << s.sum << "\n\n";

    cout << "functor, lambda:\n";
    transform(arr, arr + n, arr, [](int x){ return 0; });
    cout << "\n";
    auto print = [](const int& n) { std::cout << " " << n; };
    std::for_each(arr, arr + n, print);
    cout << "\n";
    std::for_each(arr, arr + n, [](const int& n) { std::cout << " " << n; });
}
