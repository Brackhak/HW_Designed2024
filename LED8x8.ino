#include "LedControl.h"

/*
 Now we need a LedControl to work with.
 ***** These pin numbers will probably not work with your hardware *****
 pin 12 is connected to the DataIn 
 pin 11 is connected to LOAD(CS)
 pin 10 is connected to the CLK 
 We have only a single MAX72XX.
 */ 
LedControl lc=LedControl(12,10,11,1);

/* image switching time */
unsigned long delaytime1=100;
unsigned long delaytime2=200;
void setup() {
  /*
   The MAX72XX is in power-saving mode on startup,
   we have to do a wakeup call
   */
  lc.shutdown(0,false);
  /* Set the brightness to a medium values */
  lc.setIntensity(0,8);
  /* and clear the display */
  lc.clearDisplay(0);
}

/*
 This method will display the characters for the
 word "Arduino" one after the other on the matrix. 
 (you need at least 5x7 leds to see the whole chars)
 */
void writeArduinoOnMatrix() {
  /* here is the data for the characters */
byte ALL[] = {B11111111,B11111111,B11111111,B11111111,B11111111,B11111111,B11111111,B11111111};
byte EX[] = {B00000000,B00010000,B00010000,B00010000,B00010000,B00000000,B00010000,B00000000};

byte one[] = {B00000000,B00001000,B00011000,B00001000,B00001000,B00001000,B00111100,B00000000};
byte two[] = {B00000000,B00011000,B00100100,B00000100,B00001000,B00010000,B00111100,B00000000};
byte three[] = {B000000,B00000000,B00011100,B00000100,B00001000,B00000100,B00011100,B00000000};
byte heartsmile[] = {B00110110,B01001001,B01000001,B01000001,B01000001,B00100010,B00010100,B00001000};
byte pluem0[] = {B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000};
byte pluem1[] = {B00000000,B00000000,B00000001,B00000001,B00000001,B00000001,B00000001,B00000001};
byte pluem2[] = {B00000000,B00000000,B00000011,B00000010,B00000010,B00000011,B00000010,B00000010};
byte pluem3[] = {B00000000,B00000000,B00000110,B00000101,B00000101,B00000110,B00000100,B00000100};
byte pluem4[] = {B00000000,B00000000,B00001100,B00001010,B00001010,B00001100,B00001000,B00001000};
byte pluem5[] = {B00000000,B00000000,B00011001,B00010101,B00010101,B00011001,B00010001,B00010001};
byte pluem6[] = {B00000000,B00000000,B00110010,B00101010,B00101010,B00110010,B00100010,B00100010};
byte pluem7[] = {B00000000,B00000000,B01100100,B01010100,B01010101,B01100101,B01000101,B01000100};
byte pluem8[] = {B00000000,B00000000,B01100100,B01010100,B01010101,B01100101,B01000101,B01000100};
byte pluem9[] = {B00000000,B00000000,B11001000,B10101000,B10101010,B11001010,B10001010,B10001001};
byte pluem10[] = {B00000000,B00000000,B10010000,B01010000,B01010100,B10010100,B00010100,B00010011};
byte pluem11[] = {B00000000,B00000000,B00100000,B10100000,B10101001,B00101001,B00101001,B00100110};
byte pluem12[] = {B00000000,B00000000,B01000000,B01000000,B01010010,B01010010,B01010010,B01001100};
byte pluem13[] = {B00000000,B00000000,B10000000,B10000000,B10100101,B10100101,B10100101,B10011000};
byte pluem14[] = {B00000000,B00000000,B00000000,B00000001,B01001010,B01001011,B01001010,B00110001};
byte pluem15[] = {B00000000,B00000000,B00000000,B00000011,B10010100,B10010111,B10010100,B01100011};
byte pluem16[] = {B00000000,B00000000,B00000000,B00000110,B00101001,B00101110,B00101000,B11000111};
byte pluem17[] = {B00000000,B00000000,B00000000,B00001100,B01010010,B01011100,B01010000,B10001110};
byte pluem18[] = {B00000000,B00000000,B00000000,B00011000,B10100100,B10111001,B10100001,B00011101};
byte pluem19[] = {B00000000,B00000000,B00000000,B00110000,B01001001,B01110010,B01000010,B00111010};
byte pluem20[] = {B00000000,B00000000,B00000000,B01100000,B10010010,B11100101,B10000101,B01110100};
byte pluem21[] = {B00000000,B00000000,B00000000,B11000000,B00100101,B11001010,B00001010,B11101000};
byte pluem22[] = {B00000000,B00000000,B00000000,B10000000,B01001010,B10010101,B00010101,B11010001};
byte pluem23[] = {B00000000,B00000000,B00000000,B00000000,B10010100,B00101010,B00101010,B10100010};
byte pluem24[] = {B00000000,B00000000,B00000000,B00000000,B00101000,B01010100,B01010100,B01000100};
byte pluem25[] = {B00000000,B00000000,B00000000,B00000000,B01010000,B10101000,B10101000,B10001000};
byte pluem26[] = {B00000000,B00000000,B00000000,B00000000,B10100000,B01010000,B01010000,B00010000};
byte pluem27[] = {B00000000,B00000000,B00000000,B00000000,B01000000,B10100000,B10100000,B00100000};
byte pluem28[] = {B00000000,B00000000,B00000000,B00000000,B10000000,B01000000,B01000000,B01000000};
byte pluem29[] = {B00000000,B00000000,B00000000,B00000000,B00000000,B10000000,B10000000,B10000000};
byte pluem30[] = {B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000};

byte HWD0[] = {B00000000,B00000001,B00000001,B00000001,B00000001,B00000001,B00000001,B00000000};
byte HWD1[] = {B00000000,B00000010,B00000010,B00000010,B00000011,B00000010,B00000010,B00000000};
byte HWD2[] = {B00000000,B00000100,B00000100,B00000100,B00000111,B00000100,B00000100,B00000000};
byte HWD3[] = {B00000000,B00001001,B00001001,B00001001,B00001111,B00001001,B00001001,B00000000};
byte HWD4[] = {B00000000,B00010010,B00010010,B00010010,B00011110,B00010010,B00010010,B00000000};
byte HWD5[] = {B00000000,B00100101,B00100101,B00100101,B00111101,B00100101,B00100101,B00000000};
byte HWD6[] = {B00000000,B01001010,B01001010,B01001010,B01111010,B01001011,B01001010,B00000000};
byte HWD7[] = {B00000000,B10010100,B10010100,B10010100,B11110101,B10010110,B10010100,B00000000};
byte HWD8[] = {B00000000,B00101000,B00101000,B00101000,B11101010,B00101101,B00101000,B00000000};
byte HWD9[] = {B00000000,B01010001,B01010001,B01010001,B11010101,B01011011,B01010001,B00000000};
byte HWD10[] = {B00000000,B10100010,B10100010,B10100010,B10101010,B10110110,B10100010,B00000000};
byte HWD11[] = {B00000000,B01000100,B01000100,B01000100,B01010100,B01101100,B01000100,B00000000};
byte HWD12[] = {B00000000,B10001000,B10001000,B10001000,B10101000,B11011000,B10001000,B00000000};
byte HWD13[] = {B00000000,B00010000,B00010000,B00010000,B01010000,B10110000,B00010000,B00000000};
byte HWD14[] = {B00000000,B00100000,B00100000,B00100000,B10100000,B01100000,B00100000,B00000000};
byte HWD15[] = {B00000000,B01000000,B01000000,B01000000,B01000000,B11000000,B01000000,B00000000};
byte HWD16[] = {B00000000,B10000000,B10000000,B10000000,B10000000,B10000000,B10000000,B00000000};
byte HWD17[] = {B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000};

delay(delaytime2);
  lc.setRow(0,0,HWD0[0]);
  lc.setRow(0,1,HWD0[1]);
  lc.setRow(0,2,HWD0[2]);
  lc.setRow(0,3,HWD0[3]);
  lc.setRow(0,4,HWD0[4]);
  lc.setRow(0,5,HWD0[5]);
  lc.setRow(0,6,HWD0[6]);
  lc.setRow(0,7,HWD0[7]);

  delay(delaytime2);
  lc.setRow(0,0,HWD1[0]);
  lc.setRow(0,1,HWD1[1]);
  lc.setRow(0,2,HWD1[2]);
  lc.setRow(0,3,HWD1[3]);
  lc.setRow(0,4,HWD1[4]);
  lc.setRow(0,5,HWD1[5]);
  lc.setRow(0,6,HWD1[6]);
  lc.setRow(0,7,HWD1[7]);

  delay(delaytime2);
  lc.setRow(0,0,HWD2[0]);
  lc.setRow(0,1,HWD2[1]);
  lc.setRow(0,2,HWD2[2]);
  lc.setRow(0,3,HWD2[3]);
  lc.setRow(0,4,HWD2[4]);
  lc.setRow(0,5,HWD2[5]);
  lc.setRow(0,6,HWD2[6]);
  lc.setRow(0,7,HWD2[7]);

  delay(delaytime2);
  lc.setRow(0,0,HWD3[0]);
  lc.setRow(0,1,HWD3[1]);
  lc.setRow(0,2,HWD3[2]);
  lc.setRow(0,3,HWD3[3]);
  lc.setRow(0,4,HWD3[4]);
  lc.setRow(0,5,HWD3[5]);
  lc.setRow(0,6,HWD3[6]);
  lc.setRow(0,7,HWD3[7]);

  delay(delaytime2);
  lc.setRow(0,0,HWD4[0]);
  lc.setRow(0,1,HWD4[1]);
  lc.setRow(0,2,HWD4[2]);
  lc.setRow(0,3,HWD4[3]);
  lc.setRow(0,4,HWD4[4]);
  lc.setRow(0,5,HWD4[5]);
  lc.setRow(0,6,HWD4[6]);
  lc.setRow(0,7,HWD4[7]);

  delay(delaytime2);
  lc.setRow(0,0,HWD5[0]);
  lc.setRow(0,1,HWD5[1]);
  lc.setRow(0,2,HWD5[2]);
  lc.setRow(0,3,HWD5[3]);
  lc.setRow(0,4,HWD5[4]);
  lc.setRow(0,5,HWD5[5]);
  lc.setRow(0,6,HWD5[6]);
  lc.setRow(0,7,HWD5[7]);

  delay(delaytime2);
  lc.setRow(0,0,HWD6[0]);
  lc.setRow(0,1,HWD6[1]);
  lc.setRow(0,2,HWD6[2]);
  lc.setRow(0,3,HWD6[3]);
  lc.setRow(0,4,HWD6[4]);
  lc.setRow(0,5,HWD6[5]);
  lc.setRow(0,6,HWD6[6]);
  lc.setRow(0,7,HWD6[7]);

  delay(delaytime2);
  lc.setRow(0,0,HWD7[0]);
  lc.setRow(0,1,HWD7[1]);
  lc.setRow(0,2,HWD7[2]);
  lc.setRow(0,3,HWD7[3]);
  lc.setRow(0,4,HWD7[4]);
  lc.setRow(0,5,HWD7[5]);
  lc.setRow(0,6,HWD7[6]);
  lc.setRow(0,7,HWD7[7]);
  
    delay(delaytime2);
  lc.setRow(0,0,HWD8[0]);
  lc.setRow(0,1,HWD8[1]);
  lc.setRow(0,2,HWD8[2]);
  lc.setRow(0,3,HWD8[3]);
  lc.setRow(0,4,HWD8[4]);
  lc.setRow(0,5,HWD8[5]);
  lc.setRow(0,6,HWD8[6]);
  lc.setRow(0,7,HWD8[7]);

    delay(delaytime2);
  lc.setRow(0,0,HWD9[0]);
  lc.setRow(0,1,HWD9[1]);
  lc.setRow(0,2,HWD9[2]);
  lc.setRow(0,3,HWD9[3]);
  lc.setRow(0,4,HWD9[4]);
  lc.setRow(0,5,HWD9[5]);
  lc.setRow(0,6,HWD9[6]);
  lc.setRow(0,7,HWD9[7]);

delay(delaytime2);
  lc.setRow(0,0,HWD10[0]);
  lc.setRow(0,1,HWD10[1]);
  lc.setRow(0,2,HWD10[2]);
  lc.setRow(0,3,HWD10[3]);
  lc.setRow(0,4,HWD10[4]);
  lc.setRow(0,5,HWD10[5]);
  lc.setRow(0,6,HWD10[6]);
  lc.setRow(0,7,HWD10[7]);

  delay(delaytime2);
  lc.setRow(0,0,HWD11[0]);
  lc.setRow(0,1,HWD11[1]);
  lc.setRow(0,2,HWD11[2]);
  lc.setRow(0,3,HWD11[3]);
  lc.setRow(0,4,HWD11[4]);
  lc.setRow(0,5,HWD11[5]);
  lc.setRow(0,6,HWD11[6]);
  lc.setRow(0,7,HWD11[7]);

  delay(delaytime2);
  lc.setRow(0,0,HWD12[0]);
  lc.setRow(0,1,HWD12[1]);
  lc.setRow(0,2,HWD12[2]);
  lc.setRow(0,3,HWD12[3]);
  lc.setRow(0,4,HWD12[4]);
  lc.setRow(0,5,HWD12[5]);
  lc.setRow(0,6,HWD12[6]);
  lc.setRow(0,7,HWD12[7]);

  delay(delaytime2);
  lc.setRow(0,0,HWD13[0]);
  lc.setRow(0,1,HWD13[1]);
  lc.setRow(0,2,HWD13[2]);
  lc.setRow(0,3,HWD13[3]);
  lc.setRow(0,4,HWD13[4]);
  lc.setRow(0,5,HWD13[5]);
  lc.setRow(0,6,HWD13[6]);
  lc.setRow(0,7,HWD13[7]);

  delay(delaytime2);
  lc.setRow(0,0,HWD14[0]);
  lc.setRow(0,1,HWD14[1]);
  lc.setRow(0,2,HWD14[2]);
  lc.setRow(0,3,HWD14[3]);
  lc.setRow(0,4,HWD14[4]);
  lc.setRow(0,5,HWD14[5]);
  lc.setRow(0,6,HWD14[6]);
  lc.setRow(0,7,HWD14[7]);

  delay(delaytime2);
  lc.setRow(0,0,HWD15[0]);
  lc.setRow(0,1,HWD15[1]);
  lc.setRow(0,2,HWD15[2]);
  lc.setRow(0,3,HWD15[3]);
  lc.setRow(0,4,HWD15[4]);
  lc.setRow(0,5,HWD15[5]);
  lc.setRow(0,6,HWD15[6]);
  lc.setRow(0,7,HWD15[7]);

  delay(delaytime2);
  lc.setRow(0,0,HWD16[0]);
  lc.setRow(0,1,HWD16[1]);
  lc.setRow(0,2,HWD16[2]);
  lc.setRow(0,3,HWD16[3]);
  lc.setRow(0,4,HWD16[4]);
  lc.setRow(0,5,HWD16[5]);
  lc.setRow(0,6,HWD16[6]);
  lc.setRow(0,7,HWD16[7]);

  delay(delaytime2);
  lc.setRow(0,0,HWD17[0]);
  lc.setRow(0,1,HWD17[1]);
  lc.setRow(0,2,HWD17[2]);
  lc.setRow(0,3,HWD17[3]);
  lc.setRow(0,4,HWD17[4]);
  lc.setRow(0,5,HWD17[5]);
  lc.setRow(0,6,HWD17[6]);
  lc.setRow(0,7,HWD17[7]);

for (int i = 0 ; i <= 8 ; i++){
  for (int j = 128 ; j >= 1 ; j /= 2){
    delay(50);
    lc.setRow(0,i,j);
  }
  delay(50);
  lc.setRow(0,i,0);
}

for (int j = 128 ; j >= 1 ; j /= 2){
  for (int i = 0 ; i <= 8 ; i++){
    lc.setRow(0,i,j);
    delay(50);
    lc.setRow(0,i,0);
  }
  delay(50);
}


  /* now display them one by one with a small delay */
//   lc.setRow(0,0,ALL[0]);
//   lc.setRow(0,1,ALL[1]);
//   lc.setRow(0,2,ALL[2]);
//   lc.setRow(0,3,ALL[3]);
//   lc.setRow(0,4,ALL[4]);
//   lc.setRow(0,5,ALL[5]);
//   lc.setRow(0,6,ALL[6]);
//   lc.setRow(0,7,ALL[7]);
// delay(delaytime1);
//   lc.setRow(0,0,one[0]);
//   lc.setRow(0,1,one[1]);
//   lc.setRow(0,2,one[2]);
//   lc.setRow(0,3,one[3]);
//   lc.setRow(0,4,one[4]);
//   lc.setRow(0,5,one[5]);
//   lc.setRow(0,6,one[6]);
//   lc.setRow(0,7,one[7]);

  // delay(delaytime1);

  // lc.setRow(0,0,two[0]);
  // lc.setRow(0,1,two[1]);
  // lc.setRow(0,2,two[2]);
  // lc.setRow(0,3,two[3]);
  // lc.setRow(0,4,two[4]);
  // lc.setRow(0,5,two[5]);
  // lc.setRow(0,6,two[6]);
  // lc.setRow(0,7,two[7]);

  // delay(delaytime1);

  // lc.setRow(0,0,three[0]);
  // lc.setRow(0,1,three[1]);
  // lc.setRow(0,2,three[2]);
  // lc.setRow(0,3,three[3]);
  // lc.setRow(0,4,three[4]);
  // lc.setRow(0,5,three[5]);
  // lc.setRow(0,6,three[6]);
  // lc.setRow(0,7,three[7]);

  // lc.setRow(0,0,heartsmile[0]);
  // lc.setRow(0,1,heartsmile[1]);
  // lc.setRow(0,2,heartsmile[2]);
  // lc.setRow(0,3,heartsmile[3]);
  // lc.setRow(0,4,heartsmile[4]);
  // lc.setRow(0,5,heartsmile[5]);
  // lc.setRow(0,6,heartsmile[6]);
  // lc.setRow(0,7,heartsmile[7]);
 
  // delay(delaytime1);
  // lc.setRow(0,0,0);
  // lc.setRow(0,1,0);
  // lc.setRow(0,2,0);
  // lc.setRow(0,3,0);
  // lc.setRow(0,4,0);  
  // lc.setRow(0,5,0);
  // lc.setRow(0,6,0);
  // lc.setRow(0,7,0);
  // delay(delaytime1);

  // delay(delaytime2);
  // lc.setRow(0,0,pluem0[0]);
  // lc.setRow(0,1,pluem0[1]);
  // lc.setRow(0,2,pluem0[2]);
  // lc.setRow(0,3,pluem0[3]);
  // lc.setRow(0,4,pluem0[4]);
  // lc.setRow(0,5,pluem0[5]);
  // lc.setRow(0,6,pluem0[6]);
  // lc.setRow(0,7,pluem0[7]);
  // delay(delaytime2);
  // lc.setRow(0,0,pluem1[0]);
  // lc.setRow(0,1,pluem1[1]);
  // lc.setRow(0,2,pluem1[2]);
  // lc.setRow(0,3,pluem1[3]);
  // lc.setRow(0,4,pluem1[4]);
  // lc.setRow(0,5,pluem1[5]);
  // lc.setRow(0,6,pluem1[6]);
  // lc.setRow(0,7,pluem1[7]);
  // delay(delaytime2);
  // lc.setRow(0,0,pluem2[0]);
  // lc.setRow(0,1,pluem2[1]);
  // lc.setRow(0,2,pluem2[2]);
  // lc.setRow(0,3,pluem2[3]);
  // lc.setRow(0,4,pluem2[4]);
  // lc.setRow(0,5,pluem2[5]);
  // lc.setRow(0,6,pluem2[6]);
  // lc.setRow(0,7,pluem2[7]);
  // delay(delaytime2);
  // lc.setRow(0,0,pluem3[0]);
  // lc.setRow(0,1,pluem3[1]);
  // lc.setRow(0,2,pluem3[2]);
  // lc.setRow(0,3,pluem3[3]);
  // lc.setRow(0,4,pluem3[4]);
  // lc.setRow(0,5,pluem3[5]);
  // lc.setRow(0,6,pluem3[6]);
  // lc.setRow(0,7,pluem3[7]);
  // delay(delaytime2);
  // lc.setRow(0,0,pluem4[0]);
  // lc.setRow(0,1,pluem4[1]);
  // lc.setRow(0,2,pluem4[2]);
  // lc.setRow(0,3,pluem4[3]);
  // lc.setRow(0,4,pluem4[4]);
  // lc.setRow(0,5,pluem4[5]);
  // lc.setRow(0,6,pluem4[6]);
  // lc.setRow(0,7,pluem4[7]);
  // delay(delaytime2);
  // lc.setRow(0,0,pluem5[0]);
  // lc.setRow(0,1,pluem5[1]);
  // lc.setRow(0,2,pluem5[2]);
  // lc.setRow(0,3,pluem5[3]);
  // lc.setRow(0,4,pluem5[4]);
  // lc.setRow(0,5,pluem5[5]);
  // lc.setRow(0,6,pluem5[6]);
  // lc.setRow(0,7,pluem5[7]);
  // delay(delaytime2);
  // lc.setRow(0,0,pluem6[0]);
  // lc.setRow(0,1,pluem6[1]);
  // lc.setRow(0,2,pluem6[2]);
  // lc.setRow(0,3,pluem6[3]);
  // lc.setRow(0,4,pluem6[4]);
  // lc.setRow(0,5,pluem6[5]);
  // lc.setRow(0,6,pluem6[6]);
  // lc.setRow(0,7,pluem6[7]);
  // delay(delaytime2);
  // lc.setRow(0,0,pluem7[0]);
  // lc.setRow(0,1,pluem7[1]);
  // lc.setRow(0,2,pluem7[2]);
  // lc.setRow(0,3,pluem7[3]);
  // lc.setRow(0,4,pluem7[4]);
  // lc.setRow(0,5,pluem7[5]);
  // lc.setRow(0,6,pluem7[6]);
  // lc.setRow(0,7,pluem7[7]);
  // delay(delaytime2);
  // lc.setRow(0,0,pluem8[0]);
  // lc.setRow(0,1,pluem8[1]);
  // lc.setRow(0,2,pluem8[2]);
  // lc.setRow(0,3,pluem8[3]);
  // lc.setRow(0,4,pluem8[4]);
  // lc.setRow(0,5,pluem8[5]);
  // lc.setRow(0,6,pluem8[6]);
  // lc.setRow(0,7,pluem8[7]);
  // delay(delaytime2);
  // lc.setRow(0,0,pluem9[0]);
  // lc.setRow(0,1,pluem9[1]);
  // lc.setRow(0,2,pluem9[2]);
  // lc.setRow(0,3,pluem9[3]);
  // lc.setRow(0,4,pluem9[4]);
  // lc.setRow(0,5,pluem9[5]);
  // lc.setRow(0,6,pluem9[6]);
  // lc.setRow(0,7,pluem9[7]);
  // delay(delaytime2);
  // lc.setRow(0,0,pluem10[0]);
  // lc.setRow(0,1,pluem10[1]);
  // lc.setRow(0,2,pluem10[2]);
  // lc.setRow(0,3,pluem10[3]);
  // lc.setRow(0,4,pluem10[4]);
  // lc.setRow(0,5,pluem10[5]);
  // lc.setRow(0,6,pluem10[6]);
  // lc.setRow(0,7,pluem10[7]);
  // delay(delaytime2);
  // lc.setRow(0,0,pluem11[0]);
  // lc.setRow(0,1,pluem11[1]);
  // lc.setRow(0,2,pluem11[2]);
  // lc.setRow(0,3,pluem11[3]);
  // lc.setRow(0,4,pluem11[4]);
  // lc.setRow(0,5,pluem11[5]);
  // lc.setRow(0,6,pluem11[6]);
  // lc.setRow(0,7,pluem11[7]);
  // delay(delaytime2);
  // lc.setRow(0,0,pluem12[0]);
  // lc.setRow(0,1,pluem12[1]);
  // lc.setRow(0,2,pluem12[2]);
  // lc.setRow(0,3,pluem12[3]);
  // lc.setRow(0,4,pluem12[4]);
  // lc.setRow(0,5,pluem12[5]);
  // lc.setRow(0,6,pluem12[6]);
  // lc.setRow(0,7,pluem12[7]);
  // delay(delaytime2);
  // lc.setRow(0,0,pluem13[0]);
  // lc.setRow(0,1,pluem13[1]);
  // lc.setRow(0,2,pluem13[2]);
  // lc.setRow(0,3,pluem13[3]);
  // lc.setRow(0,4,pluem13[4]);
  // lc.setRow(0,5,pluem13[5]);
  // lc.setRow(0,6,pluem13[6]);
  // lc.setRow(0,7,pluem13[7]);
  // delay(delaytime2);
  // lc.setRow(0,0,pluem14[0]);
  // lc.setRow(0,1,pluem14[1]);
  // lc.setRow(0,2,pluem14[2]);
  // lc.setRow(0,3,pluem14[3]);
  // lc.setRow(0,4,pluem14[4]);
  // lc.setRow(0,5,pluem14[5]);
  // lc.setRow(0,6,pluem14[6]);
  // lc.setRow(0,7,pluem14[7]);
  // delay(delaytime2);
  // lc.setRow(0,0,pluem15[0]);
  // lc.setRow(0,1,pluem15[1]);
  // lc.setRow(0,2,pluem15[2]);
  // lc.setRow(0,3,pluem15[3]);
  // lc.setRow(0,4,pluem15[4]);
  // lc.setRow(0,5,pluem15[5]);
  // lc.setRow(0,6,pluem15[6]);
  // lc.setRow(0,7,pluem15[7]);
  // delay(delaytime2);
  // lc.setRow(0,0,pluem16[0]);
  // lc.setRow(0,1,pluem16[1]);
  // lc.setRow(0,2,pluem16[2]);
  // lc.setRow(0,3,pluem16[3]);
  // lc.setRow(0,4,pluem16[4]);
  // lc.setRow(0,5,pluem16[5]);
  // lc.setRow(0,6,pluem16[6]);
  // lc.setRow(0,7,pluem16[7]);
  // delay(delaytime2);
  // lc.setRow(0,0,pluem17[0]);
  // lc.setRow(0,1,pluem17[1]);
  // lc.setRow(0,2,pluem17[2]);
  // lc.setRow(0,3,pluem17[3]);
  // lc.setRow(0,4,pluem17[4]);
  // lc.setRow(0,5,pluem17[5]);
  // lc.setRow(0,6,pluem17[6]);
  // lc.setRow(0,7,pluem17[7]);
  // delay(delaytime2);
  // lc.setRow(0,0,pluem18[0]);
  // lc.setRow(0,1,pluem18[1]);
  // lc.setRow(0,2,pluem18[2]);
  // lc.setRow(0,3,pluem18[3]);
  // lc.setRow(0,4,pluem18[4]);
  // lc.setRow(0,5,pluem18[5]);
  // lc.setRow(0,6,pluem18[6]);
  // lc.setRow(0,7,pluem18[7]);
  // delay(delaytime2);
  // lc.setRow(0,0,pluem19[0]);
  // lc.setRow(0,1,pluem19[1]);
  // lc.setRow(0,2,pluem19[2]);
  // lc.setRow(0,3,pluem19[3]);
  // lc.setRow(0,4,pluem19[4]);
  // lc.setRow(0,5,pluem19[5]);
  // lc.setRow(0,6,pluem19[6]);
  // lc.setRow(0,7,pluem19[7]);
  // delay(delaytime2);
  // lc.setRow(0,0,pluem20[0]);
  // lc.setRow(0,1,pluem20[1]);
  // lc.setRow(0,2,pluem20[2]);
  // lc.setRow(0,3,pluem20[3]);
  // lc.setRow(0,4,pluem20[4]);
  // lc.setRow(0,5,pluem20[5]);
  // lc.setRow(0,6,pluem20[6]);
  // lc.setRow(0,7,pluem20[7]);
  // delay(delaytime2);
  // lc.setRow(0,0,pluem21[0]);
  // lc.setRow(0,1,pluem21[1]);
  // lc.setRow(0,2,pluem21[2]);
  // lc.setRow(0,3,pluem21[3]);
  // lc.setRow(0,4,pluem21[4]);
  // lc.setRow(0,5,pluem21[5]);
  // lc.setRow(0,6,pluem21[6]);
  // lc.setRow(0,7,pluem21[7]);
  // delay(delaytime2);
  // lc.setRow(0,0,pluem22[0]);
  // lc.setRow(0,1,pluem22[1]);
  // lc.setRow(0,2,pluem22[2]);
  // lc.setRow(0,3,pluem22[3]);
  // lc.setRow(0,4,pluem22[4]);
  // lc.setRow(0,5,pluem22[5]);
  // lc.setRow(0,6,pluem22[6]);
  // lc.setRow(0,7,pluem22[7]);
  // delay(delaytime2);
  // lc.setRow(0,0,pluem23[0]);
  // lc.setRow(0,1,pluem23[1]);
  // lc.setRow(0,2,pluem23[2]);
  // lc.setRow(0,3,pluem23[3]);
  // lc.setRow(0,4,pluem23[4]);
  // lc.setRow(0,5,pluem23[5]);
  // lc.setRow(0,6,pluem23[6]);
  // lc.setRow(0,7,pluem23[7]);
  // delay(delaytime2);
  // lc.setRow(0,0,pluem24[0]);
  // lc.setRow(0,1,pluem24[1]);
  // lc.setRow(0,2,pluem24[2]);
  // lc.setRow(0,3,pluem24[3]);
  // lc.setRow(0,4,pluem24[4]);
  // lc.setRow(0,5,pluem24[5]);
  // lc.setRow(0,6,pluem24[6]);
  // lc.setRow(0,7,pluem24[7]);
  // delay(delaytime2);
  // lc.setRow(0,0,pluem25[0]);
  // lc.setRow(0,1,pluem25[1]);
  // lc.setRow(0,2,pluem25[2]);
  // lc.setRow(0,3,pluem25[3]);
  // lc.setRow(0,4,pluem25[4]);
  // lc.setRow(0,5,pluem25[5]);
  // lc.setRow(0,6,pluem25[6]);
  // lc.setRow(0,7,pluem25[7]);
  // delay(delaytime2);
  // lc.setRow(0,0,pluem26[0]);
  // lc.setRow(0,1,pluem26[1]);
  // lc.setRow(0,2,pluem26[2]);
  // lc.setRow(0,3,pluem26[3]);
  // lc.setRow(0,4,pluem26[4]);
  // lc.setRow(0,5,pluem26[5]);
  // lc.setRow(0,6,pluem26[6]);
  // lc.setRow(0,7,pluem26[7]);
  // delay(delaytime2);
  // lc.setRow(0,0,pluem27[0]);
  // lc.setRow(0,1,pluem27[1]);
  // lc.setRow(0,2,pluem27[2]);
  // lc.setRow(0,3,pluem27[3]);
  // lc.setRow(0,4,pluem27[4]);
  // lc.setRow(0,5,pluem27[5]);
  // lc.setRow(0,6,pluem27[6]);
  // lc.setRow(0,7,pluem27[7]);
  // delay(delaytime2);
  // lc.setRow(0,0,pluem28[0]);
  // lc.setRow(0,1,pluem28[1]);
  // lc.setRow(0,2,pluem28[2]);
  // lc.setRow(0,3,pluem28[3]);
  // lc.setRow(0,4,pluem28[4]);
  // lc.setRow(0,5,pluem28[5]);
  // lc.setRow(0,6,pluem28[6]);
  // lc.setRow(0,7,pluem28[7]);
  // delay(delaytime2);
  // lc.setRow(0,0,pluem29[0]);
  // lc.setRow(0,1,pluem29[1]);
  // lc.setRow(0,2,pluem29[2]);
  // lc.setRow(0,3,pluem29[3]);
  // lc.setRow(0,4,pluem29[4]);
  // lc.setRow(0,5,pluem29[5]);
  // lc.setRow(0,6,pluem29[6]);
  // lc.setRow(0,7,pluem29[7]);
  // delay(delaytime2);
  // lc.setRow(0,0,pluem30[0]);
  // lc.setRow(0,1,pluem30[1]);
  // lc.setRow(0,2,pluem30[2]);
  // lc.setRow(0,3,pluem30[3]);
  // lc.setRow(0,4,pluem30[4]);
  // lc.setRow(0,5,pluem30[5]);
  // lc.setRow(0,6,pluem30[6]);
  // lc.setRow(0,7,pluem30[7]);
  // delay(delaytime2);
  // lc.setRow(0,0,heartsmile[0]);
  // lc.setRow(0,1,heartsmile[1]);
  // lc.setRow(0,2,heartsmile[2]);
  // lc.setRow(0,3,heartsmile[3]);
  // lc.setRow(0,4,heartsmile[4]);
  // lc.setRow(0,5,heartsmile[5]);
  // lc.setRow(0,6,heartsmile[6]);
  // lc.setRow(0,7,heartsmile[7]);
  // delay(delaytime1);
  // lc.setRow(0,0,0);
  // lc.setRow(0,1,0);
  // lc.setRow(0,2,0);
  // lc.setRow(0,3,0);
  // lc.setRow(0,4,0);  
  // lc.setRow(0,5,0);
  // lc.setRow(0,6,0);
  // lc.setRow(0,7,0);
  // delay(delaytime1);
  // lc.setRow(0,0,heartsmile[0]);
  // lc.setRow(0,1,heartsmile[1]);
  // lc.setRow(0,2,heartsmile[2]);
  // lc.setRow(0,3,heartsmile[3]);
  // lc.setRow(0,4,heartsmile[4]);
  // lc.setRow(0,5,heartsmile[5]);
  // lc.setRow(0,6,heartsmile[6]);
  // lc.setRow(0,7,heartsmile[7]);
  // delay(delaytime1);
}


void loop() { 
  writeArduinoOnMatrix();
}