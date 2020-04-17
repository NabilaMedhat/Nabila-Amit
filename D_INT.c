/*
 * File:   D_INT.c
 * Author: Nabila
 *
 * Created on April 17, 2020, 7:22 PM
 */


#include <xc.h>
#include "D_INT.h"

void INT_init(char intNum, int state) {
    if (state == 3) {
        switch (intNum) {
            case 0:
                MCUCR |= (1 << ISC01) | (1 << ISC00); //Rising Edge
                GICR |= (1 << INT0);
                break;
            case 1:
                MCUCR |= (1 << ISC11) | (1 << ISC10); //Rising Edge
                GICR |= (1 << INT1);
                break;
            case 2:
                MCUCSR |= (1 << ISC2); // Rising Edge
                GICR |= (1 << INT2);
                break;
        }
    }
    if (state == 2) {
        switch (intNum) {
            case 0:
                MCUCR |= (1 << ISC01);
                MCUCR &= ~(1 << ISC00);
                GICR |= (1 << INT0);
                break;
            case 1:
                MCUCR |= (1 << ISC11);
                MCUCR &= ~(1 << ISC10);
                GICR |= (1 << INT1);
                break;
            case 2:
                MCUCSR &= ~(1 << ISC2);
                GICR |= (1 << INT2);
                break;
        }
    }
    if (state == 1) {
        switch (intNum) {
            case 0:
                MCUCR &= ~(1 << ISC01);
                MCUCR |= (1 << ISC00);
                GICR |= (1 << INT0);
                break;
            case 1:
                MCUCR &= ~(1 << ISC11);
                MCUCR |= (1 << ISC10);
                GICR |= (1 << INT1);
                break;
            default:
#warning Not Available
                break;
        }
    }
    if (state == 0) {
        switch (intNum) {
            case 0:
                MCUCR &= ~(1 << ISC01) &~(1 << ISC00); //Rising Edge
                GICR |= (1 << INT0);
                break;
            case 1:
                MCUCR &= ~(1 << ISC11) &~(1 << ISC10); //Rising Edge
                GICR |= (1 << INT1);
                break;
            default:
#warning Not Available
                break;
        }
    }
}
