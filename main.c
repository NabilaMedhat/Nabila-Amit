/*
 * File:   main.c
 * Author: Nabila
 *
 * Created on April 4, 2020, 12:00 AM
 */



#include <avr/io.h>
#include <avr/interrupt.h>

#include "lcd.h"
#include "DIO.h"
#include "D_INT.h"

ISR(INT0_vect) {
    //Interrupt Service Routine
    flag2 ^= 1;
    togglePIN(LED2, portD);
    showLCD_XY(flag2, row0, row1, on2, off2, INT);
    _delay_ms(2000);
    togglePIN(LED2, portD);
    flag2 ^= 1;
    showLCD_XY(flag2, row0, row1, on2, off2, INT);
}

int main(void) {

    INT_init(int0, Falling);
    sei();

    LCD_Init();
    LCD_String(o1);

    // Data Direction Register
    dirIO_DDRX(Button0, portD, input);
    dirIO_DDRX(Button1, portD, input);
    //dirIO_DDRX(Button2, portD, input);
    dirIO_DDRX(LED0, portD, output);
    dirIO_DDRX(LED1, portD, output);
    dirIO_DDRX(LED2, portD, output);
    resetPORT(portA);
    resetPORT(portC);
    resetPIN(LED0, portD);
    resetPIN(LED1, portD);
    resetPIN(LED2, portD);

    while (1) {
        // Loop until power OFF
        if (isPressed(Button0, pinD)) {
            flag0 = 1;
            setPIN(LED0, portD);
            showLCD(flag0, on0, off0);
        } else {
            flag0 = 0;
            resetPIN(LED0, portD);
            //showLCD(flag0, on0, off0);
        }
        if (isPressed(Button1, pinD)) {
            togglePIN(LED1, portD);
            flag1 ^= 1;
            showLCD(flag1, on1, off1);
        }
        /**ADDED AS INTERRUPT SERVICE ROUTINE**/
        /*if (isPressed(Button2, pinD)) {
            flag2 ^= 1;
            togglePIN(LED2, portD);
            showLCD(flag2, on2, off2);
            _delay_ms(2000);
            togglePIN(LED2, portD);
            flag2 ^= 1;
            showLCD(flag2, on2, off2);
        }*/
        if (isPressed(Relay, pinD)) {
            LCD_Clear();
            LCD_String(runLED);
            for (i = 0; i < 10; i++) {
                runLEDS();
            }
        }
    }
}

//Added Functions to LCD

void showLCD(int flag, char* x, char* y) {
    if (flag) {
        LCD_Clear();
        LCD_String(x);
    } else {
        LCD_Clear();
        LCD_String(y);
    }
}

void showLCD_XY(int flag, char row0, char row1, char* x, char* y, char* str) {
    if (flag) {
        LCD_Clear();
        LCD_String_xy(row0, pos, x);
        LCD_String_xy(row1, pos, str);
    } else {
        LCD_Clear();
        LCD_String_xy(row0, pos, y);
        LCD_String_xy(row1, pos, str);
    }
}

//Shifting LEDS

void runLEDS() {
    setPIN(LED0, portD);
    resetPIN(LED1, portD);
    resetPIN(LED2, portD);
    _delay_ms(500);
    resetPIN(LED0, portD);
    setPIN(LED1, portD);
    resetPIN(LED2, portD);
    _delay_ms(500);
    resetPIN(LED0, portD);
    resetPIN(LED1, portD);
    setPIN(LED2, portD);
    _delay_ms(500);
}