#include<LiquidCrystal.h>
#include<Servo.h>
Servo s;

int slot1 = 31;
int slot2 = 32;
int slot3 = 33;
int slot4 = 34;
int slot5 = 35;
int slot6 = 36;

const int rs= 12,en= 11, d4= 5, d5 =4, d6 =3 , d7 = 2;
int counter=0,c1=0,c2=0,c3=0,c4=0,c5=0,c6=0;

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup(){

 lcd.begin(16,2);
 //
   Serial.begin(9600);
  pinMode(slot1,INPUT);
  pinMode(slot2,INPUT);
  pinMode(slot3,INPUT);
  pinMode(slot4,INPUT);
  pinMode(slot5,INPUT);
  pinMode(slot6,INPUT);
  pinMode(41,OUTPUT);
 s.attach(8);
 s.write(0);
 delay(100);
}

void loop()
{

    
    if(digitalRead(slot1))
    {
         Serial.println("slot1");
        lcd.setCursor(4,0);
         lcd.print("1"); 
         lcd.setCursor(4,1);
         lcd.print("X");
         digitalWrite(41,LOW);
         c1=0;
    }
    else
    {
         lcd.setCursor(4,0);
         lcd.setCursor(4,1);
         lcd.print("1");
         digitalWrite(41,HIGH);
         c1=1;
    }
   ////slot2
    if(digitalRead(slot2))
    {
         Serial.println("slot2");
         lcd.setCursor(6,0);
         lcd.print("2"); 
         lcd.setCursor(6,1);
         lcd.print("X");
         c2=0; 
    }
    else
    {
        lcd.setCursor(6,0);
         lcd.print("2"); 
         lcd.setCursor(6,1);
         lcd.print("1");
         c2=1;
    }
    //////// slot3
    if(digitalRead(slot3))
    {
         Serial.println("slot3");
         lcd.setCursor(8,0);
         lcd.print("3"); 
         lcd.setCursor(8,1);
         lcd.print("X");
         c3=0; 
    }
    else
    {
        lcd.setCursor(8,0);
         lcd.print("3"); 
         lcd.setCursor(8,1);
         lcd.print("1");
         c3=1;
    }
    
  counter= c1+c2+c3+c4+c6;
   lcd.setCursor(12,0);
    lcd.print("C");
    lcd.setCursor(12,1);
    lcd.print(counter);
    
  
}

