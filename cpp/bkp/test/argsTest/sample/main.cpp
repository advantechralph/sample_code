#include <iostream>
#include "main.h"
using namespace std;
int main(int argc, char *argv[]){
  char buf[]="xxx ooo \t fskmfkm"; 
  Args a(buf, "\t ");
  a.Info();
  if(argc>2){
    a=Args(argv[1], argv[2]);
    a.Info();
  }
  return 0; 
}

