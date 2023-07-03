#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
int Encoder_OutputA = A0; // CLK of the encoder
int Encoder_OutputB = A1; // DT of the encoder 
int Encoder_Switch = A2;  // Encoder sw

#define inputTimeOut 10000
////Global time variable, Hour : Minute Settings
//unsigned int setHour = 0;
//unsigned int setMinute = 0;
////////

char *menu1[] = {"1.Rojo ", "2.Azul ", "3.Verde","4.Amari", "5.Blanc", "6.Back "}; //Menu declaration
char *rojo[] = {"1.Rojo01", "2.Ojo02","3.Back "}; //submenu for the first item of main maanu
///////
bool humanInputActive = false;

//unsigned long inputTimeOut = 10000;   //time out for human input session, milliseconds
unsigned long lastInputTime = millis(); //keep track of time of last human input

int Previous_Output;
int Encoder_Count;
////////////////////

int Menu1Max = 5; //max value for Menu1.
//int Menu1Min = 0; //min value for Menu1.

int rojoTop = 3;

///////////////////
void setup() {
  lcd.init();
  lcd.backlight();
  printAt("Rotary Encoder", 0, 0);
  printAt("With Arduino", 0, 1);
 //printAt(menu1[Encoder_Count], 0, 1);
  //delay(2000);
  //Pin Mode decleration
  pinMode(Encoder_OutputA, INPUT);
  pinMode(Encoder_OutputB, INPUT);
  pinMode(Encoder_Switch, INPUT);

  Previous_Output = digitalRead(Encoder_OutputA);
}

//Main run time 
void loop() {
  RtUpdate();
  lcdBackLight(); 
}

//Rotary Encoder Update()
void RtUpdate(){
  if (digitalRead(Encoder_OutputA) != Previous_Output)
  {
    lastInputTime = millis();
    if (digitalRead(Encoder_OutputB) != Previous_Output)
    {
      Encoder_Count++;
      if(Encoder_Count > Menu1Max){Encoder_Count = Menu1Max;}
      lcd.clear();
      //lcd.print(Encoder_Count);
      lcd.print(menu1[Encoder_Count]);
      //printAt(menu1[Encoder_Count], 0, 0);
      //printAt("Clockwise", 0, 1);
    }
    else
    {
      Encoder_Count--;
      if(Encoder_Count < 0){Encoder_Count = 0;}
      lcd.clear();
      //lcd.print(Encoder_Count);
      //lcd.print(menu1[Encoder_Count]);
      printAt(menu1[Encoder_Count], 0, 0);
      //printAt("Anti - Clockwise", 0, 1);
    }
  }
  Previous_Output = digitalRead(Encoder_OutputA);
  if (digitalRead(Encoder_Switch) == 0)
  {
    lastInputTime = millis();
    lcd.clear();
    printAt("Switch Pressed", 0, 0);
    printAt(rojo[Encoder_Count], 0, 1);
  }
  //input time out
  if ( (millis() - lastInputTime) > inputTimeOut ) {
    humanInputActive = false;
  } else {
    humanInputActive = true;
  }
}
//Lcd print function
void printAt(char *s, int col, int row) {
  int i = 0;
  while (s[i] != 0) {
    lcd.setCursor(col + i, row);
    lcd.print(s[i]);
    i++;
  }
}
//StandBy BakLight
void lcdBackLight() {
  //human inout timeout to turn off lcd back light
  if (humanInputActive == true) {
    lcd.backlight();
  } else {
    lcd.noBacklight();
    lcd.clear();
  }
}

//if switche pressed for first option of the main menu
void swp(){
    }