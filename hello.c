#ifndef F_CPU
#define F_CPU 16000000UL
#endif
#include <avr/io.h>
#include <util/delay.h>


int button_is_pressed(int button_number) {
  return !(PIND & (1 << button_number));
}

int pressed_buttons_count() {
  int count = 0;
  for (int i = 0; i < 8; i++) {
    count += button_is_pressed(i);
  }
  return count;
}

int get_pressed_button() {
  int value = 0;
  for (int i = 0; i < 8; i++) {
    if (button_is_pressed(i)) 
    { 
      value = i; 
      break;
    } 
  }
  return value;
}

void display(int value) {
   int i = 0;
   while (value) {
      if (value & 1) {
        PORTB |= (1 << i);
      }
      value /= 2;
      i++;  
   }
}

int main() {
  DDRD = 0x00;
  PORTD = 0xFF;
  DDRB = 0xFF;
  PORTB = 0x00;
  
  while (1) {
    while (pressed_buttons_count() > 1) {}
    if (pressed_buttons_count() == 1) {
      PORTB = 0x00;
      int value = get_pressed_button();
      display(value);   
      while (button_is_pressed(value)) {}
    }
    _delay_ms(500);
  }

}
