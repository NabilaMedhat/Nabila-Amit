/* Microchip Technology Inc. and its subsidiaries.  You may use this software 
 * and any derivatives exclusively with Microchip products. 
 * 
 * THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS".  NO WARRANTIES, WHETHER 
 * EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED 
 * WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A 
 * PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION 
 * WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION. 
 *
 * IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
 * INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
 * WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS 
 * BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE.  TO THE 
 * FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS 
 * IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF 
 * ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
 *
 * MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE 
 * TERMS. 
 */

/* 
 * File:   
 * Author: 
 * Comments:
 * Revision history: 
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef XC_HEADER_TEMPLATE_H
#define	XC_HEADER_TEMPLATE_H

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

enum LCDRows {
    row0, row1
};
char pos = 0;
char o1[] = "Push your Button";
char runLED[] = "Shifting LEDS";
char on0[] = "LED0 flashed";
char off0[] = "LED0 is OFF";
char on1[] = "LED1 is ON";
char off1[] = "LED1 is OFF";
char on2[] = "LED2 is ON";
char off2[] = "LED2 is OFF";
char INT[] = "***INTERRUPTS***";
char flag0 = 0;
char flag1 = 0;
char flag2 = 0;
int i = 0;

void dirIO_DDRX(int pinNum, char port, int direction);

void DDRXas(char ddrx, int direction);

void setPORT(char port);
void resetPORT(char port);

int isPressed(int pinNum, char pin);

void setPIN(int pinNum, char port);
void resetPIN(int pinNum, char port);
void togglePIN(int pinNum, char port);


void showLCD(int flag, char* x, char* y);
void showLCD_XY(int flag, char row0, char row1, char* x, char* y, char* str);
void runLEDS();
#include <xc.h> // include processor files - each processor file is guarded.  

// TODO Insert appropriate #include <>

// TODO Insert C++ class definitions if appropriate

// TODO Insert declarations

// Comment a function and leverage automatic documentation with slash star star
/**
    <p><b>Function prototype:</b></p>
  
    <p><b>Summary:</b></p>

    <p><b>Description:</b></p>

    <p><b>Precondition:</b></p>

    <p><b>Parameters:</b></p>

    <p><b>Returns:</b></p>

    <p><b>Example:</b></p>
    <code>
 
    </code>

    <p><b>Remarks:</b></p>
 */
// TODO Insert declarations or function prototypes (right here) to leverage 
// live documentation

#ifdef	__cplusplus
extern "C" {
#endif /* __cplusplus */

    // TODO If C++ is being used, regular C code needs function names to have C 
    // linkage so the functions can be used by the c code. 

#ifdef	__cplusplus
}
#endif /* __cplusplus */

#endif	/* XC_HEADER_TEMPLATE_H */

