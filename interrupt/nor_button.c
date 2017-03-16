/*
Turn on LED while button is pressed using if-else condition


Button connected on PB2
LED connected on PA2


*/

#include<avr/io.h>
#define F_CPU 20000000
#include<util/delay.h>
#include<avr/interrupt.h>



main(){

  DDRA=0x0f;    // set PA0 to PA3 as output
  DDRB=0x0;     // set PORTB as input
  PORTB|=(1<<2); // pullup PB2


  while (1) {

    if (!(PINB&(1<<2))) {       //if PB2 is low
      PORTA|=(1<<2);            // set PA2 High
      }
    else{                       // else
      PORTA&=(!(1<<2));         // set PA2 Low
    }
  }


}
