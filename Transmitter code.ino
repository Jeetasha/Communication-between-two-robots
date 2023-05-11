//to send and retransmit messages
#include <VirtualWire.h>
//Pointer variable of character type
char *data;
char t;
//This function will run only once
void setup() {
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  //Function for initiating the serial communication
  Serial.begin(9600);
  //Function used to set pin 2 as the transmitter pin
  vw_set_tx_pin(2);
  vw_setup(2000);
}
void loop() {
  // put your main code here, to run repeatedly:
  while (Serial.available()) {
    t = Serial.read();//The data from the serial is read into variable t
    Serial.println(t);
    //Forward
    if (t == 'F') 
    {
      digitalWrite(4, HIGH);
      digitalWrite(5, LOW);
      digitalWrite(6, LOW);
      digitalWrite(7, HIGH);
      data = "f";
      vw_send((uint8_t *)data, strlen(data));  //uint8_t is the array of 8 bit integers
      vw_wait_tx();
    }
    //BACKWARD
     else if (t == 'B') 
     {
      digitalWrite(4, LOW);
      digitalWrite(5, HIGH);
      digitalWrite(6, HIGH);
      digitalWrite(7, LOW);
      data = "b";
      vw_send((uint8_t *)data, strlen(data));
      vw_wait_tx();
    }
    //LEFT
    else if (t == 'L') 
    {
      digitalWrite(4, LOW);
      digitalWrite(5, HIGH);
      digitalWrite(6, LOW);
      digitalWrite(7, HIGH);
      data = "l";
      vw_send((uint8_t *)data, strlen(data));
      vw_wait_tx();
    }
    //RIGHT
     else if (t == 'R') 
     {
      digitalWrite(4, HIGH);
      digitalWrite(5, LOW);
      digitalWrite(6, HIGH);
      digitalWrite(7, LOW);
      data = "r";
      vw_send((uint8_t *)data, strlen(data));
      vw_wait_tx();
    }
    //STOP 
    else if (t == 'S') 
    {
      digitalWrite(4, LOW);
      digitalWrite(5, LOW);
      digitalWrite(6, LOW);
      digitalWrite(7, LOW);
      data = "s";
      vw_send((uint8_t *)data, strlen(data));
      vw_wait_tx();
    }
  }
}
//LEFT
void move_left()
{
  digitalWrite(4, LOW);
  digitalWrite(5, HIGH);
  digitalWrite(6, LOW);
  digitalWrite(7, HIGH);
}
//RIGHT
void move_right() 
{
  digitalWrite(4, HIGH);
  digitalWrite(5, LOW);
  digitalWrite(6, HIGH);
  digitalWrite(7, LOW);
}
//FORWARD
void move_Forward() 
{
  digitalWrite(4, HIGH);
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  digitalWrite(7, HIGH);
}
//BACKWARD
void move_Backward() 
{
  digitalWrite(4, LOW);
  digitalWrite(5, HIGH);
  digitalWrite(6, HIGH);
  digitalWrite(7, LOW);
}
//STOP
void stop() 
{
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);
}
