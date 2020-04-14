/*
 * File:   DIO.c
 * Author: Nabila
 *
 * Created on April 10, 2020, 5:50 PM
 */


#include <xc.h>
//#include "DIO.h"
#include "lcd.h"

void dirIO_DDRX(int pinNum, char port, int direction) {
    if (direction == 1) {
        switch (port) {

            case 0:
                DDRA |= (1 << pinNum);
                break;
            case 1:
                DDRB |= (1 << pinNum);
                break;
            case 2:
                DDRC |= (1 << pinNum);
                break;
            case 3:
                DDRD |= (1 << pinNum);
                break;
        }
    } else {
        switch (port) {

            case 0:
                DDRA &= ~(1 << pinNum);
                break;
            case 1:
                DDRB &= ~(1 << pinNum);
                break;
            case 2:
                DDRC &= ~(1 << pinNum);
                break;
            case 3:
                DDRD &= ~(1 << pinNum);
                break;
        }
    }

}

void DDRXas(char ddrx, int direction) {
    if (direction == 1) {
        switch (ddrx) {

            case 0:
                DDRA = 0xFF;
                break;
            case 1:
                DDRB = 0xFF;
                break;
            case 2:
                DDRC = 0xFF;
                break;
            case 3:
                DDRD = 0xFF;
                break;
        }
    } else if (direction == 0) {
        switch (ddrx) {

            case 0:
                DDRA = 0x00;
                break;
            case 1:
                DDRB = 0x00;
                break;
            case 2:
                DDRC = 0x00;
                break;
            case 3:
                DDRD = 0x00;
                break;
        }
    } else {
        //# warning "Wrong argument, enter input or output"
    }
}

void setPORT(char port) {

    switch (port) {

        case 0:
            PORTA = 0xFF;
            break;
        case 1:
            PORTB = 0xFF;
            break;
        case 2:
            PORTC = 0xFF;
            break;
        case 3:
            PORTD = 0xFF;
            break;
    }

}

void resetPORT(char port) {

    switch (port) {

        case 0:
            PORTA = 0x00;
            break;
        case 1:
            PORTB = 0x00;
            break;
        case 2:
            PORTC = 0x00;
            break;
        case 3:
            PORTD = 0x00;
            break;
    }

}

int isPressed(int pinNum, char pin) {

    switch (pin) {
        case 0:
            if (PINA & (1 << pinNum)) {
                return 1;
            } else {
                return 0;
            }
        case 1:
            if (PINB & (1 << pinNum)) {
                return 1;
            } else {
                return 0;
            }
        case 2:
            if (PINC & (1 << pinNum)) {
                return 1;
            } else {
                return 0;
            }
        case 3:
            if (PIND & (1 << pinNum)) {
                return 1;
            } else {
                return 0;
            }
    }
}

void setPIN(int pinNum, char port) {

    switch (port) {

        case 0:
            PORTA |= (1 << pinNum);
            break;
        case 1:
            PORTB |= (1 << pinNum);
            break;
        case 2:
            PORTC |= (1 << pinNum);
            break;
        case 3:
            PORTD |= (1 << pinNum);
            break;
    }

}

void resetPIN(int pinNum, char port) {

    switch (port) {

        case 0:
            PORTA &= ~(1 << pinNum);
            break;
        case 1:
            PORTB &= ~(1 << pinNum);
            break;
        case 2:
            PORTC &= ~(1 << pinNum);
            break;
        case 3:
            PORTD &= ~(1 << pinNum);
            break;
    }

}

void togglePIN(int pinNum, char port) {

    switch (port) {

        case 0:
            PORTA ^= (1 << pinNum);
            break;
        case 1:
            PORTB ^= (1 << pinNum);
            break;
        case 2:
            PORTC ^= (1 << pinNum);
            break;
        case 3:
            PORTD ^= (1 << pinNum);
            break;
    }

}

void showLCD(int flag, char* x, char* y) {
    if (flag) {
        LCD_Clear();
        LCD_String(x);
    } else {
        LCD_Clear();
        LCD_String(y);
    }
}
