
/*
 Demonstrates the use a 2x16 OLED display.
 The LiquidCrystal library works with all LCD displays that are compatible with the Hitachi HD44780 driver.
 
 This sketch prints to the OLED and shows the time since last reset
 
  The circuit:
 * OLED RS pin to digital pin 12
 * OLED Enable pin to digital pin 11
 * OLED D0 pin to digital pin 9
 * OLED D1 pin to digital pin 8
 * OLED D2 pin to digital pin 7
 * OLED D3 pin to digital pin 6
 * OLED D4 pin to digital pin 5
 * OLED D5 pin to digital pin 4
 * OLED D6 pin to digital pin 3
 * OLED D7 pin to digital pin 2
 * OLED R/W pin to ground
 */

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

void SetGpioDB7(uint8 v){
  digitalWrite(2, v?HIGH:LOW); 
}

void SetGpioDB6(uint8 v){
  digitalWrite(3, v?HIGH:LOW); 
}

void SetGpioDB5(uint8 v){
  digitalWrite(4, v?HIGH:LOW); 
}

void SetGpioDB4(uint8 v){
  digitalWrite(5, v?HIGH:LOW); 
}

void SetGpioDB3(uint8 v){
  digitalWrite(6, v?HIGH:LOW); 
}

void SetGpioDB2(uint8 v){
  digitalWrite(7, v?HIGH:LOW); 
}

void SetGpioDB1(uint8 v){
  digitalWrite(8, v?HIGH:LOW); 
}
/*Pin 9*/
void SetGpioDB0(uint8 v){
  digitalWrite(9, v?HIGH:LOW); 
}

void SetData(uint8 v){
#if 0
  char fmt[64]="       ";
  printf("v: 0x%02X\n", v);
  for(int i=0; i<8; i++){
    strcat(fmt, " %d");
  }
  strcat(fmt, "\n");
#endif
  SetGpioDB7(DB7(v));
  SetGpioDB6(DB6(v));
  SetGpioDB5(DB5(v));
  SetGpioDB4(DB4(v));
  SetGpioDB3(DB3(v));
  SetGpioDB2(DB2(v));
  SetGpioDB1(DB1(v));
  SetGpioDB0(DB0(v));
}

/*Pin 12*/
void ResetPinRS(void){
  digitalWrite(12, LOW); 
}
void SetPinRS(void){
  digitalWrite(12, HIGH); 
}

/*Pin 11*/
void ResetPinE(void){
  digitalWrite(11, LOW); 
}
void SetPinE(void){
  digitalWrite(11, HIGH); 
}

void Wcom(uint8_t A){
  SetData(A);
  ResetPinRS();
#if 0
  ResetPinRW();
#endif
  SetPinE();
  delay(50);
  ResetPinE();
}

void Wdata(uint8_t A){
  SetData(A);
  SetPinRS();
#if 0
  ResetPinRW();
#endif
  SetPinE();
  delay(50);
  ResetPinE();
}

void Init(void){
  ResetPinE();
  Wcom(0x38);
  delay(50);
  Wcom(0x38);
  delay(50);
  Wcom(0x38);
  delay(50);
  Wcom(0x08);
  Wcom(0x38);
  Wcom(0x10);
  Wcom(0x0c);
  Wcom(0x06);
  Wcom(0x01);
#if 0
  char line1[16]="   Welcome      "; 
  char line2[16]="   Advantech    "; 
#else
  char const line1[] = {"Newhaven Display"};
  char const line2[] = {"Character LCD   "};
#endif

  for(int i=0; i<16; i++){
    Wdata(line1[i]);
  }
  Wcom(0xc0);
  for(int i=0; i<16; i++){
    Wdata(line2[i]);
  }
  /*
  Wdata('A');
  Wdata('d');  
  Wdata('v');  
  Wdata('a');  
  Wdata('n');  
  */
}

void setup() {
  Serial.begin(9600);      // open the serial port at 9600 bps
  pinMode(12, OUTPUT);     // sets the digital pin 12 as output
  pinMode(11, OUTPUT);     // sets the digital pin 11 as output
  pinMode(9, OUTPUT);      // sets the digital pin 9 as output
  pinMode(8, OUTPUT);      // sets the digital pin 8 as output
  pinMode(7, OUTPUT);      // sets the digital pin 7 as output
  pinMode(6, OUTPUT);      // sets the digital pin 6 as output
  pinMode(5, OUTPUT);      // sets the digital pin 5 as output
  pinMode(4, OUTPUT);      // sets the digital pin 4 as output
  pinMode(3, OUTPUT);      // sets the digital pin 3 as output
  pinMode(2, OUTPUT);      // sets the digital pin 2 as output
  Init();
}

void loop() { 
  // put your main code here, to run repeatedly:
  Serial.print("loop...");
  Serial.println();
  Wcom(0x08);
  delay(1000);
  Wcom(0x0C);
  delay(1000);
}
