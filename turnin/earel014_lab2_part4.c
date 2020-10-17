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
	DDRB = 0x00; PORTB = 0xFF;
	DDRC = 0x00; PORTC = 0xFF;
	DDRD = 0xFF; PORTD = 0x00;
	
	/* Insert your solution below */
	unsigned char difference = 0x00;
	unsigned char weight = 0x00;
	unsigned char tmpA = 0x00;
	unsigned char tmpB = 0x00;
	unsigned char tmpC = 0x00;
	unsigned char tmpD = 0x00;
	while (1) {
		tmpA = PINA;
		tmpB = PINB;
		tmpC = PINC;
		weight = (tmpA + tmpB + tmpC);
		difference = (tmpA - tmpC);

		if(weight > 0x8C){
			tmpD = 0x01;
			if(difference > 80) { //if weight > 140kg & |A-C| > 80kg
				tmpD = 0x03;
				tmpD = (tmpD | weight);
			}
			else { //if weight > 140kg BUT |A-C| <= 80kg
				tmpD = (tmpD | weight) & 0xFD;
			}
		}
		else { //if weight <= 140kg
			if(difference > 80) { //if weight <= 140kg & |A-C| > 80kg
				tmpD = 0x02;
				tmpD = (tmpD | weight) & 0xFE;
			}
			else { //if weight <= 140kg BUT |A-C| <= 80kg
				tmpD = (tmpD | weight) & 0xFC;
			}
		}

		PORTD = tmpD;
	}
	return 0;
}

