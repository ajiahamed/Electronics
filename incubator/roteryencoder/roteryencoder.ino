/**************
 * VCC to 5V  *
 * GND to GND *
 * CLK to A2  *
 * DT to A3  *
 **************/
int pinA = A2;
int pinB = A3; 
int encoderPosCount = 0; 
int pinALast;  
int aVal;
boolean bCW;

 void setup() 
 { 
  //SET pinA and pinB and input
   pinMode (pinA,INPUT);
   pinMode (pinB,INPUT);
   pinALast = digitalRead(pinA);//Read Pin A 
   Serial.begin (9600);
   Serial.println("BEGIN");
   Serial.println();
 } 

 void loop() 
 { 
   aVal = digitalRead(pinA);
   if (aVal != pinALast)
   { 
     if (digitalRead(pinB) != aVal) //We're Rotating Clockwise
     { 
       encoderPosCount ++;
       bCW = true;
     } 
     
     else 
     
     {
       bCW = false;
       encoderPosCount--;
     }
     
     if (bCW)
     {
       Serial.println ("Rotate Clockwise");
     }
     
     else
     
     {
       Serial.println("Rotate Counterclockwise");
     }
     
     Serial.print("Encoder Count: ");
     Serial.println(encoderPosCount);
     Serial.println();
   } 
   
   pinALast = aVal;
 } 
