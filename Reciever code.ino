//Virtual wire library
#include <VirtualWire.h>
void setup() {
  // put your setup code here, to run once:
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  Serial.begin(9600);
  vw_set_rx_pin(2);
  vw_setup(2000);
  pinMode(2, INPUT);
  vw_rx_start();
}
//This code will run in a loop
void loop() {
  uint8_t buf[VW_MAX_MESSAGE_LEN];
  uint8_t buflen = VW_MAX_MESSAGE_LEN;
  if (vw_get_message(buf, &buflen)) {
    //Forward
    if (buf[0] == 'f') {
      digitalWrite(11, HIGH);
      digitalWrite(9, HIGH);
      digitalWrite(10, LOW);
      digitalWrite(8, LOW);
    } 
    //Backward
    else if (buf[0] == 'b') {

      digitalWrite(11, LOW);
      digitalWrite(9, LOW);
      digitalWrite(10, HIGH);
      digitalWrite(8, HIGH);
    }
    //Right
     else if (buf[0] == 'r') {

      digitalWrite(11, HIGH);
      digitalWrite(9, LOW);
      digitalWrite(10, LOW);
      digitalWrite(8, LOW);
    }
    //Left 
    else if (buf[0] == 'l') {

      digitalWrite(11, LOW);
      digitalWrite(9, LOW);
      digitalWrite(10, LOW);
      digitalWrite(8, HIGH);
    }
    //Stop 
    else if (buf[0] == 's') {
      digitalWrite(11, LOW);
      digitalWrite(9, LOW);
      digitalWrite(10, LOW);
      digitalWrite(8, LOW);
    }
  }
}
void forward() {

  digitalWrite(11, HIGH);
  digitalWrite(9, HIGH);
  digitalWrite(10, LOW);
  digitalWrite(8, LOW);
}
void backward() {
  digitalWrite(11, LOW);
  digitalWrite(9, LOW);
  digitalWrite(10, HIGH);
  digitalWrite(8, HIGH);
}
void right() {
  digitalWrite(11, HIGH);
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);
  digitalWrite(8, LOW);
}
void left() {
  digitalWrite(11, LOW);
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);
  digitalWrite(8, HIGH);
}