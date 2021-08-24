#include <string.h>
#include <avr/pgmspace.h>

#define Row1 4
#define Row2 5
#define Row3 6
#define Row4 7
#define Row5 8
#define Row6 9
#define Row7 10
#define Row8 11

#define Col1 2
#define Col2 3
#define Col3 19
#define Col4 18
#define Col5 17
#define Col6 16
#define Col7 15
#define Col8 14

byte rowLEDs[] = {Row1, Row2, Row3, Row4, Row5, Row6, Row7, Row8};
byte colLEDs[] = {Col1, Col2, Col3, Col4, Col5, Col6, Col7, Col8};

const PROGMEM char A[7][6] = {"01110", "10001", "10001", "11111", "10001", "10001", "10001"};
const PROGMEM char B[7][6] = {"11110", "10001", "10001", "11110", "10001", "10001", "11110"};
const PROGMEM char C[7][6] = {"01110", "10001", "10000", "10000", "10000", "10001", "01110"};
const PROGMEM char D[7][6] = {"11110", "10001", "10001", "10001", "10001", "10001", "11110"};
const PROGMEM char E[7][6] = {"11111", "10000", "10000", "11110", "10000", "10000", "11111"};
const PROGMEM char F[7][6] = {"11111", "10000", "10000", "11110", "10000", "10000", "10000"};
const PROGMEM char G[7][6] = {"01110", "10001", "10000", "10000", "10111", "10001", "01111"};
const PROGMEM char H[7][6] = {"10001", "10001", "10001", "11111", "10001", "10001", "10001"};
const PROGMEM char I[7][6] = {"01110", "00100", "00100", "00100", "00100", "00100", "01110"};
const PROGMEM char J[7][6] = {"00001", "00001", "00001", "00001", "00001", "10001", "01110"};
const PROGMEM char K[7][6] = {"10001", "10010", "10100", "11000", "10100", "10010", "10001"};
const PROGMEM char L[7][6] = {"10000", "10000", "10000", "10000", "10000", "10000", "11111"};
const PROGMEM char M[7][6] = {"10001", "11011", "10101", "10101", "10001", "10001", "10001"};
const PROGMEM char N[7][6] = {"10001", "10001", "11001", "10101", "10011", "10001", "10001"};
const PROGMEM char O[7][6] = {"01110", "10001", "10001", "10001", "10001", "10001", "01110"};
const PROGMEM char P[7][6] = {"11110", "10001", "10001", "10001", "11110", "10000", "10000"};
const PROGMEM char Q[7][6] = {"01110", "10001", "10001", "10001", "10101", "10010", "01101"};
const PROGMEM char R[7][6] = {"11110", "10001", "10001", "11110", "10100", "10010", "10001"};
const PROGMEM char S[7][6] = {"01110", "10001", "10000", "01110", "00001", "10001", "01110"};
const PROGMEM char T[7][6] = {"11111", "00100", "00100", "00100", "00100", "00100", "00100"};
const PROGMEM char U[7][6] = {"10001", "10001", "10001", "10001", "10001", "10001", "01110"};
const PROGMEM char V[7][6] = {"10001", "10001", "10001", "10001", "10001", "01010", "00100"};
const PROGMEM char W[7][6] = {"10001", "10001", "10001", "10101", "10101", "11011", "10001"};
const PROGMEM char X[7][6] = {"10001", "10001", "01010", "00100", "01010", "10001", "10001"};
const PROGMEM char Y[7][6] = {"10001", "10001", "01010", "00100", "00100", "00100", "00100"};
const PROGMEM char Z[7][6] = {"11111", "00001", "00010", "00100", "01000", "10000", "11111"};
const PROGMEM char zero[7][6] =  {"01110", "10001", "10011", "10101", "11001", "10001", "01110"};
const PROGMEM char one[7][6] =   {"00100", "01100", "00100", "00100", "00100", "00100", "01110"};
const PROGMEM char two[7][6] =   {"01110", "10001", "00001", "00110", "01000", "10000", "11111"};
const PROGMEM char three[7][6] = {"01110", "10001", "00001", "00110", "00001", "10001", "01110"};
const PROGMEM char four[7][6] =  {"00010", "00110", "01010", "10010", "11111", "00010", "00010"};
const PROGMEM char five[7][6] =  {"11111", "10000", "11110", "00001", "00001", "10001", "01110"};
const PROGMEM char six[7][6] =   {"00111", "01000", "10000", "11110", "10001", "10001", "01110"};
const PROGMEM char seven[7][6] = {"11111", "00001", "00010", "00100", "01000", "01000", "01000"};
const PROGMEM char eight[7][6] = {"01110", "10001", "10001", "01110", "10001", "10001", "01110"};
const PROGMEM char nine[7][6] =  {"01110", "10001", "10001", "01111", "00001", "10001", "01110"};
const PROGMEM char dash[7][6] =  {"00000", "00000", "00000", "11111", "00000", "00000", "00000"};
const PROGMEM char err[7][6] =   {"11111", "00000", "00000", "11111", "00000", "00000", "11111"};
const PROGMEM char space[7][6] = {"00000", "00000", "00000", "00000", "00000", "00000", "00000"};

