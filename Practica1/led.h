#include <Arduino.h>

class led {
  private:
    int pin;
    unsigned long previous_millis;
    int interval;
    bool is_on;

  public:
    led(int pin) {
      this->pin = pin;
      pinMode(pin, OUTPUT);
      previous_millis = 0;
      interval = 1000;
      is_on = false;
    }

    void set_interval(int interval) {
      this->interval = interval;
    }

    void update() {
      unsigned long current_millis = millis();

      if (current_millis - previous_millis >= interval) {
        previous_millis = current_millis;

        if (is_on) {
          digitalWrite(pin, LOW);
        } else {
          digitalWrite(pin, HIGH);
        }

        is_on = !is_on;
      }
    }

    void on() {
      digitalWrite(pin, HIGH);
      is_on = true;
    }

    void off() {
      digitalWrite(pin, LOW);
      is_on = false;
    }

    void blink() {
      update();
    }
};