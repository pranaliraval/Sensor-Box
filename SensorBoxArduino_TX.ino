//#include <Servo. h>
#include <SoftwareSerial.h>

SoftwareSerial myserial(10,11);
//variables
int ledstate = 0; // defines ledstate
int light = 0;   
int mode = 0;
int data = 0;
int outputmode = 0;

// outputs
int buzzer = 5;
int led = 3;
int trig = 9;
int motor = 6;

// sensors
int gassensor = A2;
int touchsensor = 2;
int echo = 12;
int ldrpin = A1;
int soundpin = A0;
int watersensor = 7;
int irsensor = 8;
int inputbutton = 4;
int outputbutton = 13;
//Servo myservo;

void setup()
{
  Serial.begin(9600);
  myserial.begin(9600);
  //myservo.attach(6);
  //Serial1.begin(38400);
  pinMode(buzzer, OUTPUT);
  pinMode(led, OUTPUT);
  pinMode(trig, OUTPUT);
  pinMode(motor, OUTPUT);

  pinMode(touchsensor, INPUT);
  pinMode(gassensor, INPUT);
  pinMode(soundpin, INPUT);
  pinMode(ldrpin, INPUT_PULLUP);
  pinMode(inputbutton, INPUT_PULLUP);
  pinMode(watersensor, INPUT);
  pinMode(irsensor, INPUT);
  pinMode(echo, INPUT);
  pinMode(outputbutton, INPUT_PULLUP);
  // put your setup code here, to run once:


  digitalWrite(led, HIGH);
  digitalWrite(buzzer, LOW);
  //myservo.write(0);
  digitalWrite(motor, HIGH);

}
void output();
void loop()
{
  if (mode == 1)
  {
    sound();

  }
  else if (mode == 2)
  {
    ir();
  }

  else if (mode == 3)
  {
    distance();
  }

  else if (mode == 4)
  {
    ldr();
  }

  else if (mode == 5 )
  {
    gas();
  }

  else if (mode == 6 )
  {
    touch();
  }
  else if (mode == 7)
  {
    water();
  }
  for (int i = 0; i < 200; i++)
  {
    modeinputbutton();
    modeoutputbutton();
    delay(1);
  }
  //  Serial.print("mode=");
  //  Serial.println(mode);
 //String m = String(mode);
 //String o = String(outputmode);
 //String d = String(data);
 String m = "";
  String d = "";
  m = m + mode;
  d = d + data;

  //Serial.println("mode=" + m + " data:" + d );
  // Serial1.println("mode=" + m + " data:" + d );
  //myserial.write("I/p Mode = ");
  //Serial.println("input =");
  //Serial.println(mode); 
 // myserial.print(mode);
 // myserial.write(m);
  //myserial.write(",");
  //myserial.write(" O/p Mode = ");
  //myserial.print(outputmode);
  //myserial.write(o);
  //myserial.write(",");
// myserial.write('\n');
 //myserial.write("Data = ");
 //myserial.print(data);
  //myserial.write(d);
  //myserial.write(",");
 // myserial.write('\n');
 myserial.println("mode=" + m + " data:" + d );
 Serial.println("mode=" + m + " data:" + d);
  //delay(20);
  //Serial.println("Output Mode");
   //Serial.println(outputmode);
  output();
  //delay(100);

}


void gas() {
  // read the input on analog pin 0:
  int sensorValue = analogRead(gassensor);
  //Serial.println("sensor value=");
  //Serial.println(sensorValue);
  //Serial1.println(sensorValue);
  data = sensorValue;
}

void touch() {
  // read the input pin:
  for (int i = 0; i < 500; i++)
  {
    if (digitalRead(touchsensor) == 1)
    {
      data = 1;
      break;
    }
    data = 0;
    delay(1);

  }


  //Serial.print("touch");
  //Serial.println(data);
  //Serial1.println(value);
  //data=value;

}
void distance()
{
 // pinMode(trig, OUTPUT);
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  int d = pulseIn(echo, HIGH); //Listen for echo
  d = (d / 58.138); //convert to CM then to inches

  data = d;

}

void ldr()
{
  light = analogRead(ldrpin);
  //Serial.println(light);
  data = light;
  // threshold = 500;
  //Serial1.println(light);
}

void water()
{
  data = digitalRead(watersensor);
  //Serial.println("Water");
  //Serial.println(data);

}
/*void ser()
  {
    int val = map(data, 0, 30, 2, 10 ); // for speed
   //int val=map(data,0,20,180,0); for angle
    for(int i=0;i<180;i++)
    {
    myservo.write(i);
    delay(val);
    }
    
    for(int i=180;i>0;i--)
    {
    myservo.write(i);
    delay(val);
    }
             
  }*/
