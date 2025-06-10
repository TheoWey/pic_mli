/*
 * File:   main.h
 * Author: weyth
 *
 * Created on 10 juin 2025, 11:31
 */

#ifndef MAIN_H
#define MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

#include <xc.h>
#include <stdio.h>
#include <stdlib.h>

#define _XTAL_FREQ 20e6 // 20MHz

// CONFIG
#pragma config FOSC = HS   // Oscillator Selection bits (HS oscillator)
#pragma config WDTE = OFF  // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = OFF // Brown-out Reset Enable bit (BOR disabled)
#pragma config LVP =                                                           \
    OFF // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit
        // (RB3 is digital I/O, HV on MCLR must be used for programming)
#pragma config CPD = OFF // Data EEPROM Memory Code Protection bit (Data EEPROM
                         // code protection off)
#pragma config WRT =                                                           \
    OFF // Flash Program Memory Write Enable bits (Write protection off; all
        // program memory may be written to by EECON control)
#pragma config CP =                                                            \
    OFF // Flash Program Memory Code Protection bit (Code protection off)

// Function prototypes

/// @brief Initialize the microcontroller peripherals and I/O pins.
/// @param None
void init(void);

#ifdef __cplusplus
}
#endif

#endif /* MAIN_H */
