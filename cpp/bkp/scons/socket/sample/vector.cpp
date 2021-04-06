#include "main.h"
using namespace std;
void vectorTest(void){
  int iArray[]={0,1,2,3,4};
  vector <int> i(iArray, iArray+sizeof(i)); 
  printf("i(%p)\n", &i);
  printf("iArray(%p)\n", &iArray);
  printf("i[0](%p): %d\n", &i[0], i[0]);
}
