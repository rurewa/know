#ifndef _ROBODEM_BUTTON_SIMPLE_H_
#define _ROBODEM_BUTTON_SIMPLE_H_

// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //

#include <stdint.h>
#include <Arduino.h>

// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //

class Button_Simple {
private:
  struct bits { enum { current, previous, changed, sample, clicksent }; };

public:
  typedef void (*event_f)(Button_Simple&);

  struct defaults {
    enum {
      debounce_time  = 30,
      hold_threshold = 500
    };
  };
  
  struct modes {
    enum type_t {
      high,     // Button is considered to be pressed when the pin is HIGH
      low,      // Button is considered to be pressed when the pin is LOW
      pull_up   // Pull-up the pin, button is considered to be pressed when the pin is LOW
    };
  };

private:
  const uint8_t _pin;
  uint8_t _mode, _state;

  unsigned long _pressed_start_time, _debounce_start_time, _last_release_time;
  unsigned long _debounce_delay_time, _hold_threshold_time, _multi_click_threshold_time;
  unsigned long _hold_event_repeat_delay, _hold_event_previous_time;

  unsigned _conseq_click_count;
  bool _hold_event_triggered;

  inline bool _new_click(unsigned long aMillis) {
    return bitRead(_state, bits::clicksent) == false && bitRead(_state, bits::current) == false &&
       (_multi_click_threshold_time == 0 || aMillis - _last_release_time > _multi_click_threshold_time);
  }

public:
  Button_Simple(uint8_t aPin, modes::type_t aMode = modes::high);

  Button_Simple& scan();

  bool is_pressed() const { return bitRead(_state, bits::current); }
  bool state_changed() const { return bitRead(_state, bits::changed); }
  inline bool unique_press() const { return (is_pressed() && state_changed()); }
  inline bool unique_release() const { return (!is_pressed() && state_changed()); }

  unsigned int clicked();
  bool held(unsigned long aTime = 0);
  inline bool held_for(unsigned long time) const { return is_pressed() && millis() - _pressed_start_time > time; }

  // Properties
  inline void debounce_delay_time(unsigned int aDelay) { _debounce_delay_time = aDelay; }
  inline unsigned long debounce_delay_time() const { return _debounce_delay_time; }

  // Minimal Time to consider the button being held for
  inline void hold_threshold(unsigned long aHoldTime) { _hold_threshold_time = aHoldTime; }
  inline unsigned long hold_threshold() const { return _hold_threshold_time; }

  inline void hold_repeat_delay(unsigned long aDelay) { _hold_event_repeat_delay = aDelay; }
  inline unsigned long hold_repeat_delay() const { return _hold_event_repeat_delay; }

  // Maximum time between clicks that qualifies as a multi-click
  inline void multi_click_threshold(uint8_t aTime) { _multi_click_threshold_time = aTime; }
  inline uint8_t multi_click_threshold() const { return _multi_click_threshold_time; }

  inline unsigned long hold_time() const { return is_pressed() ? millis() - _pressed_start_time : 0; }

  // Consecutive click count that occurred with-in the 'multi_click_threshold_time()' rule
  inline unsigned conseq_click_count() const { return _conseq_click_count; }

  inline uint8_t pin() const { return _pin; }

  inline bool operator==(Button_Simple &aOther) const { return this == &aOther; }

private: // Unsupported functionality
  Button_Simple(const Button_Simple&);
  Button_Simple& operator=(const Button_Simple&);
};

// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //

#endif // _ROBODEM_BUTTON_SIMPLE_H_
