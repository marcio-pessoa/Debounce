/* Debounce.h - Avoid Bounce Effect Library
 *
 * Author: Márcio Pessoa <marcio.pessoa@gmail.com>
 * Contributors: none
 *
 * Change log
 * 2023-01-17
 *   add: pullup resistor support.
 *
 * 2016-07-17
 *   add: experimental version.
 */

#ifndef Debounce_h
#define Debounce_h

#include "Arduino.h"

class Debounce {
 public:
  Debounce(byte pin, unsigned int period = 50, bool pullup = false);
  bool set(unsigned int period);
  bool check();

 private:
  byte _pin;
  unsigned int _period;
  bool _soft_state;
  bool _hard_state;
  bool _pullup;
};

#endif
