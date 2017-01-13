
// include the library code:
#include <LiquidCrystal.h>

//#include <SoftwareSerial.h>

//SoftwareSerial mySerial(2, 3); // RX, TX

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

void setup() {

  Serial.begin(9600);
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("Hello, world!");
  Serial1.begin(9600);
}

void loop() {
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  String s = "";
  if (Serial1.available()) {
    
    while (Serial1.available())
    {
      char ch = Serial1.read();

      s = s + ch;
      delay(1);
    }
    Serial.println(s);
    if(s.length()>5)
    {
    int x = s.indexOf('=');
    int mode = int(s.charAt(x + 1) - '0');
    int data = s.substring(s.indexOf(':') + 1).toInt();
    Serial.println(mode);


    lcd.clear();

    if(mode==0)
    {
      lcd.print("Hello, world!");
      
    }
    
    else if(mode==5)
    {
      lcd.print("GAS SENSOR");
      lcd.setCursor(0,1);
      lcd.print("VALUE=");
      lcd.print(data);
      delay(600);
    }

    else if(mode==3)
    {
      lcd.print("ULTRASONIC");
      lcd.setCursor(0,1);
      lcd.print("DISTANCE=");
      lcd.print(data);
      lcd.print(" cm");
      delay(600);
    }

    else if(mode==6)
    {
      lcd.print("TOUCH SENSOR");
      lcd.setCursor(0,1);
      if(data==0)
      lcd.print("NO TOUCH SENSED");

      else
      lcd.print("TOUCH SENSED");
    }

    else if(mode==4)
    {
      lcd.print("LIGHT SENSOR");
      lcd.setCursor(0,1);
      lcd.print("VALUE=");
      lcd.print(data);
      delay(600);

    }

    else if(mode==7)
    {
      lcd.print("WATER SENSOR");
      lcd.setCursor(0,1);
     

    if(data==0)
     lcd.print("NO WATER");

      else
      lcd.print("WATER DETECTED");
    }

     else if(mode==2)
    {
      lcd.print("IR SENSOR");
      lcd.setCursor(0,1);
     

    if(data==0)
     lcd.print("NOTHING");

      else
      lcd.print("HELLO FRIEND");
    }
    else if(mode==1)
    {
      lcd.print("SOUND SENSOR");
      lcd.setCursor(0,1);
     

    if(data>50)
     lcd.print("SOUND DETECTED");

      else
      lcd.print("NO SOUND");
      //delay(3000);
    }


    }
    Serial.println(s.length());
    Serial.println(s);
    delay(10);
  }
  
}

