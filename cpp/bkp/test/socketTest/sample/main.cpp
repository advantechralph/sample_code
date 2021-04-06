#include <iostream>
#include "main.h"
using namespace std;
void EF(Sockets *pS){
  cout << "EF(): " << endl;
  pS->Expire(5,5);
}
int main(int argc, char *argv[]){
  Sockets s;
  s.AddUDP(5555);
  s.AddTCP(6666);
  s.Run();
  return 0; 
}
