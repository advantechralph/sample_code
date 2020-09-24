#ifndef __test_bits_h__
#define __test_bits_h__

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

#define SET(reg,b) reg |= (b)
#define CLR(reg,b) reg &=~(b)

#define BIT0 (1<<0)
#define BIT1 (1<<1)
#define BIT2 (1<<2)
#define BIT3 (1<<3)
#define BIT4 (1<<4)
#define BIT5 (1<<5)
#define BIT6 (1<<6)
#define BIT7 (1<<7)

#define printbits(x) {for(int _i=7; _i>-1; _i--) printf("%d", DB(x, _i));}

#endif /* __test_bits_h__ */
