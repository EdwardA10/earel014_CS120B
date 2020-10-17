/*	Author: Edward Arellano
 *  Partner(s) Name: None
 *	Lab Section: 023
 *	Assignment: Lab #3  Exercise #2
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
	unsigned char button = 0x00;
	unsigned char tmpC = 0x00;
	while (1) {
		button = PINA & 0x00;
		if(button == 0x00) {
			tmpC = 0x40; //if fuel tank is completely empty, display PC6 only.
		}
		button = PINA & 0x01;
		if(button == 0x01) {
			tmpC = 0x50;
		}

		button = PINA & 0x02;
		if(button == 0x02) {
			tmpC = 0x50;
		}

		button = PINA & 0x03;
		if(button == 0x03) {
			tmpC = 0x70;
		}

		button = PINA & 0x04;
		if(button == 0x04) {
			tmpC = 0x70;
		}

		button = PINA & 0x05;
		if(button == 0x05) {
			tmpC = 0x38;
		}

		button = PINA & 0x06;
                if(button == 0x06) {
                        tmpC = 0x38;
                }

		button = PINA & 0x07;
                if(button == 0x07) {
                        tmpC = 0x3C;
                }

		button = PINA & 0x08;
                if(button == 0x08) {
                        tmpC = 0x3C;
                }

		button = PINA & 0x09;
                if(button == 0x09) {
                        tmpC = 0x3C;
                }

		button = PINA & 0x0A;
                if(button == 0x0A) {
                        tmpC = 0x3E;
                }

		button = PINA & 0x0B;
                if(button == 0x0B) {
                        tmpC = 0x3E;
                }

		button = PINA & 0x0C;
                if(button == 0x0C) {
                        tmpC = 0x3E;
                }

		button = PINA & 0x0D;
                if(button == 0x0D) {
                        tmpC = 0x3F;
                }

		button = PINA & 0x0E;
                if(button == 0x0E) {
                        tmpC = 0x3F;
                }

		button = PINA & 0x0F;
                if(button == 0x0F) {
                        tmpC = 0x3F;
                }

		PORTC = tmpC;
	}
	return 0;
}

