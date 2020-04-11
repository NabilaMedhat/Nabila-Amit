/*
 * File:   main.c
 * Author: Nabila
 *
 * Created on April 4, 2020, 6:24 PM
 */

#include <avr/io.h>
#include "DIO.h"

enum PortA {
    adc0, adc1
};

enum PortB {
    seg7
};

enum PortC {
    scl, sda
};

enum PortD {
    Button0, Button1, Button2, Relay, Buzzer, LED0, LED1, LED2
};

enum portX {
    portA, portB, portC, portD
};

enum ddrX {
    ddrA, ddrB, ddrC, ddrD
};

enum pinX {
    pinA, pinB, pinC, pinD
};

enum Direction {
    input, output
};

int main(void) {

    // Data Direction Register
    dirIO_DDRX(Button0, portD, input);
    dirIO_DDRX(Button1, portD, input);
    dirIO_DDRX(Button2, portD, input);
    dirIO_DDRX(LED0, portD, output);
    dirIO_DDRX(LED1, portD, output);
    dirIO_DDRX(LED2, portD, output);
    resetPORT(portA);
    resetPORT(portC);


    while (1) {
        // Loop until power OFF
        if (isPressed(Button0, pinD)) {
            setPIN(LED0, portD);
        } else {
            resetPIN(LED0, portD);
        }
        if (isPressed(Button1, pinD)) {
            setPIN(LED1, portD);
        } else {
            resetPIN(LED1, portD);
        }
        if (isPressed(Button2, pinD)) {
            setPIN(LED2, portD);
        } else {
            resetPIN(LED2, portD);
        }
    }
}