int windowTimer = 0;
int upperBound = 8;
int lowerBound = 0;
String stringWrite = "BME-393 DIGITAL CIRCUITS LAB"; 
char arrayWrite [7][200];

void setup() {
  
  for(int i = 2; i < 11; i++){
    pinMode(i, OUTPUT);
  }
  for(int i = 14; i < 20; i++){
    pinMode(i, OUTPUT);
  }
  Serial.begin(9600);

  for(int i = 0; i < 8; i++){
    for(int j = 0; j < 7; j++){
      append(arrayWrite[j], '0'); 
    }
  }
  
  for(int i = 0; i < stringWrite.length(); i++)
  {
    for(int k = 0; k < 6; k++)
    {
      if (stringWrite.charAt(i) == 'A' || stringWrite.charAt(i) == 'a')
      {
        for (int j = 0; j < 7; j++)
        {
          String tempString = String(A[j]);
          append(arrayWrite[j], pgm_read_byte(&A[j][k]));
        }
      }
      else if (stringWrite.charAt(i) == 'B' || stringWrite.charAt(i) == 'b')
      {
        for (int j = 0; j < 7; j++)
        {
          String tempString = String(B[j]);
          append(arrayWrite[j],  pgm_read_byte(&B[j][k]));
        }
      }
      else if (stringWrite.charAt(i) == 'C' || stringWrite.charAt(i) == 'c')
      {
        for (int j = 0; j < 7; j++)
        {
          String tempString = String(C[j]);
          append(arrayWrite[j],  pgm_read_byte(&C[j][k]));
        }
      }
      else if (stringWrite.charAt(i) == 'D' || stringWrite.charAt(i) == 'd')
      {
        for (int j = 0; j < 7; j++)
        {
          String tempString = String(D[j]);
          append(arrayWrite[j],  pgm_read_byte(&D[j][k]));
        }
      }
      else if (stringWrite.charAt(i) == 'E' || stringWrite.charAt(i) == 'e')
      {
        for (int j = 0; j < 7; j++)
        {
          String tempString = String(E[j]);
          append(arrayWrite[j],  pgm_read_byte(&E[j][k]));
        }
      }
      else if (stringWrite.charAt(i) == 'F' || stringWrite.charAt(i) == 'f')
      {
        for (int j = 0; j < 7; j++)
        {
          String tempString = String(F[j]);
          append(arrayWrite[j],  pgm_read_byte(&F[j][k]));
        }
      }
      else if (stringWrite.charAt(i) == 'G' || stringWrite.charAt(i) == 'g')
      {
        for (int j = 0; j < 7; j++)
        {
          String tempString = String(G[j]);
          append(arrayWrite[j],  pgm_read_byte(&G[j][k]));
        }
      }
      else if (stringWrite.charAt(i) == 'H' || stringWrite.charAt(i) == 'h')
      {
        for (int j = 0; j < 7; j++)
        {
          String tempString = String(H[j]);
          append(arrayWrite[j],  pgm_read_byte(&H[j][k]));
        }
      }
      else if (stringWrite.charAt(i) == 'I' || stringWrite.charAt(i) == 'i')
      {
        for (int j = 0; j < 7; j++)
        {
          String tempString = String(I[j]);
          append(arrayWrite[j],  pgm_read_byte(&I[j][k]));
        }
      }
      else if (stringWrite.charAt(i) == 'J' || stringWrite.charAt(i) == 'j')
      {
        for (int j = 0; j < 7; j++)
        {
          String tempString = String(J[j]);
          append(arrayWrite[j],  pgm_read_byte(&J[j][k]));
        }
      }
      else if (stringWrite.charAt(i) == 'K' || stringWrite.charAt(i) == 'k')
      {
        for (int j = 0; j < 7; j++)
        {
          String tempString = String(K[j]);
          append(arrayWrite[j], pgm_read_byte(&K[j][k]));
        }
      }
      else if (stringWrite.charAt(i) == 'L' || stringWrite.charAt(i) == 'l')
      {
        for (int j = 0; j < 7; j++)
        {
          String tempString = String(L[j]);
          append(arrayWrite[j], pgm_read_byte(&L[j][k]));
        }
      }
      else if (stringWrite.charAt(i) == 'M' || stringWrite.charAt(i) == 'm')
      {
        for (int j = 0; j < 7; j++)
        {
          String tempString = String(M[j]);
          append(arrayWrite[j], pgm_read_byte(&M[j][k]));
        }
      }
      else if (stringWrite.charAt(i) == 'N' || stringWrite.charAt(i) == 'n')
      {
        for (int j = 0; j < 7; j++)
        {
          String tempString = String(N[j]);
          append(arrayWrite[j], pgm_read_byte(&N[j][k]));
        }
      }
      else if (stringWrite.charAt(i) == 'O' || stringWrite.charAt(i) == 'o')
      {
        for (int j = 0; j < 7; j++)
        {
          String tempString = String(O[j]);
          append(arrayWrite[j], pgm_read_byte(&O[j][k]));
        }
      }
      else if (stringWrite.charAt(i) == 'P' || stringWrite.charAt(i) == 'p')
      {
        for (int j = 0; j < 7; j++)
        {
          String tempString = String(P[j]);
          append(arrayWrite[j], pgm_read_byte(&P[j][k]));
        }
      }
      else if (stringWrite.charAt(i) == 'Q' || stringWrite.charAt(i) == 'q')
      {
        for (int j = 0; j < 7; j++)
        {
          String tempString = String(Q[j]);
          append(arrayWrite[j], pgm_read_byte(&Q[j][k]));
        }
      }
      else if (stringWrite.charAt(i) == 'R' || stringWrite.charAt(i) == 'r')
      {
        for (int j = 0; j < 7; j++)
        {
          String tempString = String(R[j]);
          append(arrayWrite[j], pgm_read_byte(&R[j][k]));
        }
      }
      else if (stringWrite.charAt(i) == 'S' || stringWrite.charAt(i) == 's')
      {
        for (int j = 0; j < 7; j++)
        {
          String tempString = String(S[j]);
          append(arrayWrite[j], pgm_read_byte(&S[j][k]));
        }
      }
      else if (stringWrite.charAt(i) == 'T' || stringWrite.charAt(i) == 't')
      {
        for (int j = 0; j < 7; j++)
        {
          String tempString = String(T[j]);
          append(arrayWrite[j], pgm_read_byte(&T[j][k]));
        }
      }
      else if (stringWrite.charAt(i) == 'U' || stringWrite.charAt(i) == 'u')
      {
        for (int j = 0; j < 7; j++)
        {
          String tempString = String(U[j]);
          append(arrayWrite[j], pgm_read_byte(&U[j][k]));
        }
      }
      else if (stringWrite.charAt(i) == 'V' || stringWrite.charAt(i) == 'v')
      {
        for (int j = 0; j < 7; j++)
        {
          String tempString = String(V[j]);
          append(arrayWrite[j], pgm_read_byte(&V[j][k]));
        }
      }
      else if (stringWrite.charAt(i) == 'W' || stringWrite.charAt(i) == 'w')
      {
        for (int j = 0; j < 7; j++)
        {
          String tempString = String(W[j]);
          append(arrayWrite[j], pgm_read_byte(&W[j][k]));
        }
      }
      else if (stringWrite.charAt(i) == 'X' || stringWrite.charAt(i) == 'x')
      {
        for (int j = 0; j < 7; j++)
        {
          String tempString = String(X[j]);
          append(arrayWrite[j], pgm_read_byte(&X[j][k]));
        }
      }
      else if (stringWrite.charAt(i) == 'Y' || stringWrite.charAt(i) == 'y')
      {
        for (int j = 0; j < 7; j++)
        {
          String tempString = String(Y[j]);
          append(arrayWrite[j], pgm_read_byte(&Y[j][k]));
        }
      }
      else if (stringWrite.charAt(i) == 'Z' || stringWrite.charAt(i) == 'z')
      {
        for (int j = 0; j < 7; j++)
        {
          String tempString = String(Z[j]);
          append(arrayWrite[j], pgm_read_byte(&Z[j][k]));
        }
      }
      else if (stringWrite.charAt(i) == ' ')
      {
        for (int j = 0; j < 7; j++)
        {
          String tempString = String(space[j]);
          append(arrayWrite[j], pgm_read_byte(&space[j][k]));
        }
      }
      else if (stringWrite.charAt(i) == '1')
      {
        for (int j = 0; j < 7; j++)
        {
          String tempString = String(one[j]);
          append(arrayWrite[j], pgm_read_byte(&one[j][k]));
        }
      }
      else if (stringWrite.charAt(i) == '2')
      {
        for (int j = 0; j < 7; j++)
        {
          String tempString = String(two[j]);
          append(arrayWrite[j], pgm_read_byte(&two[j][k]));
        }
      }
      else if (stringWrite.charAt(i) == '3')
      {
        for (int j = 0; j < 7; j++)
        {
          String tempString = String(three[j]);
          append(arrayWrite[j], pgm_read_byte(&three[j][k]));
        }
      }
      else if (stringWrite.charAt(i) == '4')
      {
        for (int j = 0; j < 7; j++)
        {
          String tempString = String(four[j]);
          append(arrayWrite[j], pgm_read_byte(&four[j][k]));
        }
      }
      else if (stringWrite.charAt(i) == '5')
      {
        for (int j = 0; j < 7; j++)
        {
          String tempString = String(five[j]);
          append(arrayWrite[j], pgm_read_byte(&five[j][k]));
        }
      }
      else if (stringWrite.charAt(i) == '6')
      {
        for (int j = 0; j < 7; j++)
        {
          String tempString = String(six[j]);
          append(arrayWrite[j], pgm_read_byte(&six[j][k]));
        }
      }
      else if (stringWrite.charAt(i) == '7')
      {
        for (int j = 0; j < 7; j++)
        {
          String tempString = String(seven[j]);
          append(arrayWrite[j], pgm_read_byte(&seven[j][k]));
        }
      }
      else if (stringWrite.charAt(i) == '8')
      {
        for (int j = 0; j < 7; j++)
        {
          String tempString = String(eight[j]);
          append(arrayWrite[j], pgm_read_byte(&eight[j][k]));
        }
      }
      else if (stringWrite.charAt(i) == '9')
      {
        for (int j = 0; j < 7; j++)
        {
          String tempString = String(nine[j]);
          append(arrayWrite[j], pgm_read_byte(&nine[j][k]));
        }
      }
      else if (stringWrite.charAt(i) == '0')
      {
        for (int j = 0; j < 7; j++)
        {
          append(arrayWrite[j],  pgm_read_byte(&zero[j][k]));
        }
      }
      else if (stringWrite.charAt(i) == '-')
      {
        for (int j = 0; j < 7; j++)
        {
          String tempString = String(dash[j]);
          append(arrayWrite[j], pgm_read_byte(&dash[j][k]));
        }
      }
      else
      {
        for (int j = 0; j < 7; j++)
        {
          String tempString = String(err[j]);
          append(arrayWrite[j], pgm_read_byte(&err[j][k]));
        }
      }
      delayMicroseconds(1);
    }
    for (int j = 0; j < 7; j++)
    {
      append(arrayWrite[j], '0');
    }
  }
}

void loop() {
  if(windowTimer % 500 == 0 && windowTimer != 0){
     lowerBound++;
     upperBound++;
  }
  if(lowerBound == stringWrite.length()*6 + 8){
    lowerBound = 0;
    upperBound = 8;
  }
  scrollWindow(lowerBound, upperBound);
  windowTimer++;
}

void scrollWindow(int lower, int upper){
  int colCounter;
  
  for(int i = 0; i < 7; i++){
    digitalWrite(rowLEDs[i], HIGH);
    colCounter = 0;    
    for(int j = lower; j < upper; j++){
      char ledVal = arrayWrite[i][j];
      if(ledVal == '1'){
        digitalWrite(colLEDs[colCounter], LOW);      
      }
      colCounter++;
    }
    delayMicroseconds(1);
    
    digitalWrite(rowLEDs[i], LOW);
    
    for(int i = 0; i < 8; i++){
      digitalWrite(colLEDs[i], HIGH);
    } 
    delayMicroseconds(1);
  }
}

void append(char* letter, char character) {
  int length = strlen(letter);
  letter[length] = character;
}
