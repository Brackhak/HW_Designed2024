#include <LiquidCrystal_I2C.h>

#include <Wire.h>

LiquidCrystal_I2C lcd(0x27,16,2);

byte zerothai[] = {
  B01110,
  B10001,
  B10001,
  B10001,
  B10001,
  B10001,
  B10001,
  B01110
};
byte onethai[] = {
  B00000,
  B00000,
  B01110,
  B10101,
  B11101,
  B00001,
  B11110,
  B00000
};

byte twothai[] = {
  B10000,
  B10000,
  B11011,
  B10101,
  B10001,
  B10001,
  B01110,
  B00000
};

byte threethai[] = {
  B00000,
  B00000,
  B11011,
  B10101,
  B10001,
  B11001,
  B11001,
  B00000
};


byte fourthai[] = {
  B00010,
  B00100,
  B01000,
  B10011,
  B10011,
  B10010,
  B11111,
  B00000
};

byte fivethai[] = {
  B00001,
  B01110,
  B01100,
  B11011,
  B10011,
  B10010,
  B11111,
  B00000
};

byte sixthai[] = {
  B00000,
  B10000,
  B01110,
  B00001,
  B00001,
  B01101,
  B01111,
  B00000
};
byte seventhai[] = {
  B00000,
  B00001,
  B00001,
  B11011,
  B10101,
  B10001,
  B11001,
  B00000
};

byte eightthai[] = {
  B00001,
  B00010,
  B01100,
  B10000,
  B10000,
  B10101,
  B11011,
  B00000
};


byte ninethai[] = {
  B00000,
  B00001,
  B00001,
  B11010,
  B10100,
  B10010,
  B11001,
  B00000
};

int h=12;
int m=59;
int s=45;

int h1,h2,m1,m2,s1,s2=0;


int flag=1;
static uint32_t last_time, now = 0;

int button1;
int button2;
int hs=2;
int ms=3;

void setup() {
  // put your setup code here, to run once:
  lcd.init();
lcd.backlight();


lcd.createChar(0, onethai);
lcd.createChar(1, twothai);
lcd.createChar(2, fourthai);
lcd.createChar(3, fivethai);
lcd.createChar(4, sixthai);
lcd.createChar(5, seventhai);
lcd.createChar(6, eightthai);
lcd.createChar(7, ninethai);



lcd.setCursor(0, 0);
lcd.print("Thai Clock");





lcd.setCursor(0, 1);
lcd.print("Robot!! Tum");
now=millis();
}

void loop() {
  lcd.setCursor(0, 1);
  lcd.print("Time ");
  if(h2 == 0)lcd.print("o");
  else if(h2 < 3)lcd.write(h2-1);
  else if (h2 == 3)lcd.print("m");
  else if (h2 > 3)lcd.write(h2-2);
  if(h1 == 0)lcd.print("o");
  else if(h1 < 3)lcd.write(h1-1);
  else if (h1 == 3)lcd.print("m");
  else if (h1 > 3)lcd.write(h1-2);
  lcd.print(":");
  ///////////////////////////////////////////////////
  if(m2 == 0)lcd.print("o");
  else if(m2 < 3)lcd.write(m2-1);
  else if (m2 == 3)lcd.print("m");
  else if (m2 > 3)lcd.write(m2-2);
  if(m1 == 0)lcd.print("o");
  else if(m1 < 3)lcd.write(m1-1);
  else if (m1 == 3)lcd.print("m");
  else if (m1 > 3)lcd.write(m1-2);
  lcd.print(":");
  //////////////////////////////////////////////
  if(s2 == 0)lcd.print("o");
  else if(s2 < 3)lcd.write(s2-1);
  else if (s2 == 3)lcd.print("m");
  else if (s2 > 3)lcd.write(s2-2);
  if(s1 == 0)lcd.print("o");
  else if(s1 < 3)lcd.write(s1-1);
  else if (s1 == 3)lcd.print("m");
  else if (s1 > 3)lcd.write(s1-2);
  // put your main code here, to run repeatedly:

  // if(flag==0) lcd.print(" AM");
  // if(flag==1) lcd.print(" PM");

  for ( int i=0 ;i<5 ;i++)
  {

    while ((now-last_time)<200)
    {
      now=millis();
    }
    last_time=now;
    button1=digitalRead(hs);
    button2=digitalRead(ms);
    if (button1 == 1){
      h1 = h1+1;
    }

    if (button2 == 1){
      s1 = 0; 
      s2 = 0;     
      m1 = m1 + 1;      
    }

    if (s1 == 10) {
    
      s2 = s2 + 1;
      s1 = 0;
      if (s2 == 6 ) {
        s2 = 0;
        m1 = m1 + 1;
      }
    }
    if (m1 == 10){
      m2 = m2 + 1;
      m1 = 0;
      if (m2 == 6) {
        m2 = 0;
        h1 = h1 + 1;
      }    
    }
    if (h2 != 2 & h1 == 10){
      h2 = h2 + 1;
      h1 = 0;
    
    }
    else if(h2 == 2 & h1 == 4) {
      h2 = 0;
      h1 = 0;
      m1 = 0;
      m2 = 0;
      s1 = 0;
      s2 = 0;      
    }

  }


  
  // s=s+1;
  // if(s==60){
  //   s=0;
  //   m=m+1;
  // }
  // if(m==60)
  // {
  //   m=0;
  //   h=h+1;
  // }
  // if(h==24)
  // {
  //   h=0;
  //   // flag=flag+1;
  //   // if(flag==2)flag=0;
  // }


  s1 = s1+1;
  if (s1 == 10) {
    
    s2 = s2 + 1;
    s1 = 0;
    if (s2 == 6 ) {
      s2 = 0;
      m1 = m1 + 1;
    }
  }
  if (m1 == 10){
    m2 = m2 + 1;
    m1 = 0;
    if (m2 == 6) {
      m2 = 0;
      h1 = h1 + 1;
    }    
  }
  if (h2 != 2 & h1 == 10){
    h2 = h2 + 1;
    h1 = 0;
  
  }
  else if(h2 == 2 & h1 == 4) {
    h2 = 0;
    h1 = 0;
  }


}