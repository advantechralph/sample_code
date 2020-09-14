#include <stdio.h>
#include <string.h>
#define DB(x,i) ((x>>i)&1)
#define DB0(x)  DB(x,0)
#define DB1(x)  DB(x,1)
#define DB2(x)  DB(x,2)
#define DB3(x)  DB(x,3)
#define DB4(x)  DB(x,4)
#define DB5(x)  DB(x,5)
#define DB6(x)  DB(x,6)
#define DB7(x)  DB(x,7)

typedef unsigned char uint8; 

void dump(uint8 v){
  char fmt[64]="       "; 
  printf("v: 0x%02X\n", v);
  for(int i=0; i<8; i++){
    strcat(fmt, " %d");
  }
  strcat(fmt, "\n");
  printf("  bits: 7 6 5 4 3 2 1 0\n");
  printf(fmt, 
	  DB7(v), 
	  DB6(v), 
	  DB5(v), 
	  DB4(v), 
	  DB3(v), 
	  DB2(v), 
	  DB1(v), 
	  DB0(v) 
	  );
}


void SetGpioDB7(uint8 v){
  //NXP set GPIO DB7 pin
  if(v){
    printf("%s: set DB7 high\n", __FUNCTION__);
  }else{
    printf("%s: set DB7 low\n", __FUNCTION__);
  }
}

void SetGpioDB6(uint8 v){
  //NXP set GPIO DB6 pin
  if(v){
    printf("%s: set DB7 high\n", __FUNCTION__);
  }else{
    printf("%s: set DB7 low\n", __FUNCTION__);
  }
}

void SetGpioDB5(uint8 v){
  //NXP set GPIO DB5 pin
  if(v){
    printf("%s: set DB5 high\n", __FUNCTION__);
  }else{
    printf("%s: set DB5 low\n", __FUNCTION__);
  }
}

void SetGpioDB4(uint8 v){
  //NXP set GPIO DB4 pin
  if(v){
    printf("%s: set DB4 high\n", __FUNCTION__);
  }else{
    printf("%s: set DB4 low\n", __FUNCTION__);
  }
}

void SetGpioDB3(uint8 v){
  //NXP set GPIO DB3 pin
  if(v){
    printf("%s: set DB3 high\n", __FUNCTION__);
  }else{
    printf("%s: set DB3 low\n", __FUNCTION__);
  }
}

void SetGpioDB2(uint8 v){
  //NXP set GPIO DB2 pin
  if(v){
    printf("%s: set DB2 high\n", __FUNCTION__);
  }else{
    printf("%s: set DB2 low\n", __FUNCTION__);
  }
}

void SetGpioDB1(uint8 v){
  //NXP set GPIO DB1 pin
  if(v){
    printf("%s: set DB1 high\n", __FUNCTION__);
  }else{
    printf("%s: set DB1 low\n", __FUNCTION__);
  }
}

void SetGpioDB0(uint8 v){
  //NXP set GPIO DB0 pin
  if(v){
    printf("%s: set DB0 high\n", __FUNCTION__);
  }else{
    printf("%s: set DB0 low\n", __FUNCTION__);
  }
}

void SetData(uint8 v){
  char fmt[64]="       "; 
  printf("v: 0x%02X\n", v);
  for(int i=0; i<8; i++){
    strcat(fmt, " %d");
  }
  strcat(fmt, "\n");
  printf("  bits: 7 6 5 4 3 2 1 0\n");
  printf(fmt, 
	  DB7(v), 
	  DB6(v), 
	  DB5(v), 
	  DB4(v), 
	  DB3(v), 
	  DB2(v), 
	  DB1(v), 
	  DB0(v) 
	  );
  SetGpioDB7(DB7(v));
  SetGpioDB6(DB6(v));
  SetGpioDB5(DB5(v));
  SetGpioDB4(DB4(v));
  SetGpioDB3(DB3(v));
  SetGpioDB2(DB2(v));
  SetGpioDB1(DB1(v));
  SetGpioDB0(DB0(v));
}

int main(void){
#if 0
  printf("%d\n", DB(0x3, 0));
  printf("%d\n", DB(0x3, 1));
  printf("%d\n", DB(0x3, 2));
  printf("%d\n", DB0(0xC3));
  printf("%d\n", DB1(0xC3));
  printf("%d\n", DB2(0xC3));
  printf("%d\n", DB3(0xC3));
  printf("%d\n", DB4(0xC3));
  dump((uint8)0x3D);
  dump((uint8)0x79);
  dump((uint8)0x6A);
  dump((uint8)0x58);
#else
  SetData((uint8)0x3D);
  SetData((uint8)0x79);
  SetData((uint8)0x6A);
  SetData((uint8)0xD8);
#endif
  return 0; 
}
