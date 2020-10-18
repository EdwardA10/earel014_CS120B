/*	Author: Edward Arellano
 *  Partner(s) Name: None
 *	Lab Section: 023
 *	Assignment: Lab #2  Exercise #2
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

int main(void) {
	/* Insert DDR and PORT initializations */
	DDRA = 0x00; PORTA = 0xFF;
	DDRC = 0xFF; PORTC = 0x00;
	
	/* Insert your solution below */
	unsigned char cntavail = 0x00;
	unsigned char tmpA = 0x00;
	while (1) {
		tmpA = PINA;

		if(tmpA == 0x00) {
			cntavail = 0x04;
		}
		else if((tmpA == 0x01) || (tmpA == 0x02) || (tmpA == 0x04) || (tmpA == 0x08)) {
			cntavail = 0x03;
		}
		else if((tmpA == 0x03) || (tmpA == 0x05) || (tmpA == 0x06) || (tmpA == 0x09) || (tmpA == 0x0A) || (tmpA == 0x0C)) {
			cntavail = 0x02;
		}
		else if((tmpA == 0x07) || (tmpA == 0x0B) || (tmpA == 0x0D) || (tmpA == 0x0E)) {
			cntavail = 0x01;
		}
		else if(tmpA == 0x0F) {
			cntavail = 0x00;
		}
		else if(tmpA == 0x80){
			cntavail = 0x04;
		}
		else {
			cntavail = 0x00; //if pins 7-4 are not 0, then set cntavail to 0.
		}

		PORTC = cntavail;
	}
	return 0;
}
