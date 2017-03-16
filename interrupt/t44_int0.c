/*
Turn on LED while button is pressed using interrupt

Button connected on PB2
LED connected on PA2

*/


#include<avr/io.h>
#define F_CPU 20000000
#include<util/delay.h>
#include<avr/interrupt.h>


ISR(INT0_vect){             //interept service routine while interept is made by int0 pin
  if (!(PINB&(1<<2))) {     // if PB2 is low
    PORTA|=(1<<2);          //   set PA2 High
    }
  else{                     // else
    PORTA&=(!(1<<2));        // set PA2 Low
  }


}


main(){
  DDRA=0x0f;     // set PA0 to PA3 as output
  DDRB=0x0;     // set PORTB as input
  PORTB|=(1<<2);  // pullup PB2

  MCUCR = 1<<ISC00 ;    //  Any logical change on INT0 generates an interrupt request.
  GIMSK|= (1<<INT0);    // external pin interrupt is enabled om INT0 pin
  sei();                // set global interrupt flag

  while (1) {
    // simply nothng
  }


}
