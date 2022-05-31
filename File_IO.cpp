/*
Auther: John Blue
Time: 2022/6
Platform: atom
Object: to use fstream
*/

#include <iostream>
#include <fstream>// ifstream, ofstream
using namespace std;

int main ()
{
  ////// interaction
  //char name[50];
  //cout << "Please enter file name: ";
  //cin >> name;
  //cout << "Confirm name is: " << name << endl;

  ////// file

  // write
  fstream in;
  in.open("file.csv", fstream::in | fstream::out | fstream::app);
  if(in.is_open()) {
    in << " ,a,b,c\n";
    in << "0,d,d,d\n";
    // return to first line
    in.clear();
    //in.seek(0);
    // close
    in.close();
    cout << "Success to write .csv\n";
  }
  else {
    cout << "Fail to write .csv\n";
  }

  // read
  fstream out;
  out.open("file.csv");
  string line;
  if(out.is_open())
  {
    while(getline(out, line, '\n')){
      cout << line << '\n';
    }
    out.close();
  }
}
