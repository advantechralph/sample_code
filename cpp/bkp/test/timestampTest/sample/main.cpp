#include <iostream>
#include "main.h"
using namespace std;
int main(int argc, char *argv[]){
  cout << __FILE__ << ", " ; 
  cout << __FUNCTION__ << ", ";
  cout << __LINE__ << ": ";
  cout << endl; 
  Timestamp t; 
  cout << "Now: " << t.Now() << endl;
  cout << "Now: " << t.NowStr() << endl;
  cout << "Now: " << t.NowStr(1) << endl;
  t.Dump();
  t.Dump(0);
  t.Dump(1);
  t.Begin();
  sleep(1);
  t.End();
  //cout << "Diff: " << t.getDiff() << "(micoseconds)" << endl; 
  t.DumpDiff();
  return 0; 
}

