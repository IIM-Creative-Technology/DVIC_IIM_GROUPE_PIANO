#include <LedControl.h>

#define DO_1 65
#define RE_1 73
#define MI_1 82
#define FA_1 88
#define SOL_1 97
#define LA_1 110
#define DO_3 260
#define RE_3 293
#define MI_3 329
#define FA_3 350
#define SOL_3 391
#define LA_3 440
#define SI_3 493
#define DO_4 523
#define RE_4 587
#define MI_4 659
#define FA_4 698
#define SOL_4 783
#define LA_4 880
#define SI_4 987
#define DO_5 1046
#define RE_5 1174
#define MI_5 1318
#define FA_5 1396
#define SOL_5 1567
#define LA_5 1760
#define SI_5 1975
 

const int D = 9;
const int R = 8;
const int M = 7;
const int F = 6;
const int SO = 5;
const int L = 4;
const int SI = 11;
const int DIN = 10;
const int CS = 3;
const int CLK = 2;

int DO_N;
int RE_N;
int MI_N;
int FA_N;
int SOL_N;
int LA_N;
int SI_N;

const int Buzz = 12;
const int LED = 13;

byte d[8] = {0xff,0xc2,0x3c,0x0,0x7e,0x81,0x81,0x7e};
byte r[8] = {0xff,0x19,0x29,0x46,0x80,0xff,0x89,0x89};
byte m[8] = {0xff,0x2,0x4,0x2,0xff,0x0,0xfd,0x0};
byte f[8] = {0xff,0x9,0x9,0x1,0xfc,0xa,0xa,0xfc};
byte so[8] = {0x86,0x89,0x89,0x70,0x0,0x7e,0x81,0x7e};
byte l[8] = {0xff,0x80,0x80,0x0,0xf8,0x14,0x14,0xf8};
byte si[8] = {0x86,0x89,0x89,0x71,0x0,0x0,0xfd,0x0};
byte no[8] = {0x0,0x0,0x0,0x42,0xe1,0xff,0x0,0x0};




LedControl lc=LedControl(DIN,CLK,CS,0);

void setup()
{
  Serial.begin(9600);
  pinMode(A1, INPUT);
 
  pinMode(LED, OUTPUT);
  
  pinMode(D, INPUT);
  digitalWrite(D,HIGH);
  
  pinMode(R, INPUT);
  digitalWrite(R,HIGH);
  
  pinMode(M, INPUT);
  digitalWrite(M,HIGH);
  
  pinMode(F, INPUT);
  digitalWrite(F,HIGH);
  
  pinMode(SO, INPUT);
  digitalWrite(SO,HIGH);
  
  pinMode(L, INPUT);
  digitalWrite(L,HIGH);

  pinMode(SI, INPUT);
  digitalWrite(SI,HIGH);

  digitalWrite(LED,LOW);
  

  lc.shutdown(0,false);       
  lc.setIntensity(0,1);     
  lc.clearDisplay(0); 
}

void loop()
{
  int val = analogRead(A1);

  val = val / 4;

  if (val < 85) {
    DO_N = DO_3;
    RE_N = RE_3;
    MI_N = MI_3;
    FA_N = FA_3;
    SOL_N = SOL_3;
    LA_N = LA_3;
    SI_N = SI_3;
  } else if (val >= 85 && val < 160) {
    DO_N = DO_4;
    RE_N = RE_4;
    MI_N = MI_4;
    FA_N = FA_4;
    SOL_N = SOL_4;
    LA_N = LA_4;
    SI_N = SI_4;
  } else {
    DO_N = DO_5;
    RE_N = RE_5;
    MI_N = MI_5;
    FA_N = FA_5;
    SOL_N = SOL_5;
    LA_N = LA_5;
    SI_N = SI_5;
  }
  
  while(digitalRead(D) == LOW)
  {
    tone(Buzz,DO_N);
    digitalWrite(LED,HIGH);
    printByte(d);   

  }

  while(digitalRead(R) == LOW)
  {
    tone(Buzz,RE_N);
    digitalWrite(LED,HIGH);
    printByte(r);
  }

  while(digitalRead(M) == LOW)
  {
    tone(Buzz,MI_N);
    digitalWrite(LED,HIGH);
    printByte(m);
  }

  while(digitalRead(F) == LOW)
  {
    tone(Buzz,FA_N);
    digitalWrite(LED,HIGH);
    printByte(f);
  }

  while(digitalRead(SO) == LOW)
  {
    tone(Buzz,SOL_N);
    digitalWrite(LED,HIGH);
    printByte(so);
  }

  while(digitalRead(L) == LOW)
  {
    tone(Buzz,LA_N);
    digitalWrite(LED,HIGH);
    printByte(l);
  }
  while(digitalRead(SI) == LOW)
  {
    tone(Buzz,SI_N);
    digitalWrite(LED,HIGH);
    printByte(si);
    
  }

  noTone(Buzz);
  digitalWrite(LED,LOW);

}

void printByte(byte character [])
{
  int i = 0;
  for(i=0;i<8;i++)
  {
    lc.setRow(0,i,character[i]);
  }
}
