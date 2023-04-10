/* Debounce.cpp - Avoid Bounce Effect Library
 *
 */

#include "Debounce.h"
#include "Arduino.h"

/// @brief Constructor
/// @param pin
/// @param period
/// @param pullup
Debounce::Debounce(byte pin, unsigned int period, bool pullup) {
  attach(pin, period, pullup);
}

void Debounce::attach(byte pin, unsigned int period, bool pullup) {
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

/// @brief Check if switch is pressed
/// @return true when pressed
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

/// @brief Set debounce period
/// @param period
/// @return
bool Debounce::set(unsigned int period) {
  _period = period;
  return false;
}
