#include "Button_Simple.h"

// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //

Button_Simple::Button_Simple(uint8_t aPin, modes::type_t aMode) : _pin(aPin) {
  pinMode(_pin, INPUT);

  switch (aMode) {
    case modes::high:    _mode = HIGH; break;
    case modes::low:     _mode = LOW;  break;
    case modes::pull_up: _mode = LOW;  digitalWrite(pin(), INPUT_PULLUP); break;
  }

  _state = 0;
  bitWrite(_state, bits::current,   false);
  bitWrite(_state, bits::previous,  false);
  bitWrite(_state, bits::changed,   false);
  bitWrite(_state, bits::sample,    (_mode == LOW));
  bitWrite(_state, bits::clicksent, true);

  _debounce_delay_time = defaults::debounce_time;
  _debounce_start_time = _pressed_start_time = _last_release_time = _multi_click_threshold_time = 0;

  _hold_threshold_time     = 0;
  _conseq_click_count      = 0;

  _hold_event_triggered = true;
}

// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //

Button_Simple& Button_Simple::scan(void) {
  unsigned long __millis = millis();
  int __sample = digitalRead(pin());

  if (__sample != bitRead(_state, bits::sample)) _debounce_start_time = __millis;

  bitWrite(_state, bits::sample, __sample);
  bitWrite(_state, bits::changed, false);

  // If our samples have outlasted our debounce delay (i.e. stabilized),
  // then we can switch state.
  if ((__millis - _debounce_start_time) > _debounce_delay_time) {
    bool __p_state = bitRead(_state, bits::current), __c_state = __sample != _mode;
    bitWrite(_state, bits::previous, __p_state);
    bitWrite(_state, bits::current, __c_state);

    if (__c_state != __p_state) { // State changed
      bitWrite(_state, bits::changed, true);
      _hold_event_triggered = false;

      if (__c_state) { // Pressed
        // If we have another click within the multiClick threshold,
        // increase our click count, otherwise reset.
        if (__millis - _last_release_time < _multi_click_threshold_time) _conseq_click_count++;
        else _conseq_click_count = 1;
        _pressed_start_time = millis();
      }
      else {    // Released
        _last_release_time = __millis;
        bitWrite(_state, bits::clicksent, false);
      }
    }
  }

  return *this;
}

// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //

unsigned Button_Simple::clicked(void) {
  if (_new_click(millis())) { bitWrite(_state, bits::clicksent, true); return _conseq_click_count; }
  return 0;
}

// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //

bool Button_Simple::held(unsigned long aTime) {
  unsigned long __threshold = aTime ? aTime : (_hold_threshold_time ? _hold_threshold_time : defaults::hold_threshold);

  if (is_pressed() && !_hold_event_triggered) {
    if (millis() - _pressed_start_time > __threshold) {
      _hold_event_triggered = true;
      return true;
    }
  }
  return false;
}

// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //
