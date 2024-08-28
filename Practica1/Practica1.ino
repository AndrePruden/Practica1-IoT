#include "led.h"
/*
trig -> G17
echo -> G16
Red LED -> G2
Green LED -> G0
White LED -> G4
*/

const int trig_pin = 17; // G17
const int echo_pin = 16; // G16

led red_led(2);    // G2
led green_led(0);  // G0
led white_led(4);  // G4

void setup() {
  pinMode(trig_pin, OUTPUT);
  pinMode(echo_pin, INPUT);

  Serial.begin(9600);
}

void loop() {
  digitalWrite(trig_pin, LOW);
  delayMicroseconds(2);
  digitalWrite(trig_pin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig_pin, LOW);

  long duration = pulseIn(echo_pin, HIGH);

  int distance = duration * 0.034 / 2;

  if(distance < 300){
    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.println(" cm");
  }
  else{
    Serial.print("Distance greater than 300 cm\n");
  }

  if (distance < 30) {
    red_led.set_interval(100);
    red_led.blink();
    green_led.off();
    white_led.off();
  } 
  else if (distance >= 30 && distance < 100) {
    green_led.set_interval(100);
    green_led.blink();
    red_led.off();
    white_led.off();
  } 
  else if (distance >= 100 && distance < 150) {
    white_led.set_interval(500);
    white_led.blink();
    red_led.off();
    green_led.off();
  } 
  else {
    red_led.on();
    green_led.on();
    white_led.on();
  }
}
