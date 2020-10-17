/*	Author: Edward Arellano
 *  Partner(s) Name: None
 *	Lab Section: 023
 *	Assignment: Lab #3  Exercise #1
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
	DDRC = 0xFF; PORTC = 0x00;
	
	/* Insert your solution below */
	unsigned char count = 0x00;
	unsigned char button = 0x00;
	
	while (1) {
		count = 0x00;
		button = PINA & 0x01;

		if(button == 0x01) {
			count = count + 0x01;
		}
		else { }
		
		button = PINA & 0x02;
		if(button == 0x02) {
			count = count + 0x01;
		}
		else { }

		button = PINA & 0x04;
		if(button == 0x04) {
                        count = count + 0x01;
                }
		else { }

		button = PINA & 0x08;
		if(button == 0x08) {
                        count = count + 0x01;
                }
		else {}
		
		button = PINA & 0x10;
		if(button == 0x10) {
                        count = count + 0x01;
                }
                else {}

		button = PINA & 0x20;
		if(button == 0x20) {
                        count = count + 0x01;
                }
                else {}
		
		button = PINA & 0x40;
		if(button == 0x40) {
                        count = count + 0x01;
                }
                else {}

		button = PINA & 0x80;
		if(button == 0x80) {
                        count = count + 0x01;
                }
                else {}

		button = PINB & 0x01;
		if(button == 0x01) {
                        count = count + 0x01;
                }
		else {}

		button = PINB & 0x02;
		if(button == 0x02) {
                        count = count + 0x01;
                }
		else {}

		button = PINB & 0x04;
		if(button == 0x04) {
                        count = count + 0x01;
                }
		else {}

		button = PINB & 0x08;
		if(button == 0x08) {
                        count = count + 0x01;
                }
		else {}

		button = PINB & 0x10;
		if(button == 0x10) {
                        count = count + 0x01;
                }
		else {}

		button = PINB & 0x20;
		if(button == 0x20) {
                        count = count + 0x01;
                }
		else {}

		button = PINB & 0x40;
		if(button == 0x40) {
                        count = count + 0x01;
                }
		else {}

		button = PINB & 0x80;
		if(button == 0x80) {
                        count = count + 0x01;
                }
		else {}

		PORTC = count;
	}
	return 0;
}

