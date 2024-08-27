#include "led.h"
/*
trig -> G17
echo -> G16
Led Rojo -> G2
Led Verde -> G0
Led Blanco -> G4
*/


const int trig_pin = 17; // G17
const int echo_pin = 16; // G16


led led_rojo(2);   // G2
led led_verde(0);  // G0
led led_blanco(4); // G4

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
    Serial.print("Distancia: ");
    Serial.print(distance);
    Serial.println(" cm");
  }
  else{
    Serial.print("Distancia mayor a 300 cm\n");
  }

  if (distance < 30) {
    led_rojo.set_interval(100);
    led_rojo.blink();
    led_verde.off();
    led_blanco.off();
  } 
  else if (distance >= 30 && distance < 100) {
    led_verde.set_interval(100);
    led_verde.blink();
    led_rojo.off();
    led_blanco.off();
  } 
  else if (distance >= 100 && distance < 200) {
    led_blanco.set_interval(500);
    led_blanco.blink();
    led_rojo.off();
    led_verde.off();
  } 
  else {
    led_rojo.on();
    led_verde.on();
    led_blanco.on();
  }
}
