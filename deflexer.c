#ifndef F_CPU
#define F_CPU 16000000UL
#endif
#include <avr/io.h>
#include <util/delay.h>


int button_is_pressed(int button_number) {
  return !(PINB & (1 << button_number));
}

int pressed_buttons_count() {
  int count = 0;
  for (int i = 0; i < 3; i++) {
    count += button_is_pressed(i);
  }
  return count;
}

int get_pressed_buttons() {
  int value = 0;
  for (int i = 0; i < 3; i++) {
    if (button_is_pressed(i)) 
    { 
      value |= (1 << i); 
    } 
  }
  return value;
}

void display(int value_b) {
   int value_d = 0;
   for (int i = 0; i < 3; i++) {
      value_d += (value_b & (1 << i)) * (1 << i);
   }
   PORTD |= (1 << value_d);
}

int main() {
  DDRD = 0xFF;
  PORTD = 0x00;
  DDRC = 0x00;
  PORTC = 0b00000111;
  while (1) {
    PORTD = (1 << ((~PINC) & 7));
  }

}
