/*
Auther: John Blue
Time: 2022/6
Platform: atom
Object: to display passing and returning in C++
*/

#include <iostream>
using namespace std;

////// passing ...

// passing variable by reference
void fun1(int& x) {
  cout << "variable = " << x << "\n";
}

// passing array by reference
// template array
template <typename T, size_t M, size_t N>
void fun2(const T (&x)[M][N]) {
cout << "array =\n";
  for (int i = 0; i < M; i++) {
    for (int j = 0; j < N; j++) {
        cout << x[i][j] << ",";
    }
    cout << "\n";
  }
  //int matrix[M];// allowed? yes
}

// passing variable by pointer
void fun3(int* x) {
  cout << "variable = " << *x << "\n";
}

// passing array by pointer
void fun4(int* x, int m, int n) {
  cout << "array =\n";
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      cout << *(x + i * n + j) << ",";
    }
    cout << "\n";
  }
}

// passing array by pointer
void fun5(int x[2][1]) {
  cout << "array =\n";
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 1; j++) {
      cout << x[i][j] << ",";
    }
    cout << "\n";
  }
}

// passing array by pointer
void fun6(int** x, int m, int n) {
  cout << "array =\n";
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      cout << x[i][j] << ",";
    }
    cout << "\n";
  }
}

////// returing
int sz = 2;
int** fun7() {
  int** x = new int*[sz];
  for (int i = 0; i < sz; i++) {
    x[i] = new int;
    x[i][0] = i;
  }
  return x;
}

////// Object

class CS {
public:
    CS(){
      cout << "default construct" << endl;
    }
    CS(const CS& copy){
      cout << "copy construct" << endl;
    }
    CS& operator=(const CS& copy){
      cout << "assign operation" << endl;
      return *this;
    }
    ~CS(){}
};

CS new_instance() {
  CS rt;
  return rt;
}


int main () {
  ////// passing


  ////// returning



  ////// (object) construction optimization
  // sometimes the reurning have been optimmized with copy constructor mechnism
  // so there would have no other kinds of object construction or assignment
  cout << "Object construction ..." << endl;
  cout << "1: ";
  CS ori;
  // copying
  cout << "2: ";
  CS cp(ori);
  cout << "3: ";
  CS rt = new_instance();
  cout << "4: ";
  CS as1 = ori;
  // assigment
  CS as2;
  cout << "5: ";
  as2 = ori;
  //
  cout << "\n";









  ////// passing
  cout << "Passing ..." << endl;

  //// by reference
  // note that variable and obkect can pass by reference in C++
  cout << "pass by reference" << endl;
  int v_r = 3;
  fun1(v_r);
  int a_r[2][1] = {{0},{1}};
  fun2(a_r);
  fun2({{0},{1}});
  //
  cout << "\n";

  //// by pointer
  cout << "Pass by pointer" << endl;
  fun3(&v_r);
  fun4((int*)a_r, 2, 1);
  //fun4((int*){{0},{1}}, 2, 1);// not allowed
  fun5(a_r);
  //
  int** alc = new int*[2];
  for (int i = 0; i < 2; i++) {
    alc[i] = new int;
    alc[i][0] = i;
  }
  fun6(alc, 2, 1);
  for (int i = 0; i < 2; i++) {
    delete[] alc[i];
  }
  delete[] alc;
  //
  cout << "\n";


  ////// returning
  cout << "return ..." << endl;
  cout << "return array by pointer" << endl;
  int** arr = fun7();
  for (int i = 0; i < sz; i++) {
    cout << arr[i][0] << ",\n";
  }
  for (int i = 0; i < sz; i++) {
    delete[] arr[i];
  }
  delete[] arr;
}
