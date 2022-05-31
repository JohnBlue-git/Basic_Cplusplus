/*
Auther: John Blue
Time: 2022/6
Platform: atom
Object: to use container
Reference: https://www.cplusplus.com/reference/stl/
*/

#include <iostream>

#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>

#include <list>
#include <stack>          // std::stack
#include <deque>          // std::deque

#include <utility>      // std::pair, std::make_pair
#include <tuple>

using namespace std;

template<class T>
void auto_show(vector<T>& x) {
  // Basic 10-element integer array.
  //int x[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
  // or
  //vector<int> x; x.push_back(...) ...

  cout << "(y : x):\n";
  // Range-based for loop to iterate through the array.
  for( int y : x ) { // Access by value using a copy declared as a specific type.
                     // Not preferred.
      cout << y << " ";
  }
  cout << "\n";

  cout << "(auto y : x):\n";
  // The auto keyword causes type inference to be used. Preferred.
  for( auto y : x ) { // Copy of 'x', almost always undesirable
      cout << y << " ";
  }
  cout << "\n";

  cout << "(auto &y : x):\n";
  for( auto &y : x ) { // Type inference by reference.
      // Observes and/or modifies in-place. Preferred when modify is needed.
      cout << y << " ";
  }
  cout << "\n";

  cout << "(const auto &y : x):\n";
  for( const auto &y : x ) { // Type inference by const reference.
      // Observes in-place. Preferred when no modify is needed.
      cout << y << " ";
  }
  cout << "\n";
}

template<class T>
void double_show(const vector<vector<T>>& x) {
  cout << "iteration:\n" << endl;
  for (auto IT = x.begin(); IT != x.end(); IT++)
  {
      for (auto it = IT.begin(); it != IT.end(); it++){
          cout << *it << " ";
      }
      cout << "\n";
  }

  cout << "x[i][j]:\n" << endl;
  for(size_t i = 0; i < x.size(); i++){
      for(size_t j = 0; j < x[i].size(); j++){
          cout << x[i][j] << " ";
      }
      cout << "\n";
  }

  cout << "const auto&:\n" << endl;
  for (const auto& i : x)
  {
      for (const auto& j : i){
          cout << j << " ";
      }
      cout << "\n";
  }
  cout << "\n";
}

