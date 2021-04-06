#include <iostream>
#include "main.h"
using namespace std;
int main(int argc, char *argv[]){
  Opts o((const char *)(argv[1]?argv[1]:""));
  o.Dump();
  o.Parse();
  return 0; 
}
