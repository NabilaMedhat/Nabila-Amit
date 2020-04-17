/* 
 * File:   D_INT.h
 * Author: Nabila
 *
 * Created on April 17, 2020, 7:23 PM
 */

#ifndef D_INT_H
#define	D_INT_H

enum {
    int0, int1, int2
};

enum {
    LowLevel, AnyLogicChange, Falling, Rising
};

void INT_init(char intNum, int state);



#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

#endif	/* D_INT_H */