int main ()
{
  // auto
  std::cout << "auto: ";
  for (auto i : {1,2,3,5}) {
    std::cout << i << ", ";
  }
  std::cout << "\n";

  // vector (dynamic arrays)
  // push_back pop_back
  // front back
  // insert(it, value ) insert(it, object.begin, object.end)
  // erase(it) erase(it, it ...)
  // size clear empty
  cout << "<vector>\n";
  vector<int> vt;
  for (int i = 0; i < 6; i++) {
    vt.push_back(i);// push_back
    cout << "vt.front: "<< vt.front() << "   vt.back: "<< vt.back() << " ";// front and back
    cout << "\n";
  }
  vector<int> vt_cp(vt);// copy constructor
  while (!vt_cp.empty()) {
    vt_cp.pop_back();// pop_back
  }
  if (vt_cp.empty()) {// empty
    cout << "vt_cp  is empty\n";
  }
  vector<int> vt_ag = vt;// (re) assign
  vt_ag.clear();// clear
  for (int i = 0; i < 6; i++) {
    vt[i] = 6 - i;// [] index
  }
  auto_show(vt);// pass to function
  cout << "\n";

  // iteration
  cout << "<iteration>\n";
  vector<int>::iterator it = vt.begin();
  it = vt.insert(it, 33);// 33 6 5 4 3 2 1
  vt.insert(it, 2, 66);// 66 66 33 6 5 4 3 2 1
  it = vt.begin();
  vector<int> ele (1, 11);
  // it + 3
  //(0) 66 (1) 66 (2) 33 (3) 6 5 4 3 2 1
  it = vt.insert(it + 3, ele.begin(), ele.end());// (0) 66 66 33 11 6 5 4 3 2 1
  cout << "vt contains:\n";
  for (auto it = vt.begin(); it < vt.end(); it++) {
    cout << ' ' << *it;
  }
  cout << "\n";
  cout << "*it *= 10;\n";
  it = vt.begin();
  *it++ *= 100;
  *it *= 10;
  cout << "vt contains:\n";
  for (auto it = vt.begin(); it < vt.end(); it++) {
    *it *= 10;
    cout << ' ' << *it;
  }
  cout << "\n";
  cout << "if ++ --:\n";
  if (*it > *++it--) {
    int second = *(it + 1);
    cout << *it << " bigger than " << second;
  }
  cout << "\n";
  cout << "if + - < 0:\n";
  it = it + 4;
  if ((*it - *(it - 1)) * (*it - *(it + 1)) < 0) {// 66000 6600 33 6 5 4 3 2 1
    cout << "yes, between";
  }
  cout << "\n";
  cout << "if ++ -- < 0:\n";
  it = vt.begin() + 4;
  if ((*it - *(--it++)) * (*it - *(++it--)) < 0) {// 66000 6600 33 6 5 4 3 2 1
    cout << "yes, between";
  }
  cout << "\n\n";

  // set (binary trees)
  //(most of the people said it si red black tree, a balanced tree)
  // insert(key) insert(it, key)
  // find
  // erase(key) erase(it) erase(it, it + ...)
  // size clear empty
  cout << "<set>\n";
  set<int> st;
  for (int i = 0; i < 6; i++) {
    st.insert(i * 10);// insert: 10 20 30 40 50
  }
  st.insert(30);// no new element inserted
  cout << "st contains:\n";
  for (auto it = st.begin(); it != st.end(); it++) {// cbegin,cend: const_iterator
    cout << ' ' << *it;// the iteration is in ascending order ... 0 10 ... 50
  }
  cout << "\n";
  cout << "find key 30:\n";
  set<int>::iterator it_s;
  if (st.count(30) != 0) {// exsit
    it_s = st.find(30);//
    if (it_s != st.end()) {// Searches the container for an element equivalent to val and returns an iterator to it if found, otherwise it returns an iterator to set::end.
      cout << "key -> " << *it_s;
    }
  }
  cout << "\n\n";

  // multi set
  //Multisets are containers that store elements following a specific order, and where multiple elements can have equivalent values.
  cout << "<multi set>\n";
  multiset<int> stt;
  for (int i = 0; i < 6; i++) {
    stt.insert(i * 10);// insert: 10 20 30 40 50
  }
  stt.insert(30);// dubicate element inserted
  cout << "stt contains:\n";
  for (auto it = stt.begin(); it != stt.end(); it++) {// cbegin,cend: const_iterator
    cout << ' ' << *it;// the iteration is in ascending order ... 0 10 ... 50
  }
  cout << "\n\n";

  // unordered set
  // by hash table
  cout << "<unorder set>\n";
  unordered_set<int> st_un;
  for (int i = 0; i < 6; i++) {
    st_un.insert(i * 10);// insert: 10 20 30 40 50
  }
  st_un.insert(30);// dubicate element inserted
  cout << "st_un contains:\n";
  for (auto it = st_un.begin(); it != st_un.end(); it++) {// cbegin,cend: const_iterator
    cout << ' ' << *it;// the iteration is in ascending order ... 0 10 ... 50
  }
  cout << "\n\n";

  // unordered multi set
  // hash table
  // with duplicate key
  cout << "<unorder multi set>\n";
  unordered_multiset<int> mul_st_un;
  cout << "\n";

  // map
  cout << "<map>\n";
  cout << "mp1:\n";
  map<char, int> mp;
  mp['a'] = 100;
  mp['b'] = 200;
  mp['c'] = 300;
  mp.insert(mp.find('c'), pair<char, int>('d', 500));// insert(it, the thing to insert)
  for (auto it = mp.begin(); it != mp.end(); it++) {
    cout << it->first << " : " << it->second << '\n';
  }
  cout << "mp2:\n";
  map<char, pair<int, int>> mpp;
  mpp['a'] = pair<int, int>(0, 100);// or make_pair(0, 100)
  mpp['b'] = pair<int, int>(0, 200);
  mpp['c'] = pair<int, int>(0, 300);
  mpp.insert(mpp.find('d'), pair<char, pair<int, int>>('d', pair<int, int>(0, 600)));// insert(it...null is okay too, the thing to insert)
  for (auto it = mpp.begin(); it != mpp.end(); it++) {
    cout << it->first << " : " << it->second.second << '\n';
  }
  cout << "\n";
  //
  cout << "<tuple>\n";
  auto t = make_tuple(10, "Test", 3.14, 't', 33);
  std::cout << "The value of t is "  << "("
            << std::get<0>(t) << ", " << std::get<1>(t) << ", "
            << std::get<2>(t) << ", " << std::get<3>(t) << ", "
            << std::get<4>(t) << ")\n";
  cout << "\n\n\n";
  //
  return 0;
}
