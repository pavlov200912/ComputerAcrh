#ifndef F_CPU
#define F_CPU 16000000UL
#endif
#include <avr/io.h>
#include <util/delay.h>


int main() {
  DDRB = 0x00;
  PORTB = 0x01; 
  DDRC = 0b00011111;   
  int direction = 0; 
  PORTC = 1 << 4;

  while(1) {
    if (PINB & 0x01) { 
      // skip..
    } else {
      direction ^= 1;
      PORTC = 0;
      while (!(PINB & 0x01)) {}
      PORTC = (0x01) | (1 << 4);
      continue;
    }
    if (direction) {
       if (PORTC & 1 << 4) {
           PORTC = 0x01;
       } else {
           PORTC = (PORTC << 1); 
       }
    } else {
      if (PORTC & (0x01)) {
         PORTC = 1 << 4;
      } else {
         PORTC = (PORTC >> 1);
      }
    }
    _delay_ms(100);
  }

}
