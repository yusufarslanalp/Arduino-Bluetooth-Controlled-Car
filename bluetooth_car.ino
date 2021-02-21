#include <SoftwareSerial.h>

SoftwareSerial bt_conn(2,3); //RX TX

int input1 = 8; //input1 and input2 feeds motor1
int input2 = 9;
int input3 = 10; //input3 and input4 feeds motor2
int input4 = 11;


void setup() {
  Serial.begin(9600);
  bt_conn.begin(9600);

  
  pinMode(input1, OUTPUT);
  pinMode(input2, OUTPUT);
  pinMode(input3, OUTPUT);
  pinMode(input4, OUTPUT);

}

void loop() {
  
  if( bt_conn.available() )
  {
      char data = bt_conn.read(); //if there is no data nothing will print. and program will continue.
      Serial.println( data );

      if( data == 'p' ) //pause
      {
        my_stop();
        Serial.println( "geldi" );
      }
  
      if( data == 'f' ) //forward
      {
        forward();
        Serial.println( "geldi" );
      }

      if( data == 'b' ) //backward
      {
        backward();
        Serial.println( "geldi" );
      }

      if( data == 'r' ) //right
      {
        right();
        Serial.println( "geldi" );
      }

      if( data == 'l' ) //left
      {
        left();
        Serial.println( "geldi" );
      }
  }

}

void forward()
{
  analogWrite(input1, 255);
  analogWrite(input2, 0);

  analogWrite(input3, 0);
  analogWrite(input4, 255);  
}

void backward()
{
  analogWrite(input1, 0);
  analogWrite(input2, 255);

  analogWrite(input3, 255);
  analogWrite(input4, 0);  
}

void left()
{
  analogWrite(input1, 0);
  analogWrite(input2, 255);

  analogWrite(input3, 0);
  analogWrite(input4, 255); 
}

void right()
{
  analogWrite(input1, 255);
  analogWrite(input2, 0);

  analogWrite(input3, 255);
  analogWrite(input4, 0); 
}

void my_stop()
{
  analogWrite(input1, 0);
  analogWrite(input2, 0);

  analogWrite(input3, 0);
  analogWrite(input4, 0); 
}
