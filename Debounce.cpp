/* Debounce.cpp - Avoid Bounce Effect Library
 *
 */

#include "Arduino.h"
#include "Debounce.h"

/* Debounce
 *
 * Description
 *   Blink LED without delay function.
 *
 *   RealTime (int pin, int millis_period, boolean state)
 *
 * Parameters
 *   pin: Arduino LED pin
 *   millis_period: Time period to define blink delay (milliseconds)
 *   state: Initial LED state
 *
 * Returns
 *   void
 */
Debounce::Debounce(byte pin, unsigned int period, bool pullup) {
  _pin = pin;
  _period = period;
  _pullup = pullup;
  _soft_state = LOW;
  _hard_state = LOW;

  if (_pullup) {
    pinMode(_pin, INPUT_PULLUP);
  } else {
    pinMode(pin, INPUT);
  }
}

/* status
 *
 * Description
 *   Return LED status.
 *
 *   a_led.status(int millis_period)
 *
 * Parameters
 *   none
 *
 * Returns
 *   bool: false if LED is not blinking, true if LED is blinking
 */
bool Debounce::check() {
  _soft_state = digitalRead(_pin);
  if (_hard_state != _soft_state) {
    delay(_period);
    _soft_state = digitalRead(_pin);
    if (_hard_state != _soft_state) {
      _hard_state = _soft_state;
    }
  }

  if (_pullup) {
    return !_hard_state;
  } else {
    return _hard_state;
  }
}

/* set
 *
 * Description
 *   Return LED status.
 *
 *   a_led.status(int millis_period)
 *
 * Parameters
 *   none
 *
 * Returns
 *   bool: false if LED is not blinking, true if LED is blinking
 */
bool Debounce::set(unsigned int period) {
  _period = period;
  return false;
}