void ir()
{
  data = digitalRead(irsensor);
  //Serial.println("Proximity");
  //Serial.println(data);

}
void sound()
{
  int sound = analogRead(soundpin);
  //Serial.println(sound);
  data=sound;
 // threshold = 100;
}
/*void ser_sound()
  {
    int val = map(data, 100, 500, 10, 2); // for speed
   //int val=map(data,0,20,180,0); for angle
    for(int i=0;i<180;i++)
    {
    myservo.write(i);
    delay(val);
    }
    
    for(int i=180;i>0;i--)
    {
    myservo.write(i);
    delay(val);
    }
             
  }
  void ser_gas()
  {
   int  val = map(data, 400, 800, 10, 2); // for speed
   //int val=map(data,0,20,180,0); for angle
    for(int i=0;i<180;i++)
    {
    myservo.write(i);
    delay(val);
    }
    
    for(int i=180;i>0;i--)
    {
    myservo.write(i);
    delay(val);
    }
             
  }
void ser_ldr()
  {
    int val = map(data, 650, 1000, 10, 2); // for speed
   //int val=map(data,0,20,180,0); for angle
    for(int i=0;i<180;i++)
    {
    myservo.write(i);
    delay(val);
    }
    
    for(int i=180;i>0;i--)
    {
    myservo.write(i);
    delay(val);
    }
             
  }*/


void modeinputbutton() {
  // put your main code here, to run repeatedly:
  if (digitalRead(inputbutton) == LOW)
  {
    mode++;
    while (digitalRead(inputbutton) == LOW);
    delay(10);
  }
  if (mode >= 8)
    mode = 0;

  
}

void modeoutputbutton() {
  // put your main code here, to run repeatedly:
  if (digitalRead(outputbutton) == LOW)
  {
    outputmode++;
    while (digitalRead(outputbutton) == LOW);
    delay(10);

    digitalWrite(led, HIGH);
    digitalWrite(buzzer, LOW);
   // myservo.write(0);
   digitalWrite(motor, HIGH);
    
    if(outputmode>=4)
    outputmode = 0;
  }

}

void output()
{
  if (mode == 2 || mode == 7 || mode == 6)
  {
    if (data == 1)
    {
      if (outputmode == 3)
        digitalWrite(led, LOW);

      else if (outputmode == 1)
        digitalWrite(buzzer, HIGH);
        
      else if (outputmode == 2)
        //ser();
        digitalWrite(motor, LOW);
    }

    else if (data == 0)
    {
      if (outputmode == 3)
        digitalWrite(led, HIGH);

      else if (outputmode == 1)
        digitalWrite(buzzer, LOW);

      else if (outputmode == 2)
        //myservo.write(0); // this code will  off the servo 
        digitalWrite(motor, HIGH);
    }

  }

  else if (mode == 5)
  {
    if (data > 400)
    {
      if (outputmode == 3)
      {
        digitalWrite(led, LOW);
      }

      else if (outputmode == 1)
      {
        digitalWrite(buzzer,HIGH);
      }
        

      else if (outputmode == 2)
      {
      
        //ser_gas();
        digitalWrite(motor, LOW);
      }
      }
    
    else
    {
      if (outputmode == 3)
        digitalWrite(led, HIGH);

      else if (outputmode == 1)
        digitalWrite(buzzer,LOW);

      else if (outputmode == 2)
        //myservo.write(0);
        digitalWrite(motor, HIGH);
    }

  }
 else if (mode == 3)
  {
    if (data < 30)
    {
      //data = 30;
    int x = map(data, 0, 30, 200, 1000);
    if (outputmode == 3)
    {
      digitalWrite(led,LOW);
      delay(x);
      digitalWrite(led, HIGH);
      delay(x);
    }

    else if (outputmode == 1)
    {
      digitalWrite(buzzer, HIGH);
      delay(x);
      digitalWrite(buzzer, LOW);
      delay(x);
    }

    else if (outputmode == 2)
    {
      digitalWrite(motor, LOW);
    }
    }
  else
    {
    if (outputmode == 3)
        digitalWrite(led, HIGH);

      else if (outputmode == 1)
        digitalWrite(buzzer,LOW);

      else if (outputmode == 2)
      {
        //myservo.write(0);
        digitalWrite(motor, HIGH);
    }
  }  
  }
  else if (mode == 4)
  {
    if (data>400)
    {
    //data=400;
    //int x = map(data, 400, 700, 0, 100);
    if (outputmode == 3)
    {
        digitalWrite(led,LOW);
        
    }
    else if (outputmode == 1)
    {
      digitalWrite(buzzer, HIGH);
    }
    
    else if (outputmode == 2)
    {
       //ser_ldr();
       digitalWrite(motor, LOW);
    }
    }
    else
    {
      if (outputmode == 3)
    {
        digitalWrite(led,HIGH);
    }
      else if (outputmode == 1)
      {
        digitalWrite(buzzer,LOW);
      }

      else if (outputmode == 2)
      {
        //myservo.write(0);
        digitalWrite(motor, HIGH);
      }
    }
    }
    else if(mode==1)
    {
        if (data > 50)
    {
      if (outputmode == 3)
      {
        digitalWrite(led, LOW);
      }

      else if (outputmode == 1)
      {
        digitalWrite(buzzer,HIGH);
      }
        

      else if (outputmode == 2)
      {
        //ser_sound();
        digitalWrite(motor, LOW);
      }
    }
    else
    {
      if (outputmode == 3)
      {
        digitalWrite(led, HIGH);
      }

      else if (outputmode == 1)
      {
        digitalWrite(buzzer, LOW);
      }

      else if (outputmode == 2)
      {
        //myservo.write(0);
        digitalWrite(motor, HIGH);
      }
    }
        
      }
  
    
}
